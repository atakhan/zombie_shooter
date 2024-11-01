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
            
            if (human->isAlive_ == false) {
                continue;
            }
            if (human->isTargetReached_ == false) {
                continue;
            }

            if (human->currentStatus_ == HumanComponent::Status::WALK) {
                MoveTo(human, Config::HUMAN_WALK_COEF);
            } else
            if (human->currentStatus_ == HumanComponent::Status::RUN) {
                MoveTo(human, Config::HUMAN_RUN_COEF);
            } else {
                MoveTo(human, 0.0f);
            }
        }
    }
}

void HumanMoveSystem::MoveTo(HumanComponent *human, float speedCoef) {
    float distanceX = human->target_.x - human->position_.x;
    float distanceY = human->target_.y - human->position_.y;
    float distance = std::sqrt(std::pow(distanceX, 2) + std::pow(distanceY, 2));

    if (1.0f < distance) {
        Vector2 direction = { distanceX / distance, distanceY / distance };
        human->position_.x += direction.x * speedCoef;
        human->position_.y += direction.y * speedCoef;
        // std::cout << "Moving towards target: (" << curPos->position_.x << ", " << curPos->position_.y << ")" << std::endl;
    }
}
