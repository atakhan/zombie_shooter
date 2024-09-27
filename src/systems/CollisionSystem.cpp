#include "CollisionSystem.h"

void CollisionSystem::Init(std::vector<Entity*> *entities) {

}

void CollisionSystem::Update(std::vector<Entity*> *entities) {
    for (Entity* entity : *entities) {
        entity.
    }

    for (size_t i = 0; i < entities->size(); ++i) {
        if (entities[i].HasComponent<CircleColliderComponent>()) {
            CircleColliderComponent& circleA = entities[i].GetComponent<CircleColliderComponent>();

            for (size_t j = i + 1; j < entities.size(); ++j) {
                if (entities[j].HasComponent<CircleColliderComponent>()) {
                    CircleColliderComponent& circleB = entities[j].GetComponent<CircleColliderComponent>();

                    // Check for collision (Circle-Circle collision detection)
                    if (CheckCircleCollision(circleA, circleB)) {
                        // Handle collision response here
                        if (!circleA.isTrigger && !circleB.isTrigger) {
                            // Handle physical collision
                        } else {
                            // Handle trigger event
                        }
                    }
                }
            }
        }
    }
}

// Simple Circle-Circle collision check
bool CollisionSystem::CheckCircleCollision(const CircleColliderComponent& a, const CircleColliderComponent& b) {
    float dx = a.position_.x - b.position_.x;
    float dy = a.position_.y - b.position_.y;
    float distanceSquared = dx * dx + dy * dy;
    float radiusSum = a.radius_ + b.radius_;

    return distanceSquared < (radiusSum * radiusSum); // If distance is less than the sum of the radii, they collide
}
