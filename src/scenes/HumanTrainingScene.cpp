#include "HumanTrainingScene.h"

void HumanTrainingScene::Init() {
    Scene::AddEntity(SceneTools::CreateScene(
        Config::GAME_TITLE,
        Scene::title_
    ));
    Scene::AddSystem(new UIDrawSystem());

    // Entities
    // Scene::AddEntity(SceneTools::SpawnPlayer());
    // Scene::AddEntity(SceneTools::SpawnZombie());
    // SpawnHumanInPosWithStatus(50.0f, 100.0f, HumanComponent::Status::ATTACK);
    // SpawnHumanInPosWithStatus(150.0f, 100.0f, HumanComponent::Status::IDLE);
    // SpawnHumanInPosWithStatusAndTarget(250.0f, 100.0f, HumanComponent::Status::RUN, 250.0f, 400.0f);
    // SpawnHumanInPosWithStatusAndTarget(150.0f, 100.0f, HumanComponent::Status::RUN, 150.0f, 400.0f);
    // SpawnHumanInPosWithStatusAndTarget(350.0f, 100.0f, HumanComponent::Status::RUN, 350.0f, 400.0f);
    // SpawnHumanInPosWithStatus(450.0f, 100.0f, HumanComponent::Status::SLEEP);
    // SpawnLoot();

    // Systems
    // Scene::AddSystem(new HumanStaminaSystem());
    // Scene::AddSystem(new HumanMoveSystem());
    // Scene::AddSystem(new HumanTargetingSystem());
    // Scene::AddSystem(new HumanDrawSystem());

    // Scene::AddSystem(new LootRandomSeedSystem());
    // Scene::AddSystem(new HumanBreathSystem());
    // Scene::AddSystem(new HumanPhysiologicalSystem());

    // Scene::AddSystem(new LootDrawSystem());

    // Init Systems
    for (auto& system : systems_) {
        if (system == nullptr) {
            continue;
        }
        system->Init(&entities_);
    }
}

void HumanTrainingScene::Update(int *currentSceneIndex) {
    if (continue_) {
        for (auto& system : systems_) {
            if (system == nullptr) {
                continue;
            }
            system->Update(&entities_);
        }
        HandleExit(currentSceneIndex);
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
