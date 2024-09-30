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
            PositionComponent* position = nullptr;
            HealthComponent* health = nullptr;
            SoundComponent* sound = nullptr;
            if (entity->HasComponent<PositionComponent>()) {
                position = entity->GetComponent<PositionComponent>();
            }
            if (entity->HasComponent<HealthComponent>()) {
                health = entity->GetComponent<HealthComponent>();
            }

            if (entity->HasComponent<SoundComponent>()) {
                sound = entity->GetComponent<SoundComponent>();
            }

            if (position && health && sound) {
                DrawCircle(
                    position->position_.x,
                    position->position_.y,
                    sound->currentRadius,
                    Config::SOUND_RADIUS_COLOR
                );
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

