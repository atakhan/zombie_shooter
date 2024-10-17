#include "TargetDrawSystem.h"
#include <iostream>

void TargetDrawSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "target Draw System Initialized" << std::endl;
}

void TargetDrawSystem::Update(std::vector<Entity*> *entities) {}

void TargetDrawSystem::Draw(std::vector<Entity*> *entities) {
    for (auto& entity : *entities) {
        if (entity == nullptr) {
            std::cerr << "Entity pointer is null!" << std::endl;
            continue; // Skip this iteration
        }
        if (entity->HasComponent<TargetComponent>()) {
            PositionComponent *position = entity->GetComponent<PositionComponent>();
            TargetComponent *target = entity->GetComponent<TargetComponent>();
            if (target) {
                DrawCircle(
                    target->position_.x,
                    target->position_.y,
                    5.0f, Config::TARGET_COLOR
                );

                DrawLine(
                    position->position_.x, 
                    position->position_.y,
                    target->position_.x,
                    target->position_.y,
                    Config::PATH_COLOR
                );
            }
        }
    }
}

