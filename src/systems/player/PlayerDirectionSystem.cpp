#include "PlayerDirectionSystem.h"
#include <iostream>

void PlayerDirectionSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "PlayerDirectionSystem Initialized" << std::endl;
    debug_ = false;
}

float NormalizeAngle(float angle) {
    while (angle > 180.0f) angle -= 360.0f;
    while (angle < -180.0f) angle += 360.0f;
    return angle;
}

void PlayerDirectionSystem::Draw(std::vector<Entity*> *entities) {
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    if (player == nullptr) { return; }
    
    FeetComponent *feet = player->GetComponent<FeetComponent>();
    PositionComponent *position = player->GetComponent<PositionComponent>();
    HealthComponent *health = player->GetComponent<HealthComponent>();
    DirectionComponent *direction = player->GetComponent<DirectionComponent>();
    
    DrawCircleV(direction->mousePos_, 5.0f, BLUE_3_8);
    DrawLineV(position->position_, direction->mousePos_, WHITE);
    
    float width = health->health_ * 2;
    float height = health->health_ / 4;

    Rectangle focusRec = {position->position_.x, position->position_.y, width, height};
    Vector2 focuesRecOrigin = {0.0f, height / 2};

    // Рисуем прямоугольник с текущим углом
    DrawRectanglePro(focusRec, focuesRecOrigin, direction->rotation_, RED);
}

void PlayerDirectionSystem::Update(std::vector<Entity*> *entities) {
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    if (player == nullptr) { return; }
    
    PositionComponent *playerPosition = player->GetComponent<PositionComponent>();
    HealthComponent *playerHealth = player->GetComponent<HealthComponent>();
    FeetComponent *feet = player->GetComponent<FeetComponent>();
    CameraComponent *camera = player->GetComponent<CameraComponent>();
    DirectionComponent *playerDirection = player->GetComponent<DirectionComponent>();

    if (!playerPosition || !playerHealth || !feet) { return; }

    Vector2 mousePos = GetScreenToWorld2D(GetMousePosition(), camera->camera_);
    float mousePosX = mousePos.x;
    float mousePosY = mousePos.y;

    // Вычисляем целевой угол
    float targetRotation = MapTools::AngleBetweenVectors({mousePosX, mousePosY}, playerPosition->position_);
    targetRotation = NormalizeAngle(targetRotation); // Нормализуем целевой угол

    // Плавное вращение с интерполяцией
    float rotationSpeed = 260.0f; // Скорость вращения
    float angleDifference = NormalizeAngle(targetRotation - playerDirection->rotation_);

    // Используем интерполяцию для плавного вращения
    if (fabs(angleDifference) < rotationSpeed * GetFrameTime()) {
        playerDirection->rotation_ = targetRotation; // Остановка на целевом угле
    } else {
        if (angleDifference > 0) {
            playerDirection->rotation_ += rotationSpeed * GetFrameTime();
        } else {
            playerDirection->rotation_ -= rotationSpeed * GetFrameTime();
        }
    }

    // Обновляем позицию мыши
    playerDirection->mousePos_ = {mousePosX, mousePosY};
}