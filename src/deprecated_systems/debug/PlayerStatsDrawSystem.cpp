#include "PlayerStatsDrawSystem.h"
#include <iostream>

void PlayerStatsDrawSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Zombie Stats Draw System Initialized" << std::endl;
}

void PlayerStatsDrawSystem::Update(std::vector<Entity*> *entities) {}

void PlayerStatsDrawSystem::Draw(std::vector<Entity*> *entities) {
    for (auto& entity : *entities) {
        if (entity == nullptr) {
            std::cerr << "Entity pointer is null!" << std::endl;
            continue; // Skip this iteration
        }
        if (entity->HasComponent<PlayerComponent>()) {
            PositionComponent *position = entity->GetComponent<PositionComponent>();
            HealthComponent *health = entity->GetComponent<HealthComponent>();

            if (position && health) {

                UiTools::DrawTitleValueText(Config::DEFAULT_UI_TEXT_COLOR, position->position_, health->health_, 
                    1, "current pos: ", std::to_string(position->position_.x) + ", " + std::to_string(position->position_.y)
                );
            }
        }
        
    }
}

