#include "PlayerFeetMoveSystem.h"
#include <iostream>

void PlayerFeetMoveSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Player Adrenalin System Initialized" << std::endl;
}

void PlayerFeetMoveSystem::Draw(std::vector<Entity*> *entities) {
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    if (player == nullptr) { return; }
    PositionComponent *playerPosition = player->GetComponent<PositionComponent>();
    DrawRectangle(playerPosition->position_.x, playerPosition->position_.y - 10.0f, 15.0f, 15.0f, VIOLET);
    DrawRectangle(playerPosition->position_.x, playerPosition->position_.y + 10.0f, 15.0f, 15.0f, VIOLET);
    // DrawRectangle(playerPosition->position_.x, playerPosition->position_.y, adrenalin->max_, adrenalin->min_, RED_3_4);
    // DrawRectangle(playerPosition->position_.x, playerPosition->position_.y, adrenalin->current_, adrenalin->min_, RED_3_8);
}

void PlayerFeetMoveSystem::Update(std::vector<Entity*> *entities) {
    // Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    // if (player == nullptr) { return; }

    // PositionComponent *playerPosition = player->GetComponent<PositionComponent>();
    // HealthComponent *playerHealth = player->GetComponent<HealthComponent>();
    // AdrenalinComponent *adrenalin = player->GetComponent<AdrenalinComponent>();

    // if (!playerPosition || !playerHealth || !adrenalin) { return; }

    
    // // If adrenalin is changable
    // std::cout << "PlayerFeetMoveSystem : update : " << std::endl;
    // std::cout << "min: " << adrenalin->min_ << std::endl;
    // std::cout << "max: " << adrenalin->max_ << std::endl;
    // std::cout << "current: " << adrenalin->current_ << std::endl;

    // //   - hearing a zombi
    // for (auto& entity : *entities) {
    //     if (entity == nullptr) { continue; }
    //     if (entity->HasComponent<ZombieComponent>()) {
    //         PositionComponent *zombiePosition = entity->GetComponent<PositionComponent>();
    //         SoundComponent *zombieSound = entity->GetComponent<SoundComponent>();
    //         if (CheckCollisionCircles(
    //             playerPosition->position_, 
    //             playerHealth->health_, 
    //             zombiePosition->position_, 
    //             zombieSound->currentRadius / 2
    //         )) {
    //             // SET increased value of adrenaline
    //             IncreaseAdrenaline(adrenalin);
    //         }
    //     }
    // }
    // // TODO: When adrenalin should be increased?
    // //   - seeing a zombi
    // //   - low hp more adrenalin
    
    // if (adrenalin->current_ < adrenalin->min_) {
    //     IncreaseAdrenaline(adrenalin);
    // } else {
    //     DecreaseAdrenaline(adrenalin);
    // }

}

