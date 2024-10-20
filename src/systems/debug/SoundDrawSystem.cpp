#include "SoundDrawSystem.h"
#include <iostream>

void SoundDrawSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Sound Draw System Initialized" << std::endl;
}

void SoundDrawSystem::Update(std::vector<Entity*> *entities) {}

void SoundDrawSystem::Draw(std::vector<Entity*> *entities) {
    for (auto& entity : *entities) {
        if (entity == nullptr) {
            std::cerr << "Entity pointer is null!" << std::endl;
            continue; // Skip this iteration
        }
        if (entity->HasComponent<SoundComponent>()) {
            if (entity->HasComponent<PlayerComponent>()) {
                PositionComponent *position = entity->GetComponent<PositionComponent>();
                SoundComponent *sound = entity->GetComponent<SoundComponent>();
                if (position && sound) {
                    DrawCircle(
                        position->position_.x,
                        position->position_.y,
                        sound->currentRadius,
                        Config::SOUND_RADIUS_COLOR
                    );
                }
                BreathSoundComponent *breathSound = entity->GetComponent<BreathSoundComponent>();
                if (position && sound) {
                    DrawCircle(
                        position->position_.x,
                        position->position_.y,
                        breathSound->currentValue / 4.0f,
                        R6G6B6A1
                    );
                }
            }
        }
    }
}

