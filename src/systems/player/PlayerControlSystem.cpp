#include "PlayerControlSystem.h"
#include <iostream>

void PlayerControlSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Player Control System Initialized" << std::endl;
}

void PlayerControlSystem::Draw(std::vector<Entity*> *entities) {
    for (auto& entity : *entities) {
        if (entity == nullptr) { continue; }
        
        if (entity->HasComponent<PlayerComponent>()) {                
            PositionComponent *position = entity->GetComponent<PositionComponent>();
            HealthComponent *health = entity->GetComponent<HealthComponent>();
            
            if (position && health) {
                DrawCircle(
                    position->position_.x,
                    position->position_.y,
                    health->health_,
                    R7G7B0A3
                );
            }

            break;
        }
    }
}

void PlayerControlSystem::Update(std::vector<Entity*> *entities) {
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    if (player == nullptr) { return; }

    PositionComponent *position = player->GetComponent<PositionComponent>();
    SpeedComponent *speed = player->GetComponent<SpeedComponent>();
    SoundComponent *sound = player->GetComponent<SoundComponent>();

    if (!position || !speed || !sound) { return; }

    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
            Idle(sound);
        } else {
            if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
                MoveRight(sound, position, speed);
                MoveTop(sound, position, speed);
            } else
            if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
                MoveRight(sound, position, speed);
                MoveBottom(sound, position, speed);
            } else {
                MoveRight(sound, position, speed);
            }
        }
    } else
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
            Idle(sound);
        } else {
            if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W) ) {
                MoveLeft(sound, position, speed);
                MoveTop(sound, position, speed);
            } else
            if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
                MoveLeft(sound, position, speed);
                MoveBottom(sound, position, speed);
            } else {
                MoveLeft(sound, position, speed);
            }
        }
    } else
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
        if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
            Idle(sound);
        } else {
            if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
                MoveTop(sound, position, speed);
                MoveRight(sound, position, speed);
            } else
            if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
                MoveTop(sound, position, speed);
                MoveLeft(sound, position, speed);
            } else {
                MoveTop(sound, position, speed);
            }
        }
    } else
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
        if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
            Idle(sound);
        } else {
            if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
                MoveBottom(sound, position, speed);
                MoveRight(sound, position, speed);
            } else
            if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
                MoveBottom(sound, position, speed);
                MoveLeft(sound, position, speed);
            } else {
                MoveBottom(sound, position, speed);
            }
        }
    } else {
        Idle(sound);
    }
}

void PlayerControlSystem::IncreaseSoundRadius(SoundComponent *sound) {
    if (sound->currentRadius < sound->maxRadius) {
        sound->currentRadius = sound->currentRadius + Config::SOUND_RADIUS_STEP;
    }
}

void PlayerControlSystem::DecreaseSoundRadius(SoundComponent *sound) {
    if (sound->currentRadius > sound->minRadius) {
        sound->currentRadius = sound->currentRadius - Config::SOUND_RADIUS_STEP;
    }
}

void PlayerControlSystem::Idle(SoundComponent *sound) {
    DecreaseSoundRadius(sound);
}

void PlayerControlSystem::MoveRight(SoundComponent *sound, PositionComponent *position, SpeedComponent *speed) {
    position->position_.x = position->position_.x + speed->speed_;
    IncreaseSoundRadius(sound);
}

void PlayerControlSystem::MoveLeft(SoundComponent *sound, PositionComponent *position, SpeedComponent *speed) {
    position->position_.x = position->position_.x - speed->speed_;
    IncreaseSoundRadius(sound);
}

void PlayerControlSystem::MoveTop(SoundComponent *sound, PositionComponent *position, SpeedComponent *speed) {
    position->position_.y = position->position_.y - speed->speed_;
    IncreaseSoundRadius(sound);
}

void PlayerControlSystem::MoveBottom(SoundComponent *sound, PositionComponent *position, SpeedComponent *speed) {
    position->position_.y = position->position_.y + speed->speed_;
    IncreaseSoundRadius(sound);
}


