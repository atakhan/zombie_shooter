#include "SoundDrawSystem.h"
#include <iostream>

void SoundDrawSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Player Draw System Initialized" << std::endl;
}

void SoundDrawSystem::Update(std::vector<Entity*> *entities) {}

void SoundDrawSystem::Draw(std::vector<Entity*> *entities) {
    
    // for (auto& entity : *entities) {
    //     if (entity != nullptr) {
    //         if (entity->HasComponent<SoundComponent>()) {
    //             SoundComponent* sound = entity->GetComponent<SoundComponent>();
    //             DrawMessArea();
    //         }
    //     }

    // }
    
}

// void SoundDrawSystem::DrawMessArea(PositionComponent* position, SoundComponent* sound) {
    // DrawCircle(
    //     position->position_.x,
    //     position->position_.y,
    //     sound->currentRadius,
    //     Config::SOUND_RADIUS_COLOR
    // );
// }