#include "PlayerDirectionSystem.h"
#include <iostream>

void PlayerDirectionSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "PlayerDirectionSystem Initialized" << std::endl;
}

void PlayerDirectionSystem::Draw(std::vector<Entity*> *entities) {
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    if (player == nullptr) { return; }
    FeetComponent *feet = player->GetComponent<FeetComponent>();
    PositionComponent *position = player->GetComponent<PositionComponent>();
    HealthComponent *health = player->GetComponent<HealthComponent>();
    DirectionComponent *direction = player->GetComponent<DirectionComponent>();
    DrawCircleV(direction->mousePos_, 5.0f, BLUE_3_8);
    DrawLineV(position->position_, direction->mousePos_, BLUE_3_8);
}

void PlayerDirectionSystem::Update(std::vector<Entity*> *entities) {
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    if (player == nullptr) { return; }
    
    PositionComponent *playerPosition = player->GetComponent<PositionComponent>();
    HealthComponent *playerHealth = player->GetComponent<HealthComponent>();
    FeetComponent *feet = player->GetComponent<FeetComponent>();
    CameraComponent *camera = player->GetComponent<CameraComponent>();
    DirectionComponent *direction = player->GetComponent<DirectionComponent>();

    if (!playerPosition || !playerHealth || !feet) { return; }

    direction->mousePos_ = GetScreenToWorld2D(GetMousePosition(), camera->camera_);

    // feet->leftPosition_ = (Vector2) {
    //     playerPosition->position_.x + (playerHealth->health_ / 4),
    //     playerPosition->position_.y + (playerHealth->health_ / 4)
    // };
    // feet->rightPosition_ = (Vector2) {
    //     playerPosition->position_.x - (playerHealth->health_ / 4),
    //     playerPosition->position_.y - (playerHealth->health_ / 4)
    // };
    // feet->leftRadius_ = playerHealth->health_ / 3;
    // feet->rightRadius_ = playerHealth->health_ / 3;

    // Vector2 pointA = playerPosition->position_;
    // Vector2 pointB = GetMousePosition();
    
    // float pointsList[] = {
    //     pointA.x,
    //     pointA.y,
    //     pointB.x,
    //     pointB.y
    // };
    // float maxValue = *std::max_element(
    //     std::begin(pointsList), 
    //     std::end(pointsList)
    // );
    // float minValue = *std::min_element(
    //     std::begin(pointsList), 
    //     std::end(pointsList)
    // );

    // Vector2 vectA = {
    //     MapTools::NormalizeToRange(pointA.x, minValue, maxValue),
    //     MapTools::NormalizeToRange(pointA.y, minValue, maxValue)
    // };

    // Vector2 vectB = {
    //     MapTools::NormalizeToRange(pointB.x, minValue, maxValue),
    //     MapTools::NormalizeToRange(pointB.y, minValue, maxValue)
    // };
    
    // direction->rotation_ = MapTools::AngleBetweenVectors(vectA, vectB);
}

