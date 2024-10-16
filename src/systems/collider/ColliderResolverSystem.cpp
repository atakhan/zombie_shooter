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
    } else 
    if (a->HasComponent<PlayerComponent>() && b->HasComponent<WallComponent>()) {
        PlayerToWall(a, b);
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

void ColliderResolverSystem::PlayerToWall(Entity *player, Entity *wall) {
    CircleColliderComponent *playerCollider = player->GetComponent<CircleColliderComponent>();
    PositionComponent *playerPosition = player->GetComponent<PositionComponent>();
    HealthComponent *playerRadius = player->GetComponent<HealthComponent>();

    RectangleColliderComponent *rectangleCollider = wall->GetComponent<RectangleColliderComponent>();
    PositionComponent *rectanglePosition = wall->GetComponent<PositionComponent>();

    if (playerCollider && playerPosition && playerRadius && rectangleCollider && rectanglePosition) {
        // Calculate the closest point on the rectangle to the circle
        float closestX = std::max(rectanglePosition->position_.x, std::min(playerPosition->position_.x, rectanglePosition->position_.x + rectangleCollider->width_));
        float closestY = std::max(rectanglePosition->position_.y, std::min(playerPosition->position_.y, rectanglePosition->position_.y + rectangleCollider->height_));

        // Calculate the distance from the circle's center to this closest point
        float dx = playerPosition->position_.x - closestX;
        float dy = playerPosition->position_.y - closestY;
        
        // Check if the distance is less than or equal to the circle's radius
        if ((dx * dx + dy * dy) <= (playerRadius->health_ * playerRadius->health_)) {
            playerPosition->position_.x += 0.01f;
            playerPosition->position_.y += 0.01f;
        }
    }
}

