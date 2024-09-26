// CameraSystem.cpp
#include "CameraSystem.h"
#include <iostream>

void CameraSystem::Init(std::vector<Entity*> *entities) {
    CameraEntity* camera = nullptr;
    for (const auto& entity : *entities) {
        if (dynamic_cast<CameraEntity*>(entity)) camera = static_cast<CameraEntity*>(entity);
    }
    camera->SetTarget((Vector2) {
        Config::PLAYER_SPAWN_POSITION_X + 20.0f,
        Config::PLAYER_SPAWN_POSITION_Y + 20.0f
    });
    camera->SetOffset((Vector2) {
        Config::WINDOW_WIDTH / 2.0f,
        Config::WINDOW_HEIGHT / 2.0f
    });
    camera->SetRotation(0.0f);
    camera->SetZoom(1.0f);
}

void CameraSystem::Update(std::vector<Entity*> *entities) {
    Player* player = nullptr;
    CameraEntity* camera = nullptr;
    for (const auto& entity : *entities) {
        if (dynamic_cast<Player*>(entity)) player = static_cast<Player*>(entity);
        if (dynamic_cast<CameraEntity*>(entity)) camera = static_cast<CameraEntity*>(entity);
    }

    if (player) {
        camera->SetTarget((Vector2){ 
            player->GetPositionX() + 20, 
            player->GetPositionY() + 20
        });
    }
}

