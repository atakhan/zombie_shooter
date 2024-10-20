#include "PlayerAdrenalinSystem.h"
#include <iostream>

void PlayerAdrenalinSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Player Control System Initialized" << std::endl;
}

void PlayerAdrenalinSystem::Draw(std::vector<Entity*> *entities) {}

void PlayerAdrenalinSystem::Update(std::vector<Entity*> *entities) {
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    if (player == nullptr) { return; }

    PositionComponent *position = player->GetComponent<PositionComponent>();
    AdrenalinComponent *adrenalin = player->GetComponent<AdrenalinComponent>();

    if (!position || !adrenalin) { return; }
    //   - hearing a zombi
    // entities

    // TODO: When adrenalin should be increased?
    //   - seeing a zombi
    //   - low hp more adrenalin
}
