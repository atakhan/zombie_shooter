#include "ZombieDrawSystem.h"
#include <iostream>

void ZombieDrawSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Zombie Draw System Initialized" << std::endl;
}

void ZombieDrawSystem::Update(std::vector<Entity*> *entities) {}

void ZombieDrawSystem::Draw(std::vector<Entity*> *entities) {
    for (auto& entity : *entities) {
        if (entity == nullptr) {
            std::cerr << "Entity pointer is null!" << std::endl;
            continue; // Skip this iteration
        }
        if (entity->HasComponent<ZombieComponent>()) {
            ZombieComponent *zombie = entity->GetComponent<ZombieComponent>();
            PositionComponent *position = entity->GetComponent<PositionComponent>();
            HealthComponent *health = entity->GetComponent<HealthComponent>();
            TargetComponent *target = entity->GetComponent<TargetComponent>();

            if (position && health) {
                DrawCircle(
                    position->position_.x,
                    position->position_.y,
                    health->health_,
                    Config::ZOMBIE_COLOR
                );
            }
        }
        
    }
}

