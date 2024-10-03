#include "HumanPhysiologicalSystem.h"

void HumanPhysiologicalSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Human physiological System Initialized" << std::endl;
}

void HumanPhysiologicalSystem::Draw(std::vector<Entity*> *entities) {}

void HumanPhysiologicalSystem::Update(std::vector<Entity*> *entities) {
    for (auto& entity : *entities) {
        if (entity == nullptr) {
            std::cerr << "Entity pointer is null!" << std::endl;
            continue;
        }
        if (entity->HasComponent<HumanComponent>()) {
            HumanComponent *human = entity->GetComponent<HumanComponent>();
            HumanPhysiologicalComponent *physiology = entity->GetComponent<HumanPhysiologicalComponent>();
            if (human->isAlive) {
                float newAirValue = physiology->air_;
                if (human->currentStatus == HumanComponent::Status::SLEEP) newAirValue -= (Config::HUMAN_PHYSIOLOGY_EPS);
                if (human->currentStatus == HumanComponent::Status::IDLE) newAirValue -= (Config::HUMAN_PHYSIOLOGY_EPS * 2);
                if (human->currentStatus == HumanComponent::Status::LOOT) newAirValue -= (Config::HUMAN_PHYSIOLOGY_EPS * 3);
                if (human->currentStatus == HumanComponent::Status::WALK) newAirValue -= (Config::HUMAN_PHYSIOLOGY_EPS * 4);
                if (human->currentStatus == HumanComponent::Status::RUN) newAirValue -= (Config::HUMAN_PHYSIOLOGY_EPS * 8);
                if (human->currentStatus == HumanComponent::Status::ATTACK) newAirValue -= (Config::HUMAN_PHYSIOLOGY_EPS * 10);

                physiology->air_ = newAirValue;

            }
        }
    }
}
