#include "HumanTrainingScene.h"

void HumanTrainingScene::Init() {
    // SpawnHumanInPosWithStatus(50.0f, 100.0f, HumanComponent::Status::ATTACK);
    // SpawnHumanInPosWithStatus(150.0f, 100.0f, HumanComponent::Status::IDLE);
    // SpawnHumanInPosWithStatusAndTarget(250.0f, 100.0f, HumanComponent::Status::RUN, 250.0f, 400.0f);
    // SpawnHumanInPosWithStatusAndTarget(150.0f, 100.0f, HumanComponent::Status::RUN, 150.0f, 400.0f);
    // SpawnHumanInPosWithStatusAndTarget(350.0f, 100.0f, HumanComponent::Status::RUN, 350.0f, 400.0f);
    // SpawnHumanInPosWithStatus(450.0f, 100.0f, HumanComponent::Status::SLEEP);
    // SpawnLoot();
    Scene::AddEntity(SceneTools::InitGameComponent("Human Training Scene"));
    // Entities
    Scene::AddEntity(SceneTools::SpawnPlayer());
    Scene::AddEntity(SceneTools::SpawnZombie());

    // Systems
    Scene::AddSystem(new PlayerDrawSystem);
    Scene::AddSystem(new PlayerControlSystem);
    Scene::AddSystem(new ZombieDrawSystem);
    Scene::AddSystem(new ZombieMoveSystem);
    Scene::AddSystem(new ZombieTargetingSystem);

    // Scene::AddSystem(new HumanStaminaSystem());
    // Scene::AddSystem(new HumanMoveSystem());
    // Scene::AddSystem(new HumanTargetingSystem());
    // Scene::AddSystem(new HumanDrawSystem());

    // Scene::AddSystem(new LootRandomSeedSystem());
    // Scene::AddSystem(new HumanBreathSystem());
    // Scene::AddSystem(new HumanPhysiologicalSystem());

    // Scene::AddSystem(new LootDrawSystem());


    for (auto& system : systems_) {
        if (system == nullptr) {
            std::cerr << "System pointer is null!" << std::endl;
            continue;
        }
        system->Init(&entities_);
    }
}

void HumanTrainingScene::Update() {
    for (auto& system : systems_) {
        if (system == nullptr) {
            std::cerr << "System pointer is null!" << std::endl;
            continue;
        }
        system->Update(&entities_);
    }
}

void HumanTrainingScene::Draw() {
    for (auto& system : systems_) {
        if (system == nullptr) {
            std::cerr << "System pointer is null!" << std::endl;
            continue;
        }
        system->Draw(&entities_);
    }
}
