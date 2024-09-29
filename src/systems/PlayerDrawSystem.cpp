#include "PlayerDrawSystem.h"
#include <iostream>

void PlayerDrawSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Player Draw System Initialized" << std::endl;
}

void PlayerDrawSystem::Update(std::vector<Entity*> *entities) {}

void PlayerDrawSystem::Draw(std::vector<Entity*> *entities) {
    Entity* player = nullptr;
    for (auto& entity : *entities) {
        if (entity->HasComponent<PlayerComponent>()) {
            player = entity;
            break;
        }
    }

    if (!player) {
        std::cerr << "No player entity found!" << std::endl;
        return; // Exit if no player entity is found
    }

    PositionComponent* position = nullptr;
    HealthComponent* health = nullptr;
    SoundComponent* sound = nullptr;

    if (player->HasComponent<PositionComponent>()) {
        position = player->GetComponent<PositionComponent>();
    }

    if (player->HasComponent<HealthComponent>()) {
        health = player->GetComponent<HealthComponent>();
    }

    if (player->HasComponent<SoundComponent>()) {
        sound = player->GetComponent<SoundComponent>();
    }

    if (position && health && sound) {
        DrawCircle(
            position->position_.x,
            position->position_.y,
            sound->currentRadius,
            Config::SOUND_RADIUS_COLOR
        );
        DrawCircle(
            position->position_.x,
            position->position_.y,
            health->health_,
            Config::PLAYER_COLOR
        );
    }
    
}

