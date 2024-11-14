#include "MovementsScene.h"

void MovementsScene::Init() {
    // Scene entity
    Scene::AddEntity(Tools::CreateScene(
        Config::GAME_TITLE,
        Scene::title_
    ));

    int mapIndex = 1;
    std::vector<std::vector<int>> spawnMap = MovementsSceneMaps::GetSpawnMap(mapIndex);
    std::vector<std::vector<int>> wallsMap = MovementsSceneMaps::GetWallsMap(mapIndex);

    // Map entity
    Entity *mapEntity = Tools::CreateMap(
        spawnMap,
        wallsMap,
        Config::MAP_CELL_WIDTH,
        Config::MAP_CELL_HEIGHT
    );
    Scene::AddEntity(mapEntity);

    // Player Entity
    Scene::AddEntity(
        Tools::CreatePlayerForStepMoveSystem(
            Tools::GetPlayerSpawnPositionFromMap(mapEntity)
        )
    );
    
    GenerateMapEntities(mapEntity, spawnMap, wallsMap);
    // Systems
    // Map systems
    // Scene::AddSystem(new TerrainDrawSystem);
    
    
    // Player systems
    // Scene::AddSystem(new PlayerControlSystem);
    Scene::AddSystem(new PlayerCameraSystem);
    Scene::AddSystem(new PlayerDirectionSystem);
    
    // WARNING! UNDER CONSTRUCTION!
    Scene::AddSystem(new PlayerBodySystem);
    Scene::AddSystem(new PlayerLeftFootSystem);
    Scene::AddSystem(new PlayerRightFootSystem);
    // Scene::AddSystem(new PlayerStepSystem);
    // Scene::AddSystem(new PlayerFeetToBodyRelativeSystem);

    // Scene::AddSystem(new PlayerBreathSystem);
    // Scene::AddSystem(new PlayerAdrenalinSystem);
    // // Collider systems
    // Scene::AddSystem(new CircleCircleColliderSystem);
    // Scene::AddSystem(new CircleRectangleColliderSystem);
    // Scene::AddSystem(new ColliderResolverSystem);


    // Init Systems
    for (auto& system : systems_) {
        if (system == nullptr) {
            continue;
        }
        system->Init(&entities_);
    }
}

void MovementsScene::Update(int *currentSceneIndex) {
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

void MovementsScene::Draw() {
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


void MovementsScene::GenerateMapEntities(Entity *mapEntity, std::vector<std::vector<int>> spawnMap, std::vector<std::vector<int>> wallsMap) {
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
                Scene::AddEntity(Tools::CreateZombie(
                    PositionComponent(pos),
                    TargetComponent(pos),
                    HealthComponent(Config::ZOMBIE_HEALTH)
                ));
            }
            // Walls spawn point
            if (wallsMap[y][x] == 1) {
                Vector2 pos = (Vector2) {
                    (x * Config::MAP_CELL_WIDTH),
                    (y * Config::MAP_CELL_HEIGHT)
                };
                
                Scene::AddEntity(Tools::CreateWall(
                    PositionComponent(pos), 
                    HealthComponent(Config::DEFAULT_WALL_HEALTH),
                    RectangleColliderComponent(
                        Config::MAP_CELL_WIDTH,
                        Config::MAP_CELL_HEIGHT
                    )
                ));
            }
        }
    }
}