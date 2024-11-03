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

void PlayerFeetMoveSystem::Update(std::vector<Entity*> *entities) {
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    if (player == nullptr) { return; }
    
    PositionComponent *playerPosition = player->GetComponent<PositionComponent>();
    HealthComponent *playerHealth = player->GetComponent<HealthComponent>();
    FeetComponent *feet = player->GetComponent<FeetComponent>();
    DirectionComponent *direction = player->GetComponent<DirectionComponent>();
    SpeedComponent *speed = player->GetComponent<SpeedComponent>();

    if (!playerPosition || !playerHealth || !feet || !direction || !speed) { return; }
    
    if (feet->stepping_ == false) {
        SetDefaultPosition(feet, playerHealth, playerPosition);
    }

    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        MoveRight(feet, playerPosition, direction);
        feet->stepping_ = true;
    }

    if (IsKeyReleased(KEY_RIGHT) || IsKeyReleased(KEY_D)) {
        feet->stepping_ = false;
    }
}

void PlayerFeetMoveSystem::SetDefaultPosition(FeetComponent* feet, HealthComponent *playerHealth, PositionComponent *playerPosition) {
    float coef = 2.0f;
    feet->left_.width = playerHealth->health_ * coef;
    feet->left_.height = (playerHealth->health_ / 2.0f) * coef;
    
    float footVelocity = 3.0f;
    if (feet->left_.x < playerPosition->position_.x) {
        feet->left_.x = feet->left_.x + footVelocity;
    }
    if (feet->left_.x > playerPosition->position_.x) {
        feet->left_.x = feet->left_.x - footVelocity;
    }
    if (feet->left_.y < playerPosition->position_.y) {
        feet->left_.y = feet->left_.y + footVelocity;
    }
    if (feet->left_.y > playerPosition->position_.y) {
        feet->left_.y = feet->left_.y - footVelocity;
    }
    
    feet->right_.width = (playerHealth->health_) * coef;
    feet->right_.height = (playerHealth->health_ / 2.0f) * coef; 
    feet->right_.x = playerPosition->position_.x;
    feet->right_.y = playerPosition->position_.y;
}

void PlayerFeetMoveSystem::SetRotationCenter(FeetComponent* feet) {
    // Определяем координаты углов
    Vector2 corners[4];
    // Верхний левый угол
    corners[0] = { 0.0f, 0.0f };
    // Верхний правый угол
    corners[1] = { 0.0f + feet->left_.width, 0.0f }; 
    // Нижний правый угол
    corners[2] = { 0.0f + feet->left_.width, 0.0f + feet->left_.height }; 
    // Нижний левый угол
    corners[3] = { 0.0f, 0.0f + feet->left_.height }; 

    // Вычисляем новый центр вращения (например, центр прямоугольника)
    Vector2 rotationOrigin_center = { (corners[0].x + corners[2].x) / 2, (corners[0].y + corners[2].y) / 2 };
    Vector2 rotationOrigin_topLeft = corners[0];
    Vector2 rotationOrigin_topRight = corners[1];
    Vector2 rotationOrigin_bottomRight = corners[2];
    Vector2 rotationOrigin_bottomLeft = corners[3];
    Vector2 rotationOrigin_bottomCenter = { (corners[0].x + corners[2].x) / 2, corners[0].y};
    Vector2 rotationOrigin_topCenter = { (corners[0].x + corners[2].x) / 2, (corners[0].y + corners[2].y) };
    
    feet->leftOrigin_ = rotationOrigin_bottomCenter;
    feet->rightOrigin_ = rotationOrigin_topCenter;
}

void PlayerFeetMoveSystem::Idle(SoundComponent *sound) {}

void PlayerFeetMoveSystem::MoveRight(FeetComponent *feet, PositionComponent *body, DirectionComponent *direction) {
    // body->position_.x = body->position_.x + 10.0f;
    feet->left_.x = feet->left_.x + 1.0f;
}

void PlayerFeetMoveSystem::MoveLeft(SoundComponent *sound, PositionComponent *position, SpeedComponent *speed) {
    position->position_.x = position->position_.x - speed->speed_;
}

void PlayerFeetMoveSystem::MoveTop(SoundComponent *sound, PositionComponent *position, SpeedComponent *speed) {
    position->position_.y = position->position_.y - speed->speed_;
}

void PlayerFeetMoveSystem::MoveBottom(SoundComponent *sound, PositionComponent *position, SpeedComponent *speed) {
    position->position_.y = position->position_.y + speed->speed_;
}

