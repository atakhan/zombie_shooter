#include "CircleCircleColliderSystem.h"

void CircleCircleColliderSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Zombie targeting System Initialized" << std::endl;
}

void CircleCircleColliderSystem::Draw(std::vector<Entity*> *entities) {}

void CircleCircleColliderSystem::Update(std::vector<Entity*> *entities) {
    for (size_t i = 0; i < entities->size(); ++i) {
        for (size_t j = i + 1; j < entities->size(); ++j) {
            if (CollisionDetected(entities->at(i), entities->at(j))) {
                entities->at(i)->GetComponent<CircleColliderComponent>()->isCollide_ = true;
                entities->at(j)->GetComponent<CircleColliderComponent>()->isCollide_ = true;
            }
        }
    }
}

bool CircleCircleColliderSystem::CollisionDetected(Entity *entityA, Entity* entityB) {
    float dx = entityA->GetComponent<CircleColliderComponent>()->center_.x - entityB->GetComponent<CircleColliderComponent>()->center_.x;
    float dy = entityA->GetComponent<CircleColliderComponent>()->center_.y - entityB->GetComponent<CircleColliderComponent>()->center_.y;
    float distanceSquared = dx * dx + dy * dy;
    float radiusSum = entityA->GetComponent<CircleColliderComponent>()->radius_ + entityB->GetComponent<CircleColliderComponent>()->radius_;

    return distanceSquared <= (radiusSum * radiusSum);
}