#include "PlayerZombieScene.h"

void PlayerZombieScene::Init() {
    // Scene title
    Scene::AddEntity(SceneTools::InitGameComponent("Player Zombie Scene"));
    Scene::AddSystem(new GameTitleSceneTitleDrawSystem);

    // Entities
    Scene::AddEntity(SceneTools::SpawnPlayer());
    Scene::AddEntity(SceneTools::SpawnZombie());

    // Systems
    // Player systems
    Scene::AddSystem(new PlayerDrawSystem);
    Scene::AddSystem(new PlayerControlSystem);
    // Zombie systems
    Scene::AddSystem(new ZombieDrawSystem);
    Scene::AddSystem(new ZombieMoveSystem);
    Scene::AddSystem(new ZombieTargetingSystem);

    for (auto& system : systems_) {
        if (system == nullptr) {
            std::cerr << "System pointer is null!" << std::endl;
            continue;
        }
        system->Init(&entities_);
    }
}

void PlayerZombieScene::Update() {
    for (auto& system : systems_) {
        if (system == nullptr) {
            std::cerr << "System pointer is null!" << std::endl;
            continue;
        }
        system->Update(&entities_);
    }
}

void PlayerZombieScene::Draw() {
    for (auto& system : systems_) {
        if (system == nullptr) {
            std::cerr << "System pointer is null!" << std::endl;
            continue;
        }
        system->Draw(&entities_);
    }
}
