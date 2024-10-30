#include "PlayerFeetMoveSystem.h"
#include <iostream>

void PlayerFeetMoveSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "PlayerFeetMove System Initialized" << std::endl;
}

void PlayerFeetMoveSystem::Draw(std::vector<Entity*> *entities) {
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    if (player == nullptr) { return; }
    FeetComponent *feet = player->GetComponent<FeetComponent>();
    DirectionComponent *direction = player->GetComponent<DirectionComponent>();
    HealthComponent *health = player->GetComponent<HealthComponent>();

    if (feet && direction && health) {
        DrawRectanglePro(feet->left_, feet->leftOrigin_, direction->rotation_, BLUE);
        DrawRectanglePro(feet->right_, feet->rightOrigin_, direction->rotation_, ORANGE);
    }
}

bool PlayerFeetMoveSystem::NeedRotate(FeetComponent *feet, DirectionComponent *direction) {
    std::cout << "direction rotation_: " << direction->rotation_ << std::endl;
    std::cout << "direction mousePos: x:" << direction->mousePos_.x  << " y:" << direction->mousePos_.x << std::endl;
    std::cout << "feet->left_.x: " << feet->left_.x << std::endl;
    std::cout << "feet->left_.y: " << feet->left_.y << std::endl;
    std::cout << "==============================="<< std::endl;
    return true;
}

void PlayerFeetMoveSystem::MoveRight(FeetComponent *feet, PositionComponent *body, DirectionComponent *direction) {
    if (NeedRotate(feet, direction)) {

    }
    body->position_.x = body->position_.x + 0.0f;
    
    // IncreaseSoundRadius(sound);
}

void PlayerFeetMoveSystem::Update(std::vector<Entity*> *entities) {
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    if (player == nullptr) { return; }
    
    PositionComponent *playerPosition = player->GetComponent<PositionComponent>();
    HealthComponent *playerHealth = player->GetComponent<HealthComponent>();
    FeetComponent *feet = player->GetComponent<FeetComponent>();
    DirectionComponent *direction = player->GetComponent<DirectionComponent>();
    SpeedComponent *speed = player->GetComponent<SpeedComponent>();
    SoundComponent *sound = player->GetComponent<SoundComponent>();

    if (!playerPosition || !playerHealth || !feet || !direction || !speed || !sound) { return; }

    // Определяем координаты углов
    Vector2 corners[4];
    corners[0] = { 0.0f, 0.0f }; // Верхний левый угол
    corners[1] = { 0.0f + feet->left_.width, 0.0f }; // Верхний правый угол
    corners[2] = { 0.0f + feet->left_.width, 0.0f + feet->left_.height }; // Нижний правый угол
    corners[3] = { 0.0f, 0.0f + feet->left_.height }; // Нижний левый угол

    // Вычисляем новый центр вращения (например, центр прямоугольника)
    Vector2 rotationOrigin_center = { (corners[0].x + corners[2].x) / 2, (corners[0].y + corners[2].y) / 2 };
    Vector2 rotationOrigin_topLeft = corners[0];
    Vector2 rotationOrigin_topRight = corners[1];
    Vector2 rotationOrigin_bottomRight = corners[2];
    Vector2 rotationOrigin_bottomLeft = corners[3];

    Vector2 rotationOrigin_bottomCenter = { 
        (corners[0].x + corners[2].x) / 2, 
        corners[0].y
    };
    Vector2 rotationOrigin_topCenter = { 
        (corners[0].x + corners[2].x) / 2,
        (corners[0].y + corners[2].y)
    };

    float coef = 2.0f;
    feet->left_.width = playerHealth->health_ * coef;
    feet->left_.height = (playerHealth->health_ / 2.0f) * coef;
    feet->left_.x = playerPosition->position_.x;
    feet->left_.y = playerPosition->position_.y;
    
    feet->right_.width = (playerHealth->health_) * coef;
    feet->right_.height = (playerHealth->health_ / 2.0f) * coef; 
    feet->right_.x = playerPosition->position_.x;
    feet->right_.y = playerPosition->position_.y;

    feet->leftOrigin_ = rotationOrigin_bottomCenter;
    feet->rightOrigin_ = rotationOrigin_topCenter;

    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        MoveRight(feet, playerPosition, direction);
    }

    // if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
    //     if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
    //         Idle(sound);
    //     } else {
    //         if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
    //             MoveRight(sound, feet);
    //             MoveTop(sound, feet);
    //         } else
    //         if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
    //             MoveRight(sound, position, speed);
    //             MoveBottom(sound, position, speed);
    //         } else {
    //             MoveRight(sound, position, speed);
    //         }
    //     }
    // } else
    // if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
    //     if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
    //         Idle(sound);
    //     } else {
    //         if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W) ) {
    //             MoveLeft(sound, position, speed);
    //             MoveTop(sound, position, speed);
    //         } else
    //         if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
    //             MoveLeft(sound, position, speed);
    //             MoveBottom(sound, position, speed);
    //         } else {
    //             MoveLeft(sound, position, speed);
    //         }
    //     }
    // } else
    // if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
    //     if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
    //         Idle(sound);
    //     } else {
    //         if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
    //             MoveTop(sound, position, speed);
    //             MoveRight(sound, position, speed);
    //         } else
    //         if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
    //             MoveTop(sound, position, speed);
    //             MoveLeft(sound, position, speed);
    //         } else {
    //             MoveTop(sound, position, speed);
    //         }
    //     }
    // } else
    // if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
    //     if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
    //         Idle(sound);
    //     } else {
    //         if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
    //             MoveBottom(sound, position, speed);
    //             MoveRight(sound, position, speed);
    //         } else
    //         if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
    //             MoveBottom(sound, position, speed);
    //             MoveLeft(sound, position, speed);
    //         } else {
    //             MoveBottom(sound, position, speed);
    //         }
    //     }
    // } else {
    //     Idle(sound);
    // }
}

void PlayerFeetMoveSystem::IncreaseSoundRadius(SoundComponent *sound) {
    if (sound->currentRadius < sound->maxRadius) {
        sound->currentRadius = sound->currentRadius + Config::SOUND_RADIUS_STEP;
    }
}

void PlayerFeetMoveSystem::DecreaseSoundRadius(SoundComponent *sound) {
    if (sound->currentRadius > sound->minRadius) {
        sound->currentRadius = sound->currentRadius - Config::SOUND_RADIUS_STEP;
    }
}

void PlayerFeetMoveSystem::Idle(SoundComponent *sound) {
    DecreaseSoundRadius(sound);
}

void PlayerFeetMoveSystem::MoveLeft(SoundComponent *sound, PositionComponent *position, SpeedComponent *speed) {
    position->position_.x = position->position_.x - speed->speed_;
    IncreaseSoundRadius(sound);
}

void PlayerFeetMoveSystem::MoveTop(SoundComponent *sound, PositionComponent *position, SpeedComponent *speed) {
    position->position_.y = position->position_.y - speed->speed_;
    IncreaseSoundRadius(sound);
}

void PlayerFeetMoveSystem::MoveBottom(SoundComponent *sound, PositionComponent *position, SpeedComponent *speed) {
    position->position_.y = position->position_.y + speed->speed_;
    IncreaseSoundRadius(sound);
}

