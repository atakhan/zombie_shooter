#include "PlayerZombieScene.h"

void PlayerZombieScene::Init() {
    // Scene entity
    Scene::AddEntity(SceneTools::CreateScene(
        Config::GAME_TITLE,
        Scene::title_
    ));

    // 0 - no spawns
    // 1 - spawn player
    // 2 - spawn zombie
    // 3 - spawn obstacle
    // 4 - spawn loot
    std::vector<std::vector<int>> spawnMap = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,1,0,0,0,0,2,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,2,0,0},
        {0,0,0,0,2,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,2,0,0},
        {0,0,0,2,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };
    std::vector<std::vector<int>> wallsMap = {
        {1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1}
    };

    // Map entity
    Entity *mapEntity = MapTools::CreateMap(
        spawnMap,
        wallsMap,
        Config::MAP_CELL_WIDTH,
        Config::MAP_CELL_HEIGHT
    );
    Scene::AddEntity(mapEntity);

    // Player entity
    Scene::AddEntity(SceneTools::CreatePlayer(
        MapTools::GetPlayerSpawnPositionFromMap(mapEntity),
        Config::PLAYER_HEALTH,
        Config::PLAYER_STRENGTH,
        Config::PLAYER_AGILITY,
        Config::PLAYER_ATTACK_RADIUS,
        Config::SOUND_MAX_RADIUS
    ));

    // Zombie entities
    TerrainComponent *terrain = mapEntity->GetComponent<TerrainComponent>();
    if (terrain) {
        for (size_t i = 0; i < terrain->height_; i++) {
            for (size_t j = 0; j < terrain->width_; j++) {
                // Zombie spawn point
                if (spawnMap[i][j] == 2) {
                    Vector2 pos = (Vector2) {
                        (i * Config::MAP_CELL_HEIGHT) + (Config::MAP_CELL_HEIGHT / 2),
                        (j * Config::MAP_CELL_WIDTH) + (Config::MAP_CELL_WIDTH / 2)
                    };
                    
                    Scene::AddEntity(SceneTools::CreateZombie(
                        PositionComponent(pos),
                        TargetComponent(pos),
                        HealthComponent(Config::ZOMBIE_HEALTH),
                        AttackComponent(Config::ZOMBIE_STRENGTH, Config::ZOMBIE_ATTACK_RADIUS),
                        SpeedComponent(Config::ZOMBIE_AGILITY),
                        SoundComponent(Config::SOUND_MAX_RADIUS)
                    ));
                }
                if (wallsMap[i][j] == 1) {
                    Vector2 pos = (Vector2) {
                        (i * Config::MAP_CELL_HEIGHT),
                        (j * Config::MAP_CELL_WIDTH)
                    };
                    
                    Scene::AddEntity(MapTools::CreateWall(
                        PositionComponent(pos), 
                        HealthComponent(Config::DEFAULT_WALL_HEALTH),
                        SoundReflectComponent({
                            {10, 100},
                            {20, 50},
                            {30, 10},
                        }),
                        RectangleColliderComponent(
                            Config::MAP_CELL_WIDTH,
                            Config::MAP_CELL_HEIGHT
                        )
                    ));
                }
            }
        }
    }

    // ui entities
    Scene::AddEntity(UiTools::CreateUITextEntity(
        (Vector2){10.0f, 10.0f},
        Config::GAME_TITLE,
        16.0f, 1, 1, 3.0f, RED
    ));
    Scene::AddEntity(UiTools::CreateUITextEntity(
        (Vector2){10.0f, 10.0f},
        Scene::title_,
        16.0f, 1, 2, 3.0f, RED
    ));

    // Systems
    // Map systems
    Scene::AddSystem(new TerrainDrawSystem);
    Scene::AddSystem(new WallsDrawSystem);
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
    Scene::AddSystem(new CircleRectangleColliderSystem);
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
