#include <raylib-cpp.hpp>

#include "core/Game.h"
#include "core/Config.h"
#include "core/Scene.h"
#include "entities/Player.h"
#include "entities/Zombie.h"
#include "systems/ZombieSystem.h"
#include "systems/InputSystem.h"

int main() {
    Game game;
    Player player = Player(100.0f, 10.0f, 3.0f, 100.0f, 20.0f, 600.0f, 500.0f);
    Zombie zombie = Zombie(10.0f, 25.0f, 1.0f, 100.0f, 20.0f, 122.0f, 66.0f);
    
    zombie.SetGoal(400.0f, 300.0f);
    ZombieSystem zombieSystem;
    
    Scene scene = Scene();
    scene.AddEntity(&player);
    scene.AddEntity(&zombie);
    scene.AddSystem(&zombieSystem);
    
    game.AddScene(&scene);
    game.Init();
    
    InitWindow(800, 600, "Zombie RPG");
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
