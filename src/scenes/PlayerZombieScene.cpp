#include "PlayerZombieScene.h"

void PlayerZombieScene::Init() {
    // Scene title
    Scene::AddEntity(SceneTools::CreateScene(
        Config::GAME_TITLE,
        Scene::title_
    ));

    // ui entities
    Scene::AddEntity(UiTools::CreateUIEntity(
        (Vector2){10.0f, 10.0f},
        Config::GAME_TITLE,
        16.0f, 1, 1, 3.0f, RED
    ));
    Scene::AddEntity(UiTools::CreateUIEntity(
        (Vector2){10.0f, 10.0f},
        this->title_,
        16.0f, 1, 2, 3.0f, RED
    ));

    // Entities
    Scene::AddEntity(MapTools::CreateTerrain(
        this->width_,
        this->height_,
        Config::MAP_CELL_WIDTH,
        Config::MAP_CELL_HEIGHT
    ));

    Scene::AddEntity(SceneTools::CreatePlayer(
        (Vector2){Config::PLAYER_SPAWN_POSITION_X, Config::PLAYER_SPAWN_POSITION_Y},
        Config::PLAYER_HEALTH,
        Config::PLAYER_STRENGTH,
        Config::PLAYER_AGILITY,
        Config::PLAYER_ATTACK_RADIUS,
        Config::SOUND_MAX_RADIUS
    ));

    for (size_t i = 0; i < Config::ZOMBIES_COUNT; i++) {
        Scene::AddEntity(SceneTools::CreateZombie(
            (Vector2){Config::ZOMBIE_SPAWN_POSITION_X, Config::ZOMBIE_SPAWN_POSITION_Y},
            (Vector2){Config::ZOMBIE_DEFAULT_TARGET_POSITION_X, Config::ZOMBIE_DEFAULT_TARGET_POSITION_X},
            Config::ZOMBIE_HEALTH,
            Config::ZOMBIE_STRENGTH,
            Config::ZOMBIE_AGILITY,
            Config::ZOMBIE_ATTACK_RADIUS,
            Config::SOUND_MAX_RADIUS
        ));
    }

    // Systems
    // Map systems
    Scene::AddSystem(new TerrainDrawSystem);
    // Zombie systems
    Scene::AddSystem(new ZombieDrawSystem);
    Scene::AddSystem(new ZombieMoveSystem);
    Scene::AddSystem(new ZombieTargetingSystem);
    // Player systems
    Scene::AddSystem(new PlayerDrawSystem);
    Scene::AddSystem(new PlayerControlSystem);
    Scene::AddSystem(new PlayerCameraSystem);
    // Collider systems
    Scene::AddSystem(new CircleCircleColliderSystem);
    Scene::AddSystem(new ColliderResolverSystem);
    
    // UI draw systems
    Scene::AddUISystem(new UIDrawSystem);

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
    if (!continue_) {
        return;
    }
    CameraComponent *camera = nullptr;
    PlayerComponent *player = nullptr;
    for (auto& entity : entities_) {
        if (entity->HasComponent<PlayerComponent>()) {
            player = entity->GetComponent<PlayerComponent>();
            if (entity->HasComponent<CameraComponent>()) {
                camera = entity->GetComponent<CameraComponent>();
                break;
            }
        }
    }

    if (player && camera) {
        BeginMode2D(camera->camera_);
        for (auto& system : systems_) {
            if (system == nullptr) {
                continue;
            }
            system->Draw(&entities_);
        }
        EndMode2D();

        for (auto& system : UISystems_) {
            if (system == nullptr) {
                continue;
            }
            system->Draw(&entities_);
        }
    }
}
