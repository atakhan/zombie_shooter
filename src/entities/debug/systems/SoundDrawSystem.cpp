#include "SoundDrawSystem.h"
#include <iostream>

void SoundDrawSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Sound Draw System Initialized" << std::endl;
}

void SoundDrawSystem::Update(std::vector<Entity*> *entities) {}

void SoundDrawSystem::Draw(std::vector<Entity*> *entities) {
    // for (auto& entity : *entities) {
    //     if (entity == nullptr) { continue; }
    //     if (entity->HasComponent<SoundComponent>()) {
    //         if (entity->HasComponent<ZombieComponent>()) {
    //             PositionComponent *position = entity->GetComponent<PositionComponent>();
    //             SoundComponent *sound = entity->GetComponent<SoundComponent>();
    //             if (position && sound) {
    //                 DrawCircle(
    //                     position->position_.x,
    //                     position->position_.y,
    //                     sound->currentRadius,
    //                     GRAY_5_05
    //                 );
    //             }
    //         } else
    //         if (entity->HasComponent<PlayerComponent>()) {
    //             PositionComponent *position = entity->GetComponent<PositionComponent>();
    //             SoundComponent *sound = entity->GetComponent<SoundComponent>();
    //             if (position && sound) {
    //                 DrawCircle(
    //                     position->position_.x,
    //                     position->position_.y,
    //                     sound->currentRadius,
    //                     Config::SOUND_RADIUS_COLOR
    //                 );
    //             }
    //         }
    //     }
    // }
}

