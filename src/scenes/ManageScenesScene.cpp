#include "ManageScenesScene.h"

void ManageScenesScene::Init() {
    Scene::continue_ = true;
    // Scene title
    Scene::AddEntity(SceneTools::InitGameComponent("Choose Scene"));
    Scene::AddSystem(new GameTitleSceneTitleDrawSystem);

    // Zombie systems
    for (auto& system : systems_) {
        if (system == nullptr) {
            std::cerr << "System pointer is null!" << std::endl;
            continue;
        }
        system->Init(&entities_);
    }
}

void ManageScenesScene::Update() {
    // Exit scene
    if (IsKeyDown(KEY_Q)) {
        Scene::continue_ = false;
    }
    for (auto& system : systems_) {
        if (system == nullptr) {
            std::cerr << "System pointer is null!" << std::endl;
            continue;
        }
        system->Update(&entities_);
    }
}

void ManageScenesScene::Draw() {
    for (auto& system : systems_) {
        if (system == nullptr) {
            std::cerr << "System pointer is null!" << std::endl;
            continue;
        }
        system->Draw(&entities_);
    }
}
