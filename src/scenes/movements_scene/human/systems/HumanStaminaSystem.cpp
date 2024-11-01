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
            if (human->currentStatus_ == HumanComponent::Status::ATTACK) human->stamina_ -= 0.6f;
            if (human->currentStatus_ == HumanComponent::Status::IDLE) human->stamina_ += 0.1f;
            if (human->currentStatus_ == HumanComponent::Status::LOOT) human->stamina_ -= 0.2f;
            if (human->currentStatus_ == HumanComponent::Status::RUN) human->stamina_ -= 0.3f;
            if (human->currentStatus_ == HumanComponent::Status::SLEEP) human->stamina_ += 0.5f;
            if (human->currentStatus_ == HumanComponent::Status::WALK) human->stamina_ -= 0.1f;

            if (human->stamina_ >= human->staminaMaxValue_) {
                human->stamina_ = human->staminaMaxValue_;
            }

            if (human->currentStatus_ == HumanComponent::Status::RUN && human->stamina_ < (human->staminaMaxValue_ / 4)) {
                human->currentStatus_ = HumanComponent::Status::WALK;
            }
            if (human->stamina_ < (human->staminaMaxValue_ / 10)) {
                human->currentStatus_ = HumanComponent::Status::SLEEP;
            }
            if (human->currentStatus_ == HumanComponent::Status::SLEEP && human->stamina_ > ((human->staminaMaxValue_ / 100) * 85)) {
                human->currentStatus_ = HumanComponent::Status::IDLE;
            }
        }
    }
}
