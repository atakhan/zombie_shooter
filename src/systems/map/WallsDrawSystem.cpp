#include "WallsDrawSystem.h"
#include <iostream>

void WallsDrawSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Walls Draw System Initialized" << std::endl;
}

void WallsDrawSystem::Update(std::vector<Entity*> *entities) {}

void WallsDrawSystem::DrawWallsMapCell(float posx, float posy, int w, int h) {
    DrawRectangle(posx, posy, w, h, RED);
}

void WallsDrawSystem::Draw(std::vector<Entity*> *entities) {
    for (auto& entity : *entities) {
        if (entity != nullptr) {
            if (entity->HasComponent<WallComponent>()) {
                RectangleColliderComponent *recCollider = entity->GetComponent<RectangleColliderComponent>();
                PositionComponent *position = entity->GetComponent<PositionComponent>();
                if (recCollider) {
                    DrawWallsMapCell(position->position_.x, position->position_.y, recCollider->width_, recCollider->height_);
                }
            }
        }

    }
    
}

