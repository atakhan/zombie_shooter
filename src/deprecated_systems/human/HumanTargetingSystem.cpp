#include "HumanTargetingSystem.h"

void HumanTargetingSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Human targeting System Initialized" << std::endl;
}

void HumanTargetingSystem::Draw(std::vector<Entity*> *entities) {}

void HumanTargetingSystem::Update(std::vector<Entity*> *entities) {
    for (auto& entity : *entities) {
        if (entity == nullptr) {
            std::cerr << "Entity pointer is null!" << std::endl;
            continue;
        }
        if (!entity->HasComponent<HumanComponent>()) {
            continue;
        }
        HumanComponent* human = entity->GetComponent<HumanComponent>();
        TargetComponent* target = entity->GetComponent<TargetComponent>();
        PositionComponent* humanPos = entity->GetComponent<PositionComponent>();
        StaminaComponent* stamina = entity->GetComponent<StaminaComponent>();

        if (target->active_) {
            if (TargetReached(target->position_, humanPos->position_)) {
                target->active_ = false;
            }
        } else {
            target->position_ = FindTarget(human, entities);
            target->active_ = true;
        }

        if (stamina->currentValue_ > (stamina->maxValue_ / 2) && human->currentStatus == HumanComponent::Status::IDLE) {
            human->currentStatus = HumanComponent::Status::WALK;
            target->position_ = FindTarget(human, entities);
            target->active_ = true;
        }
    }
}

Vector2 HumanTargetingSystem::FindTarget(HumanComponent *human,std::vector<Entity*> *entities) {
    for (auto& entity : *entities) {
        if (entity->HasComponent<LootComponent>()) {
            PositionComponent* lootPos = entity->GetComponent<PositionComponent>();
            return lootPos->position_;
        }
    }
    return RandomTarget();
}

bool HumanTargetingSystem::TargetReached(Vector2 targetPos, Vector2 curPos) {
    float distanceX = targetPos.x - curPos.x;
    float distanceY = targetPos.y - curPos.y;
    float distance = std::sqrt(std::pow(distanceX, 2) + std::pow(distanceY, 2));
    
    if (Config::HUMAN_MOVE_TRESHOLD >= distance) {
        return true;
    }
    return false;
}

Vector2 HumanTargetingSystem::RandomTarget() {
    int min = 10;
    int xmax = Config::WINDOW_WIDTH;
    int ymax = Config::WINDOW_HEIGHT;
    int randX = rand()%(xmax-min + 1) + min;
    int randY = rand()%(ymax-min + 1) + min;

    return (Vector2){static_cast<float>(randX), static_cast<float>(randY)};
}
