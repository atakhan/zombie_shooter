#ifndef CIRCLE_CIRCLE_COLLIDER_SYSTEM_H
#define CIRCLE_CIRCLE_COLLIDER_SYSTEM_H

#include <vector>
#include <unordered_set>
#include <raylib-cpp.hpp>
#include <iostream>

#include "../../Config.h"
#include "../../core/Bootstrap.h"
#include "../../components/Bootstrap.h"

// Custom hash function for pairs
struct hash_pair {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& pair) const {
        auto hash1 = std::hash<T1>{}(pair.first);
        auto hash2 = std::hash<T2>{}(pair.second);
        return hash1 ^ hash2; // Combine the two hash values
    }
};

class CircleCircleColliderSystem : public System {
  public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
    void Draw(std::vector<Entity*> *entities) override;
    
    void CheckCollisions(const std::vector<CircleColliderComponent>& circles);
    bool BroadPhaseCollision(const CircleColliderComponent& a, const CircleColliderComponent& b);
    bool NarrowPhaseCollision(const CircleColliderComponent& a, const CircleColliderComponent& b);
};

#endif // CIRCLE_CIRCLE_COLLIDER_SYSTEM_H

