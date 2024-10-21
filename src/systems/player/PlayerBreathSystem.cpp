#include "PlayerBreathSystem.h"
#include <iostream>

void PlayerBreathSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Player Breath System Initialized" << std::endl;
}

void PlayerBreathSystem::Draw(std::vector<Entity*> *entities) {
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    if (player == nullptr) { return; }
    BreathSoundComponent *breathSound = player->GetComponent<BreathSoundComponent>();
    PositionComponent *position = player->GetComponent<PositionComponent>();
    if (breathSound && position) {
        std::cout << "breathSound->current_: " << breathSound->current_ << std::endl;
        DrawCircle(
            position->position_.x,
            position->position_.y,
            breathSound->current_,
            RAYWHITE
        );
    } else {
        std::cout << "breath sound draw components not found" << std::endl;
    }
}

void PlayerBreathSystem::Update(std::vector<Entity*> *entities) {
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    if (player == nullptr) { return; }

    PositionComponent *position = player->GetComponent<PositionComponent>();
    BreathSoundComponent *breathSound = player->GetComponent<BreathSoundComponent>();
    AdrenalinComponent *adrenalin = player->GetComponent<AdrenalinComponent>();

    if (!position || !breathSound || !adrenalin) { return; }
    if (breathSound->current_ < breathSound->min_) {
        breathSound->inhale_ = true;
    }
    if (breathSound->max_ < breathSound->current_) {
        breathSound->inhale_ = false;
    }

    if (breathSound->inhale_ == true) {
        breathSound->current_ = breathSound->current_ + (breathSound->step_ * adrenalin->current_);
    } else {
        breathSound->current_ = breathSound->current_ - (breathSound->step_ * adrenalin->current_);
    }

}
