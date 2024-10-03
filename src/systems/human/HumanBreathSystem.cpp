#include "HumanBreathSystem.h"

void HumanBreathSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Human breath System Initialized" << std::endl;
}

void HumanBreathSystem::Draw(std::vector<Entity*> *entities) {}

void HumanBreathSystem::Update(std::vector<Entity*> *entities) {
    for (auto& entity : *entities) {
        if (entity == nullptr) {
            std::cerr << "Entity pointer is null!" << std::endl;
            continue;
        }
        if (entity->HasComponent<HumanComponent>()) {
            HumanComponent* human = entity->GetComponent<HumanComponent>();
            if (human->isAlive) {
                std::cout << "Human is alive!.." << std::endl;
                TargetComponent* target = entity->GetComponent<TargetComponent>();
                PositionComponent* humanPos = entity->GetComponent<PositionComponent>();
                HumanPhysiologicalComponent* physiology = entity->GetComponent<HumanPhysiologicalComponent>();
                HumanBreathComponent* humanBreath = entity->GetComponent<HumanBreathComponent>();


                if (humanBreath->inhale) {
                    MakeInhale(humanBreath, physiology);
                    IncreaseAirValue(physiology, human->currentStatus);
                } else {
                    MakeExhale(humanBreath, physiology);
                    // DecreaseAirValue(physiology, human->currentStatus);
                }

                // Human dies
                if (physiology->air_ < Config::HUMAN_PHYSIOLOGY_EPS) {
                    human->isAlive = false;
                }
            }
        }
    }
}

void HumanBreathSystem::MakeExhale(HumanBreathComponent* humanBreath, HumanPhysiologicalComponent *physiology) {
    std::cout << "<-- exhale.." << std::endl;
    // humanBreath->inhaleValue = humanBreath->inhaleValue - Config::HUMAN_PHYSIOLOGY_EPS;
    if (humanBreath->inhaleValue < Config::HUMAN_PHYSIOLOGY_EPS) {
        humanBreath->inhale = true;
    }
}
void HumanBreathSystem::MakeInhale(HumanBreathComponent* humanBreath, HumanPhysiologicalComponent *physiology) {
    std::cout << "--> inhale.." << std::endl;
    humanBreath->inhaleValue = humanBreath->inhaleValue + humanBreath->inhaleValue;
    if (humanBreath->inhaleValue > humanBreath->lungsCapacity) {
        humanBreath->inhale = false;
    }
}

void HumanBreathSystem::DecreaseAirValue(HumanPhysiologicalComponent *physiology, HumanComponent::Status currentStatus) {
    float newAirValue = physiology->air_;

    if (currentStatus == HumanComponent::Status::SLEEP) newAirValue -= (Config::HUMAN_PHYSIOLOGY_EPS);
    if (currentStatus == HumanComponent::Status::IDLE) newAirValue -= (Config::HUMAN_PHYSIOLOGY_EPS * 2);
    if (currentStatus == HumanComponent::Status::LOOT) newAirValue -= (Config::HUMAN_PHYSIOLOGY_EPS * 3);
    if (currentStatus == HumanComponent::Status::WALK) newAirValue -= (Config::HUMAN_PHYSIOLOGY_EPS * 4);
    if (currentStatus == HumanComponent::Status::RUN) newAirValue -= (Config::HUMAN_PHYSIOLOGY_EPS * 8);
    if (currentStatus == HumanComponent::Status::ATTACK) newAirValue -= (Config::HUMAN_PHYSIOLOGY_EPS * 10);

    physiology->air_ = newAirValue;
}

void HumanBreathSystem::IncreaseAirValue(HumanPhysiologicalComponent *physiology, HumanComponent::Status currentStatus) {
    float newAirValue = physiology->air_;

    if (currentStatus == HumanComponent::Status::SLEEP) newAirValue += (Config::HUMAN_PHYSIOLOGY_EPS * 200);
    if (currentStatus == HumanComponent::Status::IDLE) newAirValue += (Config::HUMAN_PHYSIOLOGY_EPS * 160);
    if (currentStatus == HumanComponent::Status::LOOT) newAirValue += (Config::HUMAN_PHYSIOLOGY_EPS * 80);
    if (currentStatus == HumanComponent::Status::WALK) newAirValue += (Config::HUMAN_PHYSIOLOGY_EPS * 60);
    if (currentStatus == HumanComponent::Status::RUN) newAirValue += (Config::HUMAN_PHYSIOLOGY_EPS * 40);
    if (currentStatus == HumanComponent::Status::ATTACK) newAirValue += (Config::HUMAN_PHYSIOLOGY_EPS * 10);

    physiology->air_ = newAirValue;
}