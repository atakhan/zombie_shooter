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
            if (human->isAlive) {
                TargetComponent* target = entity->GetComponent<TargetComponent>();
                PositionComponent* humanPos = entity->GetComponent<PositionComponent>();
                HumanPhysiologicalComponent* physiology = entity->GetComponent<HumanPhysiologicalComponent>();
                
                if (human->currentStatus == HumanComponent::Status::WALK 
                 || human->currentStatus == HumanComponent::Status::RUN) {
                    if (TargetNotReached(target->position_, humanPos->position_)) {
                        MoveTo(
                            physiology,
                            target, 
                            humanPos, 
                            &human->currentStatus,
                            GetSpeed(human->currentStatus)
                        );
                    } else {
                        human->currentStatus = HumanComponent::Status::IDLE;
                    }
                }
            }
        }
    }
}

bool HumanMoveSystem::TargetNotReached(Vector2 targetPos, Vector2 curPos) {
    float distanceX = targetPos.x - curPos.x;
    float distanceY = targetPos.y - curPos.y;
    float distance = std::sqrt(std::pow(distanceX, 2) + std::pow(distanceY, 2));
    
    if (Config::HUMAN_MOVE_TRESHOLD < distance) {
        return true;
    }
    return false;
}

float HumanMoveSystem::GetSpeed(HumanComponent::Status state) {
    if (state == HumanComponent::Status::WALK) return Config::HUMAN_WALK_SPEED;
    if (state == HumanComponent::Status::RUN) return Config::HUMAN_RUN_SPEED;
    return 2.1f;
}

void HumanMoveSystem::MoveTo(HumanPhysiologicalComponent *physiology, TargetComponent *targetPos, PositionComponent *curPos, HumanComponent::Status *state, float speed) {
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
