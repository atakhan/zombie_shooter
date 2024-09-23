#include <raylib-cpp.hpp>

#include "core/Game.h"
#include "core/Config.h"
#include "core/Scene.h"
#include "entities/Player.h"
#include "entities/Zombie.h"
#include "systems/ZombieSystem.h"
#include "systems/PlayerSystem.h"

int main() {
    Game game;
    Scene scene = Scene();

    // Entities
    scene.AddEntity(new Player(
        Config::PLAYER_SPAWN_POSITION_X, 
        Config::PLAYER_SPAWN_POSITION_Y,
        Config::PLAYER_HEALTH, 
        Config::PLAYER_STRENGTH, 
        Config::PLAYER_AGILITY, 
        Config::PLAYER_HEARING_RADIUS, 
        Config::PLAYER_ATTACK_RADIUS
    ));

    for (size_t i = 0; i < Config::ZOMBIES_COUNT; i++)
    {
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
