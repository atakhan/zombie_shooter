#include "CircleCircleColliderSystem.h"

void CircleCircleColliderSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Zombie targeting System Initialized" << std::endl;
}

void CircleCircleColliderSystem::Draw(std::vector<Entity*> *entities) {}

void CircleCircleColliderSystem::Update(std::vector<Entity*> *entities) {
    std::vector<CircleColliderComponent> *circles = nullptr;
    for (auto& entity : *entities) {
        CircleColliderComponent *circleColliderComponent = nullptr;
        if (entity->HasComponent<CircleColliderComponent>()) {
            circles->push_back(*entity->GetComponent<CircleColliderComponent>());
        }
    }

    
}

void CircleCircleColliderSystem::CheckCollisions(const std::vector<CircleColliderComponent>& circles) {
    // Broad Phase: Use a simple spatial partitioning method (e.g., grid, bounding box)
    std::unordered_set<std::pair<int, int>, hash_pair> broadPhaseCollisions;
    
    for (size_t i = 0; i < circles.size(); ++i) {
        for (size_t j = i + 1; j < circles.size(); ++j) {
            if (BroadPhaseCollision(circles[i], circles[j])) {
                broadPhaseCollisions.emplace(i, j);
            }
        }
    }

    // Narrow Phase: Check for actual collisions
    for (const auto& pair : broadPhaseCollisions) {
        if (NarrowPhaseCollision(circles[pair.first], circles[pair.second])) {
            // Handle collision response here
            std::cout << "Collision detected between circle " << pair.first 
                        << " and circle " << pair.second << "!" << std::endl;
        }
    }
}

// Broad Phase Collision Detection (Bounding Circle Check)
bool BroadPhaseCollision(const CircleColliderComponent& a, const CircleColliderComponent& b) {
    // Check if bounding circles overlap
    float dx = a.center_.x - b.center_.x;
    float dy = a.center_.y - b.center_.y;
    float distanceSquared = dx * dx + dy * dy;
    float radiusSum = a.radius_ + b.radius_;
    return distanceSquared <= (radiusSum * radiusSum);
}

// Narrow Phase Collision Detection (Exact Circle Overlap Check)
bool NarrowPhaseCollision(const CircleColliderComponent& a, const CircleColliderComponent& b) {
    float dx = a.center_.x - b.center_.x;
    float dy = a.center_.y - b.center_.y;
    float distanceSquared = dx * dx + dy * dy;
    float radiusSum = a.radius_ + b.radius_;
    return distanceSquared < (radiusSum * radiusSum);
}
