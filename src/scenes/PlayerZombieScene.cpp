#include "PlayerZombieScene.h"

void PlayerZombieScene::Init() {
    
    // Scene title
    SceneTools::CreateScene(Config::GAME_TITLE, Scene::title_, this);

    // Entities
    Scene::AddEntity(MapTools::CreateTerrain(this));
    Scene::AddEntity(SceneTools::CreatePlayer(
        (Vector2){Config::PLAYER_SPAWN_POSITION_X, Config::PLAYER_SPAWN_POSITION_Y},
        Config::PLAYER_HEALTH,
        Config::PLAYER_STRENGTH,
        Config::PLAYER_AGILITY,
        Config::PLAYER_ATTACK_RADIUS,
        Config::SOUND_MAX_RADIUS
    ));
    Scene::AddEntity(SceneTools::CreateZombie(
        (Vector2){Config::ZOMBIE_SPAWN_POSITION_X,Config::ZOMBIE_SPAWN_POSITION_Y},
        (Vector2){Config::ZOMBIE_DEFAULT_TARGET_POSITION_X, Config::ZOMBIE_DEFAULT_TARGET_POSITION_X},
        Config::ZOMBIE_HEALTH,
        Config::ZOMBIE_STRENGTH,
        Config::ZOMBIE_AGILITY,
        Config::ZOMBIE_ATTACK_RADIUS,
        Config::SOUND_MAX_RADIUS
    ));

    // Systems
    // UI Draw systems
    // Scene::AddSystem(new UIDrawSystem());
    // Map systems
    Scene::AddSystem(new TerrainDrawSystem);
    // Player systems
    Scene::AddSystem(new PlayerDrawSystem);
    Scene::AddSystem(new PlayerControlSystem);
    // Scene::AddSystem(new SceneControlSystem);
    
    // Zombie systems
    Scene::AddSystem(new ZombieDrawSystem);
    Scene::AddSystem(new ZombieMoveSystem);
    Scene::AddSystem(new ZombieTargetingSystem);
    

    // Init Systems
    for (auto& system : systems_) {
        if (system == nullptr) {
            continue;
        }
        system->Init(&entities_);
    }
}

void PlayerZombieScene::Update(int *currentSceneIndex) {
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

void PlayerZombieScene::Draw() {
    if (continue_) {
        for (auto& system : systems_) {
            if (system == nullptr) {
                continue;
            }
            system->Draw(&entities_);
        }
    }
}