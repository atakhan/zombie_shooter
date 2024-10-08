#include "PlayerCameraSystem.h"
#include <iostream>

void PlayerCameraSystem::Init(std::vector<Entity*> *entities) {
    Entity* playerEntity = nullptr;
    PlayerComponent *playerComponent = nullptr;
    CameraComponent *camera = nullptr;
    for (auto& entity : *entities) {
        if (entity->HasComponent<PlayerComponent>()) {
            playerEntity = entity;
            playerComponent = playerEntity->GetComponent<PlayerComponent>();
            camera = playerEntity->GetComponent<CameraComponent>();
            break;
        }
    }
    if (playerEntity) {
        PositionComponent *playerPosition = playerEntity->GetComponent<PositionComponent>();
        camera->camera_.target = (Vector2) {
            Config::PLAYER_SPAWN_POSITION_X + 20.0f,
            Config::PLAYER_SPAWN_POSITION_Y + 20.0f
        };
        camera->camera_.offset = (Vector2) {
            Config::WINDOW_WIDTH / 2.0f,
            Config::WINDOW_HEIGHT / 2.0f
        };
        camera->camera_.rotation = 0.0f;
        camera->camera_.zoom = 1.0f;
    }
}

void PlayerCameraSystem::Update(std::vector<Entity*> *entities) {
    Entity* playerEntity = nullptr;
    PositionComponent *playerPosition = nullptr;
    CameraComponent *camera = nullptr;
    for (auto& entity : *entities) {
        if (entity->HasComponent<PlayerComponent>()) {
            playerEntity = entity;
            playerPosition = playerEntity->GetComponent<PositionComponent>();
            camera = playerEntity->GetComponent<CameraComponent>();
            break;
        }
    }
    if (playerEntity && playerPosition && camera) {
        camera->camera_.target = (Vector2){ 
            playerPosition->position_.x + 20, 
            playerPosition->position_.y + 20
        };
    }
}

void PlayerCameraSystem::Draw(std::vector<Entity*> *entities) {

}

