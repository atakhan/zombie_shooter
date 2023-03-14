
#include "Collision.h"
#include "Scene.h"

Manifold::Manifold(RigidBody* _A, RigidBody* _B) : numContacts(0) {
    A = _A; B = _B;  
    this->u = sqrtf(A->friction * B->friction); // Mixed Friction
    this->e = max(A->restitution, B->restitution); // Max Restitution
    Dispatcher[A->shape->type][B->shape->type](*this, A->shape, B->shape);
}

void Manifold::Update(Contact* newContacts, const int& numNewContacts) {
    const real k_tolerance = k__distance;
    Contact mergedContacts[2];
    for (int i = 0; i < numNewContacts; i++) {
        for(int j = 0; j < numContacts; j++) {
            if((newContacts[i].position - contacts[j].position).SquareMagnitude() < k_tolerance) {
                mergedContacts[i] = newContacts[i];
                mergedContacts[i].Pn = contacts[j].Pn;
                mergedContacts[i].Pt = contacts[j].Pt;
                break;
            } else if(j + 1 == numContacts) {
                mergedContacts[i] = newContacts[i];
                mergedContacts[i].warmPoint = mergedContacts[i].position;
            }
        }			
    }
    numContacts = numNewContacts;
    
    for(int i = 0; i < numContacts; i++)
        contacts[i] = mergedContacts[i];
}

void Manifold::WarmStarting(void) {
    Vec2 tangent = Cross(normal, -1.0f);
    for(int i = 0; i < numContacts; i++) {
        Contact* c = contacts + i;
        Vec2 ra = A->position - c->position;
        Vec2 rb = B->position - c->position;
        Vec2 P = normal * c->Pn + tangent * c->Pt;
        A->velocity -= P * A->invm;
        B->velocity += P * B->invm;
        A->angularVelocity -= Cross(P, ra) * A->invI;
        B->angularVelocity += Cross(P, rb) * B->invI;
    }
}

void Manifold::PreStep(const real& dt) {
    const real k_slop = 0.004f;
    const real k_biasFactor = 0.1f;
    real massLinear = A->invm + B->invm;
    for(int i = 0; i < numContacts; i++) {
        Contact* c = contacts + i;
        Vec2 ra = A->position - c->position;
        Vec2 rb = B->position - c->position;
        c->massNormal = massLinear + pow2(Cross(normal, ra)) * A->invI + pow2(Cross(normal, rb)) * B->invI;
        c->massNormal = 1.0f / c->massNormal;
        c->massTangent = massLinear + pow2(Dot(normal, ra)) * A->invI + pow2(Dot(normal, rb)) * B->invI; // Cross(tangent, r)^2 = Dot(normal, r)^2 : in 2D
        c->massTangent = 1.0f / c->massTangent;
        Vec2 dv = B->velocity + Cross(rb, B->angularVelocity) - A->velocity - Cross(ra, A->angularVelocity);
        real vn = dv * normal;
        c->restitution = vn < -1.0f ? vn * e : 0.0f;
        // Baumgarte Stabilization
        if(Scene::CorrectionType == BAUMGARTE) {
            c->bias = min(0.0f, c->penetration + k_slop) * k_biasFactor / dt;
        }
    }
}

void Manifold::ApplyImpulse(void) {
    Vec2 tangent = Cross(normal, -1.0f); // Vector Tangent
    for(int i = 0; i < numContacts; i++) {
        Contact* c = contacts + i; 
        Vec2 ra = A->position - c->position;
        Vec2 rb = B->position - c->position;
        Vec2 dv = B->velocity + Cross(rb, B->angularVelocity) - A->velocity - Cross(ra, A->angularVelocity); // (v2 - v1) Δv Relative Velocity
        real vt = dv * tangent; // Tangent Relative Velocity
        real dPt = -vt * c->massTangent; // Ax + b = 0 --> x = -b * A⁻¹; 
        real MaxPt = u * c->Pn; // MaxPt = uλn
        real Pt0 = c->Pt;
        c->Pt = clamp(-MaxPt, MaxPt, Pt0 + dPt); // |λt| <= uλn  "OR"  -uλn <= λt <= uλn
        dPt = c->Pt - Pt0;
        Vec2 P = tangent * dPt; // Jt * λ
        A->velocity -= P * A->invm;
        B->velocity += P * B->invm;
        A->angularVelocity -= Cross(P, ra) * A->invI;
        B->angularVelocity += Cross(P, rb) * B->invI;
    }
  
    for(int i = 0; i < numContacts; i++) {
        Contact* c = contacts + i; 
        Vec2 ra = A->position - c->position;
        Vec2 rb = B->position - c->position;
        Vec2 dv = B->velocity + Cross(rb, B->angularVelocity) - A->velocity - Cross(ra, A->angularVelocity); // (v2 - v1) Δv Relative Velocity
        real vn = dv * normal; // Normal Relative Velocity
        real dPn = -(vn + c->restitution + c->bias) * c->massNormal; // Ax + b = 0 --> x = -b * A⁻¹; 
        real Pn0 = c->Pn;
        c->Pn = max(c->Pn + dPn, 0.0f); // Accumulated Impulse & (v2 - v1) * J / M⁻¹ >= 0
        dPn = c->Pn - Pn0;
        Vec2 P = normal * dPn; // Jt * λ
        A->velocity -= P * A->invm; 
        B->velocity += P * B->invm;
        A->angularVelocity -= Cross(P, ra) * A->invI;
        B->angularVelocity += Cross(P, rb) * B->invI;
    }
}



real Manifold::RecalculatePenetration(Vec2& normal, Vec2& position, const int& i){
    Shape* sA = this->A->shape;
    Shape* sB = this->B->shape; 
    PostPosition p = postPosition;
    Vec2 distance = B->position - A->position;
    
    // Circle to circle
    if(sA->type + sB->type == 0) {
        real magnitude = distance.Magnitude();
        normal = this->normal;
        position = A->position + normal * ((sA->radius - sB->radius + magnitude) * 0.5f);
        
        return magnitude - sA->radius - sB->radius;
    
    // CircleToOBB || OBBToCircle
    } else if(sA->type + sB->type == 1) {
        Mat2 rotB(B->orientation - p.oldOrientationB);
        normal = rotB * this->normal;
        Vec2 point2 = rotB * p.oldPointB[i];
        real magnitude = normal * (distance + point2);  
        position = A->position + normal * magnitude;
        
        return magnitude - sA->radius;
    
    // OBBToOBB
    } else if(sA->type + sB->type == 2) {
        Mat2 rotA(A->orientation - p.oldOrientationA);
        Mat2 rotB(B->orientation - p.oldOrientationB);
        normal = rotB * this->normal;
        Vec2 point1 = rotA * p.oldPointA[i];
        Vec2 point2 = rotB * p.oldPointB[i];
        real penetration = normal * (distance + point2 - point1);
        position = A->position + point1 + normal * penetration;	
        
        return penetration;
    }
    return 0;
}

void Manifold::ApplyCorrection(void) {
    const real k_slop = 0.002f;
    const real k_biasFactor = 0.2f;
    real massLinear = A->invm + B->invm;
    Vec2 XA = A->position;
    Vec2 XB = B->position;
    real θA = A->orientation;
    real θB = B->orientation;
    Vec2 contactPoint, normal;
    for(int i = 0; i < numContacts; i++) {
        real penetration = RecalculatePenetration(normal, contactPoint, i);
        Vec2 ra = A->position - contactPoint;
        Vec2 rb = B->position - contactPoint;
        real massNormal = massLinear + pow2(Cross(normal, ra)) * A->invI + pow2(Cross(normal, rb)) * B->invI;
        Vec2 C = normal * -min(penetration + k_slop, 0) * (k_biasFactor / massNormal);
        XA -= C * A->invm;
        XB += C * B->invm;
        θA -= Cross(C, ra) * A->invI;
        θB += Cross(C, rb) * B->invI;
    }
    A->position = XA;
    B->position = XB;
    A->orientation = θA;
    B->orientation = θB;
}