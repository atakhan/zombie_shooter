#include "PlayerStepSystem.h"
#include <iostream>

void PlayerStepSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "PlayerFeetMove System Initialized" << std::endl;
}

void PlayerStepSystem::Draw(std::vector<Entity*> *entities) {
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    if (player == nullptr) { return; }
    
    LeftFootComponent *leftFoot = player->GetComponent<LeftFootComponent>();
    RightFootComponent *rightFoot = player->GetComponent<RightFootComponent>();
    DirectionComponent *direction = player->GetComponent<DirectionComponent>();
    HealthComponent *health = player->GetComponent<HealthComponent>();
    PositionComponent *playerPosition = player->GetComponent<PositionComponent>();

    if (leftFoot) {        
        DrawCircle(leftFoot->pos_.x, leftFoot->pos_.y, leftFoot->radius_, BLUE);
        DrawCircle(rightFoot->pos_.x, rightFoot->pos_.y, leftFoot->radius_, VIOLET);
        // DrawCircle(leftFoot->bone_.x, leftFoot->bone_.y, 10.0f, BLUE);
        // DrawRectanglePro(rightFoot->bone_, rightFoot->origin_, rightFoot->rotation_, GREEN);
        // DrawCircleV(leftFoot->goalPosition_, 5.0f, YELLOW);
    }

    // !TODO: exclude this procedure to own system?
    // DRAW PLAYER BODY 
    if (playerPosition && health) {
        DrawCircleV(playerPosition->position_, 5.0f, RED);
    }
}

void PlayerStepSystem::Update(std::vector<Entity*> *entities) {
    using namespace std;
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    if (player == nullptr) { return; }

    PlayerComponent *playerComponent = player->GetComponent<PlayerComponent>();
    DirectionComponent *playerDirection = player->GetComponent<DirectionComponent>();
    PositionComponent *playerPosition = player->GetComponent<PositionComponent>();
    HealthComponent *playerHealth = player->GetComponent<HealthComponent>();
    LeftFootComponent *leftFoot = player->GetComponent<LeftFootComponent>();
    RightFootComponent *rightFoot = player->GetComponent<RightFootComponent>();
    SpeedComponent *speed = player->GetComponent<SpeedComponent>();

    if (!playerPosition || !playerHealth || !leftFoot || !rightFoot || !playerDirection || !speed)
    { return; }
    
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        cout << "key right pressed" << endl;
    } else
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
        cout << "key left pressed" << endl;
    } else
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
        cout << "key up pressed" << endl;
    } else
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
        cout << "key down pressed" << endl;
    } else {
        Idle(leftFoot, rightFoot, playerComponent);
    }
}

void PlayerStepSystem::Idle(LeftFootComponent* leftFoot, RightFootComponent* rightFoot, PlayerComponent* player) {
    leftFoot->pos_ = leftFoot->idlePos_;
    rightFoot->pos_ = rightFoot->idlePos_;
    player->currentState_ = PlayerComponent::IDLE;
    // leftFoot->moving_ = false;
}

void PlayerStepSystem::MoveRight(PositionComponent *playerPosition, LeftFootComponent *leftFoot, RightFootComponent *rightFoot) {
    Move(leftFoot, playerPosition);
    float stepSize = 10.0f;
    if (CheckCollisionPointCircle(leftFoot->goalPosition_, leftFoot->pos_, leftFoot->radius_)) {
        leftFoot->goalPosition_ = {
            leftFoot->goalPosition_.x + stepSize,
            leftFoot->goalPosition_.y
        };
    }
}

void PlayerStepSystem::MoveLeft(SoundComponent *sound, PositionComponent *position, SpeedComponent *speed) {
    position->position_.x = position->position_.x - speed->speed_;
}

void PlayerStepSystem::MoveTop(SoundComponent *sound, PositionComponent *position, SpeedComponent *speed) {
    position->position_.y = position->position_.y - speed->speed_;
}

void PlayerStepSystem::MoveBottom(SoundComponent *sound, PositionComponent *position, SpeedComponent *speed) {
    position->position_.y = position->position_.y + speed->speed_;
}

void PlayerStepSystem::Move(LeftFootComponent *leftFoot, PositionComponent *playerPosition) {
    float moveVelocity = 1.0f;
    if (leftFoot->pos_.x < leftFoot->goalPosition_.x) {
        leftFoot->pos_.x = leftFoot->pos_.x + moveVelocity;
        // playerPosition->position_.x = playerPosition->position_.x + (moveVelocity/2);
    }
    if (leftFoot->pos_.x > leftFoot->goalPosition_.x) {
        leftFoot->pos_.x = leftFoot->pos_.x - moveVelocity;
        // playerPosition->position_.x = playerPosition->position_.x - (moveVelocity/2);
    }
    if (leftFoot->pos_.y < leftFoot->goalPosition_.y) {
        leftFoot->pos_.y = leftFoot->pos_.y + moveVelocity;
        // playerPosition->position_.y = playerPosition->position_.y + (moveVelocity/2);
    }
    if (leftFoot->pos_.y > leftFoot->goalPosition_.y) {
        leftFoot->pos_.y = leftFoot->pos_.y - moveVelocity;
        // playerPosition->position_.y = playerPosition->position_.y - (moveVelocity/2);
    }
}