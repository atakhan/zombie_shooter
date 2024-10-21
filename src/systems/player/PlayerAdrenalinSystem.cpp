#include "PlayerAdrenalinSystem.h"
#include <iostream>

void PlayerAdrenalinSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Player Adrenalin System Initialized" << std::endl;
}

void PlayerAdrenalinSystem::Draw(std::vector<Entity*> *entities) {
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    if (player == nullptr) { return; }
    PositionComponent *playerPosition = player->GetComponent<PositionComponent>();
    AdrenalinComponent *adrenalin = player->GetComponent<AdrenalinComponent>();
    DrawRectangle(playerPosition->position_.x, playerPosition->position_.y, adrenalin->max_, adrenalin->min_, RED_3_4);
    DrawRectangle(playerPosition->position_.x, playerPosition->position_.y, adrenalin->current_, adrenalin->min_, RED_3_8);
}

void PlayerAdrenalinSystem::Update(std::vector<Entity*> *entities) {
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    if (player == nullptr) { return; }

    PositionComponent *playerPosition = player->GetComponent<PositionComponent>();
    HealthComponent *playerHealth = player->GetComponent<HealthComponent>();
    AdrenalinComponent *adrenalin = player->GetComponent<AdrenalinComponent>();

    if (!playerPosition || !playerHealth || !adrenalin) { return; }

    // If adrenalin is changable
    if (adrenalin->min_ < adrenalin->current_ && adrenalin->current_ < adrenalin->max_) {
        //   - hearing a zombi
        for (auto& entity : *entities) {
            if (entity == nullptr) { continue; }
            if (entity->HasComponent<ZombieComponent>()) {
                PositionComponent *zombiePosition = entity->GetComponent<PositionComponent>();
                SoundComponent *zombieSound = entity->GetComponent<SoundComponent>();
                if (CheckCollisionCircles(
                    playerPosition->position_, 
                    playerHealth->health_, 
                    zombiePosition->position_, 
                    zombieSound->currentRadius
                )) {
                    // SET increased value of adrenaline 
                    IncreaseAdrenaline(adrenalin);
                }
            }
        }
        // TODO: When adrenalin should be increased?
        //   - seeing a zombi
        //   - low hp more adrenalin
    
    } else {
        DecreaseAdrenaline(adrenalin);
    }
    
    // DEFAULT ACTION ON EACH ADRENALIN ITERATION
    // SET decreased value of adrenaline 
    DecreaseAdrenaline(adrenalin);

}

void PlayerAdrenalinSystem::DecreaseAdrenaline(AdrenalinComponent *adrenalin) {
    adrenalin->current_ = adrenalin->current_ - adrenalin->step_;
}
void PlayerAdrenalinSystem::IncreaseAdrenaline(AdrenalinComponent *adrenalin) {
    adrenalin->current_ = adrenalin->current_ + adrenalin->step_;
}
