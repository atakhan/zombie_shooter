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
                    HandleCollision(entityA, entities->at(collidedEntityIndex));
                    collider->collisions_.pop();
                }
                
            }
        }
    }
}

void ColliderResolverSystem::Draw(std::vector<Entity*> *entities) {}

void ColliderResolverSystem::HandleCollision(Entity *a, Entity *b) {
    if (a->HasComponent<PlayerComponent>() && b->HasComponent<ZombieComponent>()) {

    }
}

