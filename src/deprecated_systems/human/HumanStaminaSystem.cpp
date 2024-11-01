#include "HumanStaminaSystem.h"

void HumanStaminaSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Human stamina System Initialized" << std::endl;
}

void HumanStaminaSystem::Draw(std::vector<Entity*> *entities) {}

void HumanStaminaSystem::Update(std::vector<Entity*> *entities) {
    for (auto& entity : *entities) {
        if (entity == nullptr) {
            std::cerr << "Entity pointer is null!" << std::endl;
            continue;
        }
        if (entity->HasComponent<HumanComponent>()) {
            HumanComponent* human = entity->GetComponent<HumanComponent>();
            StaminaComponent* stamina = entity->GetComponent<StaminaComponent>();
            if (human->currentStatus == HumanComponent::Status::ATTACK) stamina->currentValue_ -= 0.6f;
            if (human->currentStatus == HumanComponent::Status::IDLE) stamina->currentValue_ += 0.1f;
            if (human->currentStatus == HumanComponent::Status::LOOT) stamina->currentValue_ -= 0.2f;
            if (human->currentStatus == HumanComponent::Status::RUN) stamina->currentValue_ -= 0.3f;
            if (human->currentStatus == HumanComponent::Status::SLEEP) stamina->currentValue_ += 0.5f;
            if (human->currentStatus == HumanComponent::Status::WALK) stamina->currentValue_ -= 0.1f;

            if (stamina->currentValue_ >= stamina->maxValue_) {
                stamina->currentValue_ = stamina->maxValue_;
            }

            if (human->currentStatus == HumanComponent::Status::RUN && stamina->currentValue_ < (stamina->maxValue_ / 4)) {
                human->currentStatus = HumanComponent::Status::WALK;
            }
            if (stamina->currentValue_ < (stamina->maxValue_ / 10)) {
                human->currentStatus = HumanComponent::Status::SLEEP;
            }
            if (human->currentStatus == HumanComponent::Status::SLEEP && stamina->currentValue_ > ((stamina->maxValue_ / 100) * 85)) {
                human->currentStatus = HumanComponent::Status::IDLE;
            }
        }
    }
}
