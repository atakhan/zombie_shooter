#include "PlayerRightFootSystem.h"
#include <iostream>

void PlayerRightFootSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "PlayerRightFootSystem System Initialized" << std::endl;
}

void PlayerRightFootSystem::Draw(std::vector<Entity*> *entities) {
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    if (player == nullptr) { return; }
    
    RightFootComponent *rightFoot = player->GetComponent<RightFootComponent>();

    if (rightFoot) {
        DrawCircleV(rightFoot->pos_, rightFoot->radius_, RED);
        DrawCircleV(rightFoot->goalPosition_, 4.0f, YELLOW);
    }
}

void PlayerRightFootSystem::Update(std::vector<Entity*> *entities) {
    
    using namespace std;
    
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    
    if (player == nullptr) { return; }

    RightFootComponent *foot = player->GetComponent<RightFootComponent>();
    PlayerBodyComponent *body = player->GetComponent<PlayerBodyComponent>();

    if (!foot && !body) { return; }

    MoveFromBody(foot, body);
    
    // if (foot->moving_) {
    //     if (GoalReached(foot)) {
    //         foot->moving_ = false;
    //     } else {
    //         MoveToGoal(foot);
    //     }
    // }

}

bool PlayerRightFootSystem::GoalReached(RightFootComponent *foot) {
    if (CheckCollisionPointCircle(foot->goalPosition_, foot->pos_, foot->radius_)) {
        return true;
    }
    return false;
}

void PlayerRightFootSystem::MoveToGoal(RightFootComponent *foot) {
    Vector2 newPos = {
        foot->goalPosition_.x,
        foot->goalPosition_.y
    };
    
    foot->pos_ = newPos;
}

void PlayerRightFootSystem::MoveFromBody(RightFootComponent *foot, PlayerBodyComponent *body) {
    Vector2 newPos = {
        body->pos_.x + 21.0f,
        body->pos_.y
    };
    
    foot->pos_ = newPos;
}
