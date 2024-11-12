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
}

void PlayerStepSystem::Update(std::vector<Entity*> *entities) {
    using namespace std;
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    if (player == nullptr) { return; }

    PlayerComponent *playerComponent = player->GetComponent<PlayerComponent>();
    DirectionComponent *playerDirection = player->GetComponent<DirectionComponent>();
    LeftFootComponent *leftFoot = player->GetComponent<LeftFootComponent>();
    RightFootComponent *rightFoot = player->GetComponent<RightFootComponent>();
    PlayerBodyComponent *body = player->GetComponent<PlayerBodyComponent>();

    if (!body || !leftFoot || !rightFoot || !playerDirection)
    { return; }

    float collisionRadius = 10.0f;
    float stepValue = 40.0f;
    
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        WhoIsFirst(leftFoot, rightFoot, (leftFoot->pos_.x < rightFoot->pos_.x));
        MoveRight(leftFoot, rightFoot, collisionRadius, stepValue);
    }
    else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
        WhoIsFirst(leftFoot, rightFoot, (leftFoot->pos_.x < rightFoot->pos_.x));
        MoveLeft(leftFoot, rightFoot, collisionRadius, stepValue);
    }
    else if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
        WhoIsFirst(leftFoot, rightFoot, (leftFoot->pos_.y < rightFoot->pos_.y));
        MoveUp(leftFoot, rightFoot, collisionRadius, stepValue);
    }
    else if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
        WhoIsFirst(leftFoot, rightFoot, (leftFoot->pos_.y < rightFoot->pos_.y));
        MoveDown(leftFoot, rightFoot, collisionRadius, stepValue);
    }
    else {
        Idle(leftFoot, rightFoot, playerComponent, collisionRadius);
    }
}

void PlayerStepSystem::WhoIsFirst(LeftFootComponent *leftFoot, RightFootComponent *rightFoot, bool leftFirst) {
    if (!leftFoot->moving_ && !rightFoot->moving_) {
        if (leftFirst) {
            leftFoot->moving_ = true;
        } else {
            rightFoot->moving_ = true;
        }
    }
}

void PlayerStepSystem::MoveRight(LeftFootComponent *leftFoot, RightFootComponent *rightFoot, float collisionRadius, float stepValue) {
    MoveLeftFoot(
        leftFoot, rightFoot,
        (leftFoot->pos_.x > leftFoot->goalPosition_.x),
        {leftFoot->idlePos_.x + stepValue, leftFoot->idlePos_.y}
    );
    MoveRightFoot(
        leftFoot, rightFoot,
        (rightFoot->pos_.x > rightFoot->goalPosition_.x),
        {rightFoot->idlePos_.x + stepValue, rightFoot->idlePos_.y}
    );
}

void PlayerStepSystem::MoveLeft(LeftFootComponent *leftFoot, RightFootComponent *rightFoot, float collisionRadius, float stepValue) {
    MoveLeftFoot(
        leftFoot, rightFoot,
        (leftFoot->pos_.x < leftFoot->goalPosition_.x),
        {leftFoot->idlePos_.x - stepValue, leftFoot->idlePos_.y}
    );
    MoveRightFoot(
        leftFoot, rightFoot, 
        (rightFoot->pos_.x < rightFoot->goalPosition_.x),
        {rightFoot->idlePos_.x - stepValue, rightFoot->idlePos_.y}
    );
}

void PlayerStepSystem::MoveUp(LeftFootComponent *leftFoot, RightFootComponent *rightFoot, float collisionRadius, float stepValue) {
    MoveLeftFoot(
        leftFoot, rightFoot,
        (leftFoot->pos_.y < leftFoot->goalPosition_.y),
        {leftFoot->idlePos_.x, leftFoot->idlePos_.y - stepValue}
    );
    MoveRightFoot(
        leftFoot, rightFoot,
        (rightFoot->pos_.y < rightFoot->goalPosition_.y),
        {rightFoot->idlePos_.x, rightFoot->idlePos_.y - stepValue}
    );
}

void PlayerStepSystem::MoveDown(LeftFootComponent *leftFoot, RightFootComponent *rightFoot, float collisionRadius, float stepValue) {
    MoveLeftFoot(
        leftFoot, rightFoot,
        (leftFoot->pos_.y > leftFoot->goalPosition_.y),
        {leftFoot->idlePos_.x, leftFoot->idlePos_.y + stepValue}
    );
    MoveRightFoot(
        leftFoot, rightFoot,
        (rightFoot->pos_.y > rightFoot->goalPosition_.y),
        {rightFoot->idlePos_.x, rightFoot->idlePos_.y + stepValue}
    );
}

void PlayerStepSystem::MoveLeftFoot(LeftFootComponent *leftFoot, RightFootComponent *rightFoot, bool condition, Vector2 newGoalPos) {
    if (leftFoot->moving_) {
        if (condition) {
            leftFoot->goalPosition_ = newGoalPos;
            leftFoot->idlePos_ = leftFoot->goalPosition_;
            leftFoot->moving_ = false;
            rightFoot->moving_ = true;
        } else {
            rightFoot->moving_ = false;
        }
    }
}

void PlayerStepSystem::MoveRightFoot(LeftFootComponent *leftFoot, RightFootComponent *rightFoot, bool condition, Vector2 newGoalPos) {
    if (rightFoot->moving_) {
        if (condition) {
            rightFoot->goalPosition_ = newGoalPos;
            rightFoot->idlePos_ = rightFoot->goalPosition_;
            rightFoot->moving_ = false;
            leftFoot->moving_ = true;
        } else {
            leftFoot->moving_ = false;
        }
    }
}

void PlayerStepSystem::Idle(LeftFootComponent* leftFoot, RightFootComponent* rightFoot, PlayerComponent* player, float collisionRadius) {
    leftFoot->pos_ = leftFoot->idlePos_;
    rightFoot->pos_ = rightFoot->idlePos_;
    player->currentState_ = PlayerComponent::IDLE;
    // leftFoot->moving_ = false;
    if (leftFoot->moving_) {
        if (!CheckCollisionCircles(leftFoot->pos_, collisionRadius, leftFoot->goalPosition_, collisionRadius)) {
            if (!CheckCollisionCircles(leftFoot->pos_, collisionRadius, leftFoot->idlePos_, collisionRadius)) {
                leftFoot->pos_.x -= 60.0f * GetFrameTime();
            } else {
                leftFoot->moving_ = false;
                leftFoot->pos_ = leftFoot->idlePos_;
            }
        }
    }
    if (rightFoot->moving_) {
        if (!CheckCollisionCircles(rightFoot->pos_, collisionRadius, rightFoot->goalPosition_, collisionRadius)) {
            if (!CheckCollisionCircles(rightFoot->pos_, collisionRadius, rightFoot->idlePos_, collisionRadius)) {
                rightFoot->pos_.x -= 60.0f * GetFrameTime();
            } else {
                rightFoot->moving_ = false;
                rightFoot->pos_ = rightFoot->idlePos_;
            }
        }
    }
}
