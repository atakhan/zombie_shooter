// PlayerSystem.cpp
#include "PlayerSystem.h"
#include <iostream>

void PlayerSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Input System Initialized" << std::endl;
}

void PlayerSystem::Update(std::vector<Entity*> *entities) {
    for (const auto& entity : *entities) {
        Player* player = nullptr;
        if (dynamic_cast<Player*>(entity)) player = static_cast<Player*>(entity);
        if (player) {
            if (IsKeyDown(KEY_RIGHT)) { 
                
                player->MoveRight();
            }
            if (IsKeyDown(KEY_LEFT))  player->SetPositionX(player->GetPositionX() - 2.0f);
            if (IsKeyDown(KEY_UP)) player->SetPositionY(player->GetPositionY() - 2.0f);
            if (IsKeyDown(KEY_DOWN)) player->SetPositionY(player->GetPositionY() + 2.0f);
        }
    }
}

