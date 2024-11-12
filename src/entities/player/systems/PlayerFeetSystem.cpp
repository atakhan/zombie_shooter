#include "PlayerFeetSystem.h"
#include <iostream>

void PlayerFeetSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "PlayerFeetMove System Initialized" << std::endl;
}

void PlayerFeetSystem::Draw(std::vector<Entity*> *entities) {
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    if (player == nullptr) { return; }
    
    LeftFootComponent *leftFoot = player->GetComponent<LeftFootComponent>();
    RightFootComponent *rightFoot = player->GetComponent<RightFootComponent>();
    PlayerBodyComponent *playerBody = player->GetComponent<PlayerBodyComponent>();

    if (playerBody) {
        if (leftFoot) {
            DrawCircleV(leftFoot->pos_, leftFoot->radius_, leftFoot->color_);
            DrawCircleV(leftFoot->goalPosition_, 4.0f, leftFoot->color_);
            DrawLineV(leftFoot->pos_, playerBody->pos_, leftFoot->color_);
        }
        if (rightFoot) {
            DrawCircleV(rightFoot->pos_, leftFoot->radius_, rightFoot->color_);
            DrawCircleV(rightFoot->goalPosition_, 4.0f, rightFoot->color_);
            DrawLineV(rightFoot->pos_, playerBody->pos_, rightFoot->color_);
        }
    }
}

void PlayerFeetSystem::Update(std::vector<Entity*> *entities) {
    using namespace std;
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    if (player == nullptr) { return; }

    PlayerComponent *playerComponent = player->GetComponent<PlayerComponent>();
    PlayerBodyComponent *body = player->GetComponent<PlayerBodyComponent>();
    DirectionComponent *playerDirection = player->GetComponent<DirectionComponent>();
    LeftFootComponent *leftFoot = player->GetComponent<LeftFootComponent>();
    RightFootComponent *rightFoot = player->GetComponent<RightFootComponent>();

    // // Feet targeting logic
    // if (leftFoot && rightFoot) {
        
    //     float stepValue = 50.0f;
    //     float collisionRadius = 10.0f;

    //     if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
    //         LeftFoot(
    //             leftFoot, rightFoot,
    //             (bool)(leftFoot->pos_.x > leftFoot->goalPosition_.x),
    //             {leftFoot->idlePos_.x + stepValue, leftFoot->idlePos_.y}
    //         );
    //         RightFoot(
    //             leftFoot, rightFoot,
    //             (bool)(rightFoot->pos_.x > rightFoot->goalPosition_.x),
    //             {rightFoot->idlePos_.x + stepValue, rightFoot->idlePos_.y}
    //         );
    //     }

    //     else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
    //         LeftFoot(
    //             leftFoot, rightFoot,
    //             (bool)(leftFoot->pos_.x < leftFoot->goalPosition_.x),
    //             {leftFoot->idlePos_.x - stepValue, leftFoot->idlePos_.y}
    //         );
    //         RightFoot(
    //             leftFoot, rightFoot, 
    //             (bool)(rightFoot->pos_.x < rightFoot->goalPosition_.x),
    //             {rightFoot->idlePos_.x - stepValue, rightFoot->idlePos_.y}
    //         );
    //     }

    //     else if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
    //         LeftFoot(
    //             leftFoot, rightFoot,
    //             (bool)(leftFoot->pos_.y < leftFoot->goalPosition_.y),
    //             {leftFoot->idlePos_.x, leftFoot->idlePos_.y - stepValue}
    //         );
    //         RightFoot(
    //             leftFoot, rightFoot,
    //             (bool)(rightFoot->pos_.y < rightFoot->goalPosition_.y),
    //             {rightFoot->idlePos_.x, rightFoot->idlePos_.y - stepValue}
    //         );
    //     }

    //     else if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
    //         LeftFoot(
    //             leftFoot, rightFoot,
    //             (bool)(leftFoot->pos_.y > leftFoot->goalPosition_.y),
    //             {leftFoot->idlePos_.x, leftFoot->idlePos_.y + stepValue}
    //         );
    //         RightFoot(
    //             leftFoot, rightFoot,
    //             (bool)(rightFoot->pos_.y > rightFoot->goalPosition_.y),
    //             {rightFoot->idlePos_.x, rightFoot->idlePos_.y + stepValue}
    //         );
    //     } else {
    //         LeftFoot(
    //             leftFoot, rightFoot,
    //             (bool)(leftFoot->pos_.y > leftFoot->goalPosition_.y),
    //             leftFoot->goalPosition_
    //         );
    //         RightFoot(
    //             leftFoot, rightFoot,
    //             (bool)(rightFoot->pos_.y > rightFoot->goalPosition_.y),
    //             rightFoot->goalPosition_
    //         );
    //     }
    // }

    // // Move logic
    // if (leftFoot && rightFoot) {
    //     // move feet to the goal by comparing feet pos and goal pos
    //     if (leftFoot->moving_) {
    //         if (leftFoot->goalPosition_.x < leftFoot->pos_.x) {
    //             leftFoot->pos_.x -= 60.0f * GetFrameTime();
    //         }
    //         if (leftFoot->goalPosition_.x > leftFoot->pos_.x) {
    //             leftFoot->pos_.x += 60.0f * GetFrameTime();
    //         }
    //     }

    //     if (rightFoot->moving_) {
    //         if (rightFoot->goalPosition_.y < rightFoot->pos_.y) {
    //             rightFoot->pos_.y -= 60.0f * GetFrameTime();
    //         }
    //         if (rightFoot->goalPosition_.y > rightFoot->pos_.y) {
    //             rightFoot->pos_.y += 60.0f * GetFrameTime();
    //         }
    //     }
    // }
    
}

void PlayerFeetSystem::LeftFoot(LeftFootComponent *leftFoot, RightFootComponent *rightFoot, bool goalReached, Vector2 newGoalPos) {
    if (leftFoot->moving_) {
        if (goalReached) {
            leftFoot->goalPosition_ = newGoalPos;
            leftFoot->idlePos_ = leftFoot->goalPosition_;
            leftFoot->moving_ = false;
            rightFoot->moving_ = true;
        } else {
            rightFoot->moving_ = false;
        }
    }
}

void PlayerFeetSystem::RightFoot(LeftFootComponent *leftFoot, RightFootComponent *rightFoot, bool goalReached, Vector2 newGoalPos) {
    if (rightFoot->moving_) {
        if (goalReached) {
            rightFoot->goalPosition_ = newGoalPos;
            rightFoot->idlePos_ = rightFoot->goalPosition_;
            rightFoot->moving_ = false;
            leftFoot->moving_ = true;
        } else {
            leftFoot->moving_ = false;
        }
    }
}


