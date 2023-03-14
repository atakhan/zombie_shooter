#include "Scene.h"

typedef std::pair<ManifoldKey, Manifold> ManPair;
typedef std::map<ManifoldKey, Manifold>::iterator ManifoldAux;

int Scene::CorrectionType = NONE;

void Scene::Add(RigidBody* body) {
    bodies.push_back(body);
}

void Scene::Clear(void) {
    bodies.clear(); 
    manifolds.clear();
}

void Scene::BroadPhase() {
    const int length = bodies.size();
    
    for(int i = 0; i < length; i++) {
        RigidBody* bi = bodies[i];
        for(int j = i + 1; j < length; j++) {
            RigidBody* bj = bodies[j];
            if(bi->m + bj->m == 0.0f) continue;
            
            ManifoldKey key(bi, bj);
            Manifold newMan(bi, bj);
            
            if(newMan.numContacts > 0) {
                ManifoldAux iter = manifolds.find(key);
                
                if(iter == manifolds.end()) {
                    manifolds.insert(ManPair(key, newMan));
                } else {
                    iter->second.normal = newMan.normal;
                    iter->second.A = newMan.A;
                    iter->second.B = newMan.B;
                    iter->second.postPosition = newMan.postPosition;
                    iter->second.Update(newMan.contacts, newMan.numContacts);
                }
            } else {
                manifolds.erase(key);
            }
        }
    }
}

void Scene::Step(const real& dt) {
    BroadPhase();
  
    for(auto b : bodies) {
        b->velocity += (b->force * b->invm + gravity * b->gravityScale) * dt; // v = v + Fext * M⁻¹ * Δt
        b->angularVelocity += b->torque * b->invI * dt;                       // ω = ω + τext * I⁻¹ * Δt
        b->velocity *= pow(0.97f, b->linearDamping);                          // min = 0.97f && max = 1;
        b->angularVelocity *= pow(0.97f, b->angularDamping);                  // min = 0.97f && max = 1;
    }

    for(ManifoldAux temp = manifolds.begin(); temp != manifolds.end(); temp++) {
        temp->second.PreStep(dt);
    }
    
    for(ManifoldAux temp = manifolds.begin(); temp != manifolds.end(); temp++) {
        // v = v + P * M⁻¹
        // ω = ω + L * I⁻¹
        temp->second.WarmStarting(); 
    }
  	
    // (SI/PGS) Sequential-Impulse/Projected-Gauss-Seidel 
    for(int i = 0; i < iterVel; i++) {
        for(ManifoldAux temp = manifolds.begin(); temp != manifolds.end(); temp++) {
            temp->second.ApplyImpulse(); 
        }
    }

    if(CorrectionType == NGS) {
        // (NGS) Newton-Ranpson-Gauss-Seidel OR Non-Linear-Gauss-Seidel
        for(int i = 0; i < iterPos; i++) {
            for(ManifoldAux temp = manifolds.begin(); temp != manifolds.end(); temp++) {
                temp->second.ApplyCorrection();
            }
        }
    }

    for(auto b : bodies) {
        b->position += b->velocity * dt; // x = x + v * Δt
        b->orientation += b->angularVelocity * dt; // θ = θ + ω * Δt 
        b->force.SetZero(); 
        b->torque = 0.0f;
    }
}