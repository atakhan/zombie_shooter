#include <raylib-cpp.hpp>

#include "Config.h"
#include "core/Game.h"
#include "core/Scene.h"
#include "entities/Player.h"
#include "entities/Zombie.h"
#include "systems/ZombieSystem.h"
#include "systems/PlayerSystem.h"

int main() {
    Game game;
    Scene scene = Scene();

    Player *player = new Player(
        Config::PLAYER_SPAWN_POSITION_X, 
        Config::PLAYER_SPAWN_POSITION_Y,
        Config::PLAYER_HEALTH, 
        Config::PLAYER_STRENGTH, 
        Config::PLAYER_AGILITY, 
        Config::PLAYER_HEARING_RADIUS, 
        Config::PLAYER_ATTACK_RADIUS
    );

    // Entities
    scene.AddEntity(player);

    for (size_t i = 0; i < Config::ZOMBIES_COUNT; i++) {
        scene.AddEntity(new Zombie(
            Config::ZOMBIE_SPAWN_POSITION_X, 
            Config::ZOMBIE_SPAWN_POSITION_Y,
            Config::ZOMBIE_HEALTH, 
            Config::ZOMBIE_STRENGTH, 
            Config::ZOMBIE_AGILITY, 
            Config::ZOMBIE_HEARING_RADIUS, 
            Config::ZOMBIE_ATTACK_RADIUS
        ));
    }

    // Systems
    ZombieSystem zombieSystem;
    PlayerSystem inputSystem;
    scene.AddSystem(&inputSystem);
    scene.AddSystem(&zombieSystem);

    game.AddScene(&scene);
    game.Init();

    InitWindow(
        Config::WINDOW_WIDTH,
        Config::WINDOW_HEIGHT,
        (Config::WINDOW_TITLE).c_str()
    );

    // Camera
    Camera2D camera = { 0 };
    camera.target = (Vector2){ Config::PLAYER_SPAWN_POSITION_X + 20.0f, Config::PLAYER_SPAWN_POSITION_Y + 20.0f };
    camera.offset = (Vector2){ Config::WINDOW_WIDTH/2.0f, Config::WINDOW_HEIGHT/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        game.Update();

        camera.target = (Vector2){ 
            player->GetPositionX() + 20, 
            player->GetPositionY() + 20
        };

        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginMode2D(camera);
                game.Draw();
            EndMode2D();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
