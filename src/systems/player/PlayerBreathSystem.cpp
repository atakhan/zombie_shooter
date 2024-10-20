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
    BreathComponent *breath = player->GetComponent<BreathComponent>();
    SoundComponent *sound = player->GetComponent<SoundComponent>();

    if (!position || !sound || !breath) { return; }



}
