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
                entities->at(i)->GetComponent<CircleColliderComponent>()->collisions_.push(j);
                entities->at(j)->GetComponent<CircleColliderComponent>()->collisions_.push(i);
            }
        }
    }
}

bool CircleCircleColliderSystem::CollisionDetected(Entity *entityA, Entity* entityB) {
    CircleColliderComponent *aCollider = entityA->GetComponent<CircleColliderComponent>();
    PositionComponent *aPosition = entityA->GetComponent<PositionComponent>();
    HealthComponent *aRadius = entityA->GetComponent<HealthComponent>();

    CircleColliderComponent *bCollider = entityB->GetComponent<CircleColliderComponent>();
    PositionComponent *bPosition = entityB->GetComponent<PositionComponent>();
    HealthComponent *bRadius = entityB->GetComponent<HealthComponent>();

    if (aCollider && aPosition && aRadius && bCollider && bPosition && bRadius) {
        float dx = aPosition->position_.x - bPosition->position_.x;
        float dy = aPosition->position_.y - bPosition->position_.y;
        float distanceSquared = dx * dx + dy * dy;
        float radiusSum = aRadius->health_ + bRadius->health_;
    
        return distanceSquared <= (radiusSum * radiusSum);
    
    } else {

        return false;
    }

}