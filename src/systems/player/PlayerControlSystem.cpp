#include "PlayerControlSystem.h"
#include <iostream>

void PlayerControlSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Player Control System Initialized" << std::endl;
}

void PlayerControlSystem::Draw(std::vector<Entity*> *entities) {}

void PlayerControlSystem::Update(std::vector<Entity*> *entities) {
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    if (player == nullptr) { return; }

    PositionComponent *position = player->GetComponent<PositionComponent>();
    SpeedComponent *speed = player->GetComponent<SpeedComponent>();
    SoundComponent *sound = player->GetComponent<SoundComponent>();

    if (!position || !speed || !sound) { return; }

    if (IsKeyDown(KEY_RIGHT)) {
        if (IsKeyDown(KEY_LEFT)) {
            Idle(sound);
        } else {
            if (IsKeyDown(KEY_UP)) {
                MoveRight(sound, position, speed);
                MoveTop(sound, position, speed);
            } else
            if (IsKeyDown(KEY_DOWN)) {
                MoveRight(sound, position, speed);
                MoveBottom(sound, position, speed);
            } else {
                MoveRight(sound, position, speed);
            }
        }
    } else
    if (IsKeyDown(KEY_LEFT)) {
        if (IsKeyDown(KEY_RIGHT)) {
            Idle(sound);
        } else {
            if (IsKeyDown(KEY_UP)) {
                MoveLeft(sound, position, speed);
                MoveTop(sound, position, speed);
            } else
            if (IsKeyDown(KEY_DOWN)) {
                MoveLeft(sound, position, speed);
                MoveBottom(sound, position, speed);
            } else {
                MoveLeft(sound, position, speed);
            }
        }
    } else
    if (IsKeyDown(KEY_UP)) {
        if (IsKeyDown(KEY_DOWN)) {
            Idle(sound);
        } else {
            if (IsKeyDown(KEY_RIGHT)) {
                MoveTop(sound, position, speed);
                MoveRight(sound, position, speed);
            } else
            if (IsKeyDown(KEY_LEFT)) {
                MoveTop(sound, position, speed);
                MoveLeft(sound, position, speed);
            } else {
                MoveTop(sound, position, speed);
            }
        }
    } else
    if (IsKeyDown(KEY_DOWN)) {
        if (IsKeyDown(KEY_UP)) {
            Idle(sound);
        } else {
            if (IsKeyDown(KEY_RIGHT)) {
                MoveBottom(sound, position, speed);
                MoveRight(sound, position, speed);
            } else
            if (IsKeyDown(KEY_LEFT)) {
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


