#include "PlayerZombieScene.h"
#include "PlayerZombieSceneMaps.h"

void PlayerZombieScene::Init() {
    // Scene entity
    Scene::AddEntity(SceneTools::CreateScene(
        Config::GAME_TITLE,
        Scene::title_
    ));

    int mapIndex = 1;
    std::vector<std::vector<int>> spawnMap = PlayerZombieSceneMaps::GetSpawnMap(mapIndex);
    std::vector<std::vector<int>> wallsMap = PlayerZombieSceneMaps::GetWallsMap(mapIndex);

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
    
    GenerateMapEntities(mapEntity, spawnMap, wallsMap);

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
    // Zombie systems
    Scene::AddSystem(new ZombieMoveSystem);
    Scene::AddSystem(new ZombieTargetingSystem);
    
    // Player systems
    Scene::AddSystem(new PlayerControlSystem);
    Scene::AddSystem(new PlayerCameraSystem);
    Scene::AddSystem(new PlayerBreathSystem);
    Scene::AddSystem(new PlayerAdrenalinSystem);
    Scene::AddSystem(new PlayerFeetMoveSystem);
    
    // Collider systems
    Scene::AddSystem(new CircleCircleColliderSystem);
    Scene::AddSystem(new CircleRectangleColliderSystem);
    Scene::AddSystem(new ColliderResolverSystem);
    
    // Draw systems
    Scene::AddSystem(new TerrainDrawSystem);
    Scene::AddSystem(new ZombieDrawSystem);
    Scene::AddSystem(new PlayerDrawSystem);

    // Debug systems
    // Scene::AddSystem(new SoundDrawSystem);
    // Scene::AddSystem(new TargetDrawSystem);
    // Scene::AddSystem(new ZombieStatsDrawSystem);
    
    // UI draw systems
    // Scene::AddUISystem(new DebugUIDrawSystem);
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


void PlayerZombieScene::GenerateMapEntities(Entity *mapEntity, std::vector<std::vector<int>> spawnMap, std::vector<std::vector<int>> wallsMap) {
    TerrainComponent *terrain = mapEntity->GetComponent<TerrainComponent>();
    if (!terrain) {
        return;
    }
    // Zombie and Walls entities
    for (size_t y = 0; y < terrain->height_; y++) {
        for (size_t x = 0; x < terrain->width_; x++) {
            // Zombie spawn point
            if (spawnMap[y][x] == 2) {
                Vector2 pos = (Vector2) {
                    (x * Config::MAP_CELL_WIDTH) + (Config::MAP_CELL_WIDTH / 2),
                    (y * Config::MAP_CELL_HEIGHT) + (Config::MAP_CELL_HEIGHT / 2)
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
            // Walls spawn point
            if (wallsMap[y][x] == 1) {
                Vector2 pos = (Vector2) {
                    (x * Config::MAP_CELL_WIDTH),
                    (y * Config::MAP_CELL_HEIGHT)
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