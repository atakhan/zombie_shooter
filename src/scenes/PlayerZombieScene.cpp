#include "PlayerZombieScene.h"

void PlayerZombieScene::Init() {
    
    // Scene title
    Scene::AddEntity(SceneTools::CreateScene(Config::GAME_TITLE, Scene::title_));
    Scene::AddEntity(UiTools::CreateUIEntity(
        (Vector2){10.0f, 10.0f},
        Config::GAME_TITLE,
        16.0f, 1, 1, 3.0f, RED
    ));
    Scene::AddEntity(UiTools::CreateUIEntity(
        (Vector2){10.0f, 10.0f},
        Scene::title_,
        16.0f, 1, 2, 3.0f, RED
    ));

    // Entities
    Scene::AddEntity(SceneTools::CreatePlayer(
        (Vector2){Config::PLAYER_SPAWN_POSITION_X, Config::PLAYER_SPAWN_POSITION_Y},
        Config::PLAYER_HEALTH,
        Config::PLAYER_STRENGTH,
        Config::PLAYER_AGILITY,
        Config::PLAYER_ATTACK_RADIUS,
        Config::SOUND_MAX_RADIUS
    ));
    // Scene::AddEntity(SceneTools::SpawnZombie());

    // Systems
    // UI Draw systems
    Scene::AddSystem(new UIDrawSystem());
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
    std::cout << "PlayerZombieScene UPDATE!" << std::endl;
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
