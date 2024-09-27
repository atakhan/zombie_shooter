#include "CameraSystem.h"
#include <iostream>

void CameraSystem::Init(std::vector<Entity*> *entities) {
    Player* player = nullptr;
    for (const auto& entity : *entities) {
        if (dynamic_cast<Player*>(entity)) player = static_cast<Player*>(entity);
    }
    if (player) {
        player->camera_.SetTarget((Vector2) {
            Config::PLAYER_SPAWN_POSITION_X + 20.0f,
            Config::PLAYER_SPAWN_POSITION_Y + 20.0f
        });
        player->camera_.SetOffset((Vector2) {
            Config::WINDOW_WIDTH / 2.0f,
            Config::WINDOW_HEIGHT / 2.0f
        });
        player->camera_.SetRotation(0.0f);
        player->camera_.SetZoom(1.0f);
    }
}

void CameraSystem::Update(std::vector<Entity*> *entities) {
    Player* player = nullptr;
    for (const auto& entity : *entities) {
        if (dynamic_cast<Player*>(entity)) player = static_cast<Player*>(entity);
    }
    if (player) {
        player->camera_.SetTarget((Vector2){ 
            player->GetPositionX() + 20, 
            player->GetPositionY() + 20
        });
    }
}


