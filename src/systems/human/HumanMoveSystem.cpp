#include "HumanMoveSystem.h"

void HumanMoveSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Human move System Initialized" << std::endl;
}

void HumanMoveSystem::Draw(std::vector<Entity*> *entities) {}

void HumanMoveSystem::Update(std::vector<Entity*> *entities) {
    for (auto& entity : *entities) {
        if (entity == nullptr) {
            std::cerr << "Entity pointer is null!" << std::endl;
            continue;
        }
        if (entity->HasComponent<HumanComponent>()) {
            HumanComponent* human = entity->GetComponent<HumanComponent>();
            PositionComponent* humanPos = entity->GetComponent<PositionComponent>();
            TargetComponent* target = entity->GetComponent<TargetComponent>();
            
            if (human->isAlive==false || humanPos==nullptr || target==nullptr || target->active_==false) {
                continue;
            }

            if (human->currentStatus == HumanComponent::Status::WALK) {
                MoveTo(target, humanPos, Config::HUMAN_WALK_SPEED);
            } else
            if (human->currentStatus == HumanComponent::Status::RUN) {
                MoveTo(target, humanPos, Config::HUMAN_RUN_SPEED);
            } else {
                MoveTo(target, humanPos, 0.0f);
            }
        }
    }
}

void HumanMoveSystem::MoveTo(TargetComponent *targetPos, PositionComponent *curPos, float speed) {
    float distanceX = targetPos->position_.x - curPos->position_.x;
    float distanceY = targetPos->position_.y - curPos->position_.y;
    float distance = std::sqrt(std::pow(distanceX, 2) + std::pow(distanceY, 2));

    if (Config::HUMAN_MOVE_TRESHOLD < distance) {
        Vector2 direction = { distanceX / distance, distanceY / distance };
        curPos->position_.x += direction.x * speed;
        curPos->position_.y += direction.y * speed;
        // std::cout << "Moving towards target: (" << curPos->position_.x << ", " << curPos->position_.y << ")" << std::endl;
    }
}
