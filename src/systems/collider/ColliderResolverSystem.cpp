#include "ColliderResolverSystem.h"

void ColliderResolverSystem::Init(std::vector<Entity*> *entities) {}

void ColliderResolverSystem::Update(std::vector<Entity*> *entities) {
    for (size_t i = 0; i < entities->size(); ++i) {
        Entity *entityA = entities->at(i);
        CircleColliderComponent *collider = entityA->GetComponent<CircleColliderComponent>();
        if (collider) {
            if (collider->collisions_.size() > 0) {
                while (!collider->collisions_.empty()) {
                    unsigned collidedEntityIndex = collider->collisions_.front();
                    Entity * entityB = entities->at(collidedEntityIndex);
                    HandleCollision(entityA, entityB);
                    collider->collisions_.pop();
                    collider->isCollide_ = false;
                }
                
            }
        }
    }
}

void ColliderResolverSystem::Draw(std::vector<Entity*> *entities) {}

void ColliderResolverSystem::HandleCollision(Entity *a, Entity *b) {
    if (!a->HasComponent<CircleColliderComponent>() || !b->HasComponent<CircleColliderComponent>()) {
        return;
    }

    // if (a->GetComponent<CircleColliderComponent>()->isCollide_ == false || b->GetComponent<CircleColliderComponent>()->isCollide_ == false) {
    //     a->GetComponent<CircleColliderComponent>()->isCollide_ = false;
    //     b->GetComponent<CircleColliderComponent>()->isCollide_ = false;
    //     return;
    // }

    if (a->HasComponent<PlayerComponent>() && b->HasComponent<ZombieComponent>()) {
        PlayerToZombie(a, b);
    } else 
    if (a->HasComponent<ZombieComponent>() && b->HasComponent<ZombieComponent>()) {
        ZombieToZombie(a, b);
    }
}

void ColliderResolverSystem::PlayerToZombie(Entity *a, Entity *b) {
    std::cout << "collision detected between player and zombie" << std::endl;
}

void ColliderResolverSystem::ZombieToZombie(Entity *z1, Entity *z2) {
    CircleColliderComponent *z1Collider = z1->GetComponent<CircleColliderComponent>();
    CircleColliderComponent *z2Collider = z2->GetComponent<CircleColliderComponent>();

    if (z1Collider->isCollide_ && z1Collider->isCollide_) {
        PositionComponent *z1Pos = z1->GetComponent<PositionComponent>();
        HealthComponent *z1Radius = z1->GetComponent<HealthComponent>();
        PositionComponent *z2Pos = z2->GetComponent<PositionComponent>();
        HealthComponent *z2Radius = z2->GetComponent<HealthComponent>();

        float dx = z1Pos->position_.x - z2Pos->position_.x;
        float dy = z1Pos->position_.y - z2Pos->position_.y;
        float distanceSquared = (dx * dx) + (dy * dy);

        float overlapValue = (z1Radius->health_ + z2Radius->health_) - sqrtf(distanceSquared);

        z1Pos->position_.x = z1Pos->position_.x + (overlapValue/2);
        z2Pos->position_.x = z2Pos->position_.x + ((overlapValue/2) * (-1));
    }
}

