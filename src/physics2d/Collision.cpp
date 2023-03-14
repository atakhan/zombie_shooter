#include "Collision.h"
#include <iostream>

void CircleToCircle(Manifold& m, Shape* c1, Shape* c2) {
    Vec2 distance = c2->body->position - c1->body->position;
    real radius = c2->radius + c1->radius;
    real magnitude = distance.SquareMagnitude();
    
    if(magnitude > radius * radius) return;

    magnitude = sqrtf(magnitude);
    m.numContacts = 1;
    m.contacts[0].penetration = magnitude - radius;
    m.normal = magnitude ? distance * (real(1) / magnitude) : Vec2(0, 1);
    m.contacts[0].position = c1->body->position + m.normal * ((c1->radius - c2->radius + magnitude) * real(0.5));
}

void CircleToOBB(Manifold& m, Shape* c1, Shape*	b1) {
    Mat2 Rot(-b1->body->orientation);
    Vec2 distance = c1->body->position - b1->body->position;
    Vec2 localSpace = Rot * distance;
    Vec2 width = b1->width * real(0.5);
    real dx = absf(localSpace.x) - width.x;
    if(dx > c1->radius) return;

    real dy = absf(localSpace.y) - width.y;
    
    if(dy > c1->radius) return;
    
    Vec2 closest; // Closest Point
    // 4 Conditions to Find the Closest Point of the Circle.
    if(-localSpace.x > width.x) closest.x =  dx; else
    if( localSpace.x > width.x) closest.x = -dx;
    if(-localSpace.y > width.y) closest.y =  dy; else
    if( localSpace.y > width.y) closest.y = -dy;
    
    real magnitude = closest.SquareMagnitude();
    
    if(magnitude > c1->radius * c1->radius) return;
    
    if(magnitude) {
        magnitude = sqrtf(magnitude); 
        m.normal = closest * (real(1) / magnitude);		
    } else {
        magnitude = max(dx, dy);
        m.normal = dx > dy ? Vec2(localSpace.x < 0 ? 1 : -1, 0) : Vec2(0, localSpace.y < 0 ? 1 : -1);
    }
    
    m.numContacts = 1;
    m.contacts[0].penetration = magnitude - c1->radius;
    Rot.SetTranspose(m.normal);
    m.contacts[0].position = c1->body->position + m.normal * magnitude;
    
    m.postPosition.oldPointB[0] = distance + m.normal * magnitude;
    m.postPosition.oldOrientationB = b1->body->orientation;
}

void OBBToCircle(Manifold& m, Shape* A, Shape* B) {
    m.A = B->body; 
    m.B = A->body; 
    CircleToOBB(m, B, A);
}

inline static int FindIncidentEdgeIndex(const real& projection1, const real& projection2) {
    int i = projection1 < 0.0f ? 1 : -1;
    
    if(projection1 * i >  projection2) return 1;
    if(projection1 * i > -projection2) return 3;
    
    return 1 - i;
}

inline static Vec2 ClipSegment(Vec2& A, Vec2& B, Vec2& C, const Vec2& n) {
    Vec2 BA = B - A;
    Vec2 CA = C - A;
    
    real t = (n.x * CA.y - n.y * CA.x) / (n.x * BA.y - n.y * BA.x);
    
    return (0 > t || t > 1)? A : A + BA * t;
}

void OBBToOBB(Manifold& m, Shape* b1, Shape* b2) {
    Mat2 Rot1(b2->body->orientation - b1->body->orientation);
    Mat2 Rot2(-b1->body->orientation);
    Vec2 hA = b1->width * real(0.5);
    Vec2 hB = b2->width * real(0.5);
    Vec2 hB1 = Rot1 * hB;
    Vec2 hB2 = Rot1 * Vec2(-hB.x, hB.y);	 
    Vec2 localSpace = Rot2.Rotate(b2->body->position - b1->body->position);
    real Bx = hA.x + max(absf(hB1.x), absf(hB2.x));
    if(localSpace.x * localSpace.x > Bx * Bx) return;

    real By = hA.y + max(absf(hB1.y), absf(hB2.y));
    if(localSpace.y * localSpace.y > By * By) return;

    Vec2 normalB = -Rot1.Column0(); 
    Vec2 vertsA[] = {Vec2(-hA.x, hA.y), -hA, Vec2(hA.x, -hA.y), hA};
    Vec2 vertsB[] = {localSpace + hB2, localSpace - hB1, localSpace - hB2, localSpace + hB1};
    real Ax1 = Dot(normalB, vertsA[0]); 
    real Ax2 = Dot(normalB, vertsA[1]);
    real Bx1 = Dot(normalB, vertsB[3]);
    real Bx2 = Dot(normalB, vertsB[1]);
    real Ax = max(absf(Ax1), absf(Ax2));
    if((-Ax + Bx1) * (Ax + Bx2) > 0) return; 

    real Ay1 = Cross(normalB, vertsA[0]);
    real Ay2 = Cross(normalB, vertsA[1]); 
    real By1 = Cross(normalB, vertsB[3]);
    real By2 = Cross(normalB, vertsB[1]);
    real Ay = max(absf(Ay1), absf(Ay2));
    if((-Ay + By1) * (Ay + By2) > 0) return;
    
    Vec2 axes[] = {Vec2(-1, 0), Vec2(0, -1), normalB, Cross(normalB, -1)};
    real v1[] = {Bx + localSpace.x, By + localSpace.y, Ax - Bx1, Ay - By1};
    real v2[] = {Bx - localSpace.x, By - localSpace.y, Ax + Bx2, Ay + By2};
    int axisIndex = 0, numContacts = 0; 
    real penetration = min(v1[0], v2[0]); 
    
    for(int i = 1; i < 4; i++) {
        real minimum = min(v1[i], v2[i]);
        if(minimum <= penetration + 0.007f) {
            axisIndex = i; penetration = minimum;
        }
    }
    
    Vec2 ref[2], inc[2];
    int side = v1[axisIndex] < v2[axisIndex] ? 1 : -1;
    Vec2 normal = axes[axisIndex] * real(side); // local space normal 
    if(axisIndex < 2) {
        m.A = b2->body; m.B = b1->body;
        if(side == -1) axisIndex += 2;
        ref[0] = vertsA[axisIndex];
        ref[1] = axisIndex < 3 ? vertsA[axisIndex + 1] : vertsA[0];
        axisIndex = FindIncidentEdgeIndex(normal * axes[2], normal * axes[3]);
        inc[0] = vertsB[axisIndex];
        inc[1] = axisIndex < 3 ? vertsB[axisIndex + 1] : vertsB[0];
        normal *= -1;
    } else {
        if(side == -1) axisIndex -= 2;
        ref[0] = vertsB[axisIndex];
        ref[1] = axisIndex < 3 ? vertsB[axisIndex + 1] : vertsB[0];
        axisIndex = FindIncidentEdgeIndex(normal.x, normal.y);
        inc[0] = vertsA[axisIndex];
        inc[1] = axisIndex < 3 ? vertsA[axisIndex + 1] : vertsA[0];
    }
    
    m.normal = Rot2.Transpose(normal); // world space normal
    Vec2 ref0Point = Rot2.Transpose(ref[0]);
    
    for(int i = 0; i < 2; i++) {
        Vec2 clipPoint = ClipSegment(inc[1 - i], inc[i], ref[i], normal);
        penetration = normal * (ref[0] - clipPoint);
        if(penetration <= 0) {
            Rot2.SetTranspose(clipPoint);
            m.contacts[numContacts].penetration = penetration;
            m.contacts[numContacts].position = b1->body->position + clipPoint + m.normal * penetration;
            // Post-Projection Position
            m.postPosition.oldPointA[numContacts] = b1->body->position + clipPoint - m.A->position;
            m.postPosition.oldPointB[numContacts] = b1->body->position + ref0Point - m.B->position;
            numContacts++;
        }
    }
    // Post-Projection Position
    m.postPosition.oldOrientationA = m.A->orientation;
    m.postPosition.oldOrientationB = m.B->orientation;
    m.numContacts = numContacts;
}
