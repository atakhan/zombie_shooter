#include "CircleRectangleColliderSystem.h"

void CircleRectangleColliderSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Circle-Rectangle Collider System Initialized" << std::endl;
}

void CircleRectangleColliderSystem::Draw(std::vector<Entity*> *entities) {}

void CircleRectangleColliderSystem::Update(std::vector<Entity*> *entities) {
    for (size_t i = 0; i < entities->size(); ++i) {
        for (size_t j = 0; j < entities->size(); ++j) {
            if (i != j && CollisionDetected(entities->at(i), entities->at(j))) {
                entities->at(i)->GetComponent<CircleColliderComponent>()->isCollide_ = true;
                entities->at(i)->GetComponent<CircleColliderComponent>()->collisions_.push(j);
                
                entities->at(j)->GetComponent<RectangleColliderComponent>()->isCollide_ = true;
                entities->at(j)->GetComponent<RectangleColliderComponent>()->collisions_.push(i);
            }
        }
    }
}

bool CircleRectangleColliderSystem::CollisionDetected(Entity *circleEntity, Entity* rectangleEntity) {
    CircleColliderComponent *circleCollider = circleEntity->GetComponent<CircleColliderComponent>();
    PositionComponent *circlePosition = circleEntity->GetComponent<PositionComponent>();
    HealthComponent *circleRadius = circleEntity->GetComponent<HealthComponent>();

    RectangleColliderComponent *rectangleCollider = rectangleEntity->GetComponent<RectangleColliderComponent>();
    PositionComponent *rectanglePosition = rectangleEntity->GetComponent<PositionComponent>();

    if (circleCollider && circlePosition && circleRadius && rectangleCollider && rectanglePosition) {
        // Calculate the closest point on the rectangle to the circle
        float closestX = std::max(rectanglePosition->position_.x, std::min(circlePosition->position_.x, rectanglePosition->position_.x + rectangleCollider->width_));
        float closestY = std::max(rectanglePosition->position_.y, std::min(circlePosition->position_.y, rectanglePosition->position_.y + rectangleCollider->height_));

        // Calculate the distance from the circle's center to this closest point
        float dx = circlePosition->position_.x - closestX;
        float dy = circlePosition->position_.y - closestY;
        
        // Check if the distance is less than or equal to the circle's radius
        return (dx * dx + dy * dy) <= (circleRadius->health_ * circleRadius->health_);
    }

    return false;
}