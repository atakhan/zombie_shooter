#include "ZombieStatsDrawSystem.h"
#include <iostream>

void ZombieStatsDrawSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Zombie Stats Draw System Initialized" << std::endl;
}

void ZombieStatsDrawSystem::Update(std::vector<Entity*> *entities) {}

void ZombieStatsDrawSystem::Draw(std::vector<Entity*> *entities) {
    for (auto& entity : *entities) {
        if (entity == nullptr) {
            std::cerr << "Entity pointer is null!" << std::endl;
            continue; // Skip this iteration
        }
        if (entity->HasComponent<ZombieComponent>()) {
            PositionComponent *position = entity->GetComponent<PositionComponent>();
            HealthComponent *health = entity->GetComponent<HealthComponent>();
            TargetComponent *target = entity->GetComponent<TargetComponent>();

            if (position && target && health) {

                UiTools::DrawTitleValueText(Config::DEFAULT_UI_TEXT_COLOR, position->position_, health->health_, 
                    1, "current pos: ", std::to_string(position->position_.x) + ", " + std::to_string(position->position_.y)
                );
                
                UiTools::DrawTitleValueText(Config::DEFAULT_UI_TEXT_COLOR, position->position_, health->health_, 
                    2, "target: ", std::to_string(target->position_.x) + ", " + std::to_string(target->position_.y)
                );
                
                UiTools::DrawTitleValueText(Config::DEFAULT_UI_TEXT_COLOR, position->position_, health->health_, 
                    3, "target status: ", std::to_string(target->active_)
                );
            }
        }
        
    }
}

