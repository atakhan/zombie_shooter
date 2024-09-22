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

    Player player = Player(20.0f, 10.0f, 3.0f, 100.0f, 20.0f, 600.0f, 500.0f, 300.0f);
    Zombie zombie1 = Zombie(10.0f, 25.0f, 1.0f, 100.0f, 20.0f, 122.0f, 66.0f);

    ZombieSystem zombieSystem;
    PlayerSystem inputSystem;

    scene.AddEntity(&player);
    scene.AddEntity(&zombie1);
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
