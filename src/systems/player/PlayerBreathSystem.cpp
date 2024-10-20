#include "PlayerBreathSystem.h"
#include <iostream>

void PlayerBreathSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Player Control System Initialized" << std::endl;
}

void PlayerBreathSystem::Draw(std::vector<Entity*> *entities) {}

void PlayerBreathSystem::Update(std::vector<Entity*> *entities) {
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    if (player == nullptr) { return; }

    PositionComponent *position = player->GetComponent<PositionComponent>();
    BreathSoundComponent *breathSound = player->GetComponent<BreathSoundComponent>();

    if (!position || !breathSound) { return; }

    breathSound->maxValue = 

    if (breathSound->inhale == true) {
        float newValue = breathSound->currentValue + 0.2f;
        if (newValue < breathSound->maxValue) {
            breathSound->currentValue = newValue;
        } else {
            breathSound->inhale = false;
        }
    } else {
        float newValue = breathSound->currentValue - 0.2f;
        if (newValue > breathSound->minValue) {
            breathSound->currentValue = newValue;
        } else {
            breathSound->inhale = true;
        }
    }

}
