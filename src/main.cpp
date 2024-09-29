#include <raylib-cpp.hpp>

#include "Config.h"
#include "core/Game.h"
#include "core/Scene.h"
#include "components/AttackComponent.h"
#include "components/CameraComponent.h"
#include "components/CircleColliderComponent.h"
#include "components/HealthComponent.h"
#include "components/PositionComponent.h"
#include "components/SoundComponent.h"
#include "components/SpeedComponent.h"
#include "components/TargetComponent.h"
#include "systems/ZombieSystem.h"
#include "systems/PlayerSystem.h"
#include "systems/CameraSystem.h"

int main() {
    Game game;
    Scene scene = Scene();

    Entity player;
    player.AddComponent<HealthComponent>(
        HealthComponent(
            Config::PLAYER_HEALTH
        )
    );
    player.AddComponent<AttackComponent>(
        AttackComponent(
            Config::PLAYER_STRENGTH, 
            Config::PLAYER_ATTACK_RADIUS
        )
    );
    player.AddComponent<PositionComponent>(
        PositionComponent(
            Config::PLAYER_SPAWN_POSITION_X, 
            Config::PLAYER_SPAWN_POSITION_Y
        )
    );
    player.AddComponent<SpeedComponent>(
        SpeedComponent(
            Config::PLAYER_AGILITY
        )
    );
    player.AddComponent<SoundComponent>(
        SoundComponent(
            Config::SOUND_MIN_RADIUS, 
            Config::SOUND_MIN_RADIUS, 
            Config::SOUND_MAX_RADIUS,
            true
        )
    );

    // Player *player = new Player(
    //     Config::PLAYER_SPAWN_POSITION_X,
    //     Config::PLAYER_SPAWN_POSITION_Y,
    //     Config::PLAYER_HEALTH,
    //     Config::PLAYER_STRENGTH, 
    //     Config::PLAYER_AGILITY, 
    //     Config::PLAYER_HEARING_RADIUS, 
    //     Config::PLAYER_ATTACK_RADIUS
    // );

    scene.AddEntity(&player);
    
    // Entities
    // for (size_t i = 0; i < Config::ZOMBIES_COUNT; i++) {
    //     scene.AddEntity(new Zombie(
    //         Config::ZOMBIE_SPAWN_POSITION_X, 
    //         Config::ZOMBIE_SPAWN_POSITION_Y,
    //         Config::ZOMBIE_HEALTH, 
    //         Config::ZOMBIE_STRENGTH, 
    //         Config::ZOMBIE_AGILITY, 
    //         Config::ZOMBIE_HEARING_RADIUS, 
    //         Config::ZOMBIE_ATTACK_RADIUS
    //     ));
    // }

    // Systems
    // ZombieSystem zombieSystem;
    // PlayerSystem playerSystem;
    CameraSystem cameraSystem;
    // scene.AddSystem(&playerSystem);
    // scene.AddSystem(&zombieSystem);
    scene.AddSystem(&cameraSystem);

    game.AddScene(&scene);
    game.Init();

    InitWindow(
        Config::WINDOW_WIDTH,
        Config::WINDOW_HEIGHT,
        Config::WINDOW_TITLE
    );

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        game.Update();

        BeginDrawing();
            ClearBackground(RAYWHITE);
            game.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
