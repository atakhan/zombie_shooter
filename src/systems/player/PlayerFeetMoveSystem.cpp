#include "PlayerFeetMoveSystem.h"
#include <iostream>

void PlayerFeetMoveSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Player Adrenalin System Initialized" << std::endl;
}

void PlayerFeetMoveSystem::Draw(std::vector<Entity*> *entities) {
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    if (player == nullptr) { return; }
    FeetComponent *feet = player->GetComponent<FeetComponent>();

    DrawCircleV(feet->leftPosition_, feet->leftRadius_, RAYWHITE);
    DrawCircleV(feet->rightPosition_, feet->rightRadius_, RAYWHITE);
}

void PlayerFeetMoveSystem::Update(std::vector<Entity*> *entities) {
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    if (player == nullptr) { return; }
    
    PositionComponent *playerPosition = player->GetComponent<PositionComponent>();
    HealthComponent *playerHealth = player->GetComponent<HealthComponent>();
    FeetComponent *feet = player->GetComponent<FeetComponent>();

    if (!playerPosition || !playerHealth || !feet) { return; }

    feet->leftPosition_ = (Vector2) {
        playerPosition->position_.x + (playerHealth->health_ / 4),
        playerPosition->position_.y + (playerHealth->health_ / 4)
    };
    feet->rightPosition_ = (Vector2) {
        playerPosition->position_.x - (playerHealth->health_ / 4),
        playerPosition->position_.y - (playerHealth->health_ / 4)
    };
    feet->leftRadius_ = playerHealth->health_ / 3;
    feet->rightRadius_ = playerHealth->health_ / 3;
}

