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
    SpeedComponent *speed = player->GetComponent<SpeedComponent>();
    PlayerBodyComponent *body = player->GetComponent<PlayerBodyComponent>();

    if (!body || !leftFoot || !rightFoot || !playerDirection || !speed)
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
        {leftFoot->idlePos_.x + stepValue, leftFoot->idlePos_.y}, 
        {leftFoot->pos_.x + (60.0f * GetFrameTime()), leftFoot->pos_.y}
    );
    MoveRightFoot(
        leftFoot, rightFoot,
        (rightFoot->pos_.x > rightFoot->goalPosition_.x),
        {rightFoot->idlePos_.x + stepValue, rightFoot->idlePos_.y}, 
        {rightFoot->pos_.x + (60.0f * GetFrameTime()), rightFoot->pos_.y}
    );
}

void PlayerStepSystem::MoveLeft(LeftFootComponent *leftFoot, RightFootComponent *rightFoot, float collisionRadius, float stepValue) {
    MoveLeftFoot(
        leftFoot, rightFoot,
        (leftFoot->pos_.x < leftFoot->goalPosition_.x),
        {leftFoot->idlePos_.x - stepValue, leftFoot->idlePos_.y}, 
        {leftFoot->pos_.x - (60.0f * GetFrameTime()), leftFoot->pos_.y}
    );
    MoveRightFoot(
        leftFoot, rightFoot, 
        (rightFoot->pos_.x < rightFoot->goalPosition_.x),
        {rightFoot->idlePos_.x - stepValue, rightFoot->idlePos_.y}, 
        {rightFoot->pos_.x - (60.0f * GetFrameTime()), rightFoot->pos_.y}
    );
}

void PlayerStepSystem::MoveUp(LeftFootComponent *leftFoot, RightFootComponent *rightFoot, float collisionRadius, float stepValue) {
    MoveLeftFoot(
        leftFoot, rightFoot,
        (leftFoot->pos_.y < leftFoot->goalPosition_.y),
        {leftFoot->idlePos_.x, leftFoot->idlePos_.y - stepValue},
        {leftFoot->pos_.x, leftFoot->pos_.y - (60.0f * GetFrameTime())}
    );
    MoveRightFoot(
        leftFoot, rightFoot,
        (rightFoot->pos_.y < rightFoot->goalPosition_.y),
        {rightFoot->idlePos_.x, rightFoot->idlePos_.y - stepValue},
        {rightFoot->pos_.x, rightFoot->pos_.y - (60.0f * GetFrameTime())}
    );
}

void PlayerStepSystem::MoveDown(LeftFootComponent *leftFoot, RightFootComponent *rightFoot, float collisionRadius, float stepValue) {
    MoveLeftFoot(
        leftFoot, rightFoot,
        (leftFoot->pos_.y > leftFoot->goalPosition_.y),
        {leftFoot->idlePos_.x, leftFoot->idlePos_.y + stepValue}, 
        {leftFoot->pos_.x, leftFoot->pos_.y + (60.0f * GetFrameTime())}
    );
    MoveRightFoot(
        leftFoot, rightFoot,
        (rightFoot->pos_.y > rightFoot->goalPosition_.y),
        {rightFoot->idlePos_.x, rightFoot->idlePos_.y + stepValue},
        {rightFoot->pos_.x, rightFoot->pos_.y + (60.0f * GetFrameTime())}
    );
}

void PlayerStepSystem::MoveLeftFoot(
    LeftFootComponent *leftFoot, 
    RightFootComponent *rightFoot, 
    bool condition, 
    Vector2 newGoalPos, 
    Vector2 newPos
) {
    if (leftFoot->moving_) {
        if (condition) {
            leftFoot->goalPosition_ = newGoalPos;
            leftFoot->idlePos_ = leftFoot->goalPosition_;
            leftFoot->moving_ = false;
            rightFoot->moving_ = true;
        } else {
            leftFoot->pos_ = newPos;
            leftFoot->idlePos_ = newPos;
            rightFoot->moving_ = false;
        }
    }
}

void PlayerStepSystem::MoveRightFoot(
    LeftFootComponent *leftFoot, 
    RightFootComponent *rightFoot, 
    bool condition, 
    Vector2 newGoalPos, 
    Vector2 newPos
) {
    if (rightFoot->moving_) {
        if (condition) {
            rightFoot->goalPosition_ = newGoalPos;
            rightFoot->idlePos_ = rightFoot->goalPosition_;
            leftFoot->moving_ = true;
            rightFoot->moving_ = false;
        } else {
            rightFoot->pos_ = newPos;
            rightFoot->idlePos_ = newPos;
            leftFoot->moving_ = false;
        }
    }
}

void PlayerStepSystem::Idle(LeftFootComponent* leftFoot, RightFootComponent* rightFoot, PlayerComponent* player, float collisionRadius) {
    player->currentState_ = PlayerComponent::IDLE;
    if (leftFoot->moving_) {
        leftFoot->goalPosition_ = leftFoot->idlePos_;
    }
    if (rightFoot->moving_) {
        rightFoot->goalPosition_ = rightFoot->idlePos_;
    }
}
