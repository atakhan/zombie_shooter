#include "CircleRectangleColliderSystem.h"

void CircleRectangleColliderSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Circle-Rectangle Collider System Initialized" << std::endl;
}

void CircleRectangleColliderSystem::Draw(std::vector<Entity*> *entities) {}

void CircleRectangleColliderSystem::Update(std::vector<Entity*> *entities) {
    for (size_t i = 0; i < entities->size(); ++i) {
        for (size_t j = 0; j < entities->size(); ++j) {
            if (i == j) {
                continue;
            }
            if (entities->at(i)->HasComponent<CircleColliderComponent>()) {
                if (entities->at(j)->HasComponent<RectangleColliderComponent>()) {
                    if (CollisionDetected(entities->at(i), entities->at(j))) {
                        entities->at(i)->GetComponent<CircleColliderComponent>()->isCollide_ = true;
                        entities->at(i)->GetComponent<CircleColliderComponent>()->collisions_.push(j);
                        
                        entities->at(j)->GetComponent<RectangleColliderComponent>()->isCollide_ = true;
                        entities->at(j)->GetComponent<RectangleColliderComponent>()->collisions_.push(i);
                    }
                }
            }
        }
    }
}

bool CircleRectangleColliderSystem::CollisionDetected(Entity *circleEntity, Entity* rectangleEntity) {
    // Circle
    CircleColliderComponent *circleCollider = circleEntity->GetComponent<CircleColliderComponent>();
    PositionComponent *circlePosition = circleEntity->GetComponent<PositionComponent>();
    HealthComponent *circleRadius = circleEntity->GetComponent<HealthComponent>();

    // Rectangle
    RectangleColliderComponent *rectangleCollider = rectangleEntity->GetComponent<RectangleColliderComponent>();
    PositionComponent *rectanglePosition = rectangleEntity->GetComponent<PositionComponent>();

    if (circleCollider && circlePosition && circleRadius && rectangleCollider && rectanglePosition) {
        return Intersects(
            circlePosition->position_.x, 
            circlePosition->position_.y, 
            circleCollider->radius_,
            rectanglePosition->position_.x,
            rectanglePosition->position_.y,
            rectangleCollider->width_,
            rectangleCollider->height_
        );
    }

    return false;
}

bool CircleRectangleColliderSystem::Intersects(float cx, float cy, float cr, float rx, float ry, float rw, float rh)
{
    return CheckCollisionCircleRec((Vector2){cx, cy}, cr, (Rectangle){
        rx, ry, rw, rh
    });
}