#include "PlayerDrawSystem.h"
#include <iostream>

void PlayerDrawSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Player Draw System Initialized" << std::endl;
}

void PlayerDrawSystem::Update(std::vector<Entity*> *entities) {}

void PlayerDrawSystem::Draw(std::vector<Entity*> *entities) {
    
    for (auto& entity : *entities) {
        if (entity != nullptr) {
            if (entity->HasComponent<PlayerComponent>()) {
                PlayerComponent* player = entity->GetComponent<PlayerComponent>();
                
                PositionComponent *position = entity->GetComponent<PositionComponent>();
                HealthComponent *health = entity->GetComponent<HealthComponent>();
                
                if (position && health) {
                    DrawCircle(
                        position->position_.x,
                        position->position_.y,
                        health->health_,
                        Config::PLAYER_COLOR
                    );
                }
            }
        }

    }
    
}

