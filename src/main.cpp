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
    Player player = Player(20.0f, 10.0f, 3.0f, 100.0f, 20.0f, 600.0f, 500.0f);
    Zombie zombie1 = Zombie(10.0f, 25.0f, 1.0f, 100.0f, 20.0f, 122.0f, 66.0f);
    Zombie zombie2 = Zombie(10.0f, 25.0f, 1.0f, 100.0f, 20.0f, 122.0f, 66.0f);
    Zombie zombie3 = Zombie(10.0f, 25.0f, 1.0f, 100.0f, 20.0f, 122.0f, 66.0f);
    Zombie zombie4 = Zombie(10.0f, 25.0f, 1.0f, 100.0f, 20.0f, 122.0f, 66.0f);
    Zombie zombie5 = Zombie(10.0f, 25.0f, 1.0f, 100.0f, 20.0f, 122.0f, 66.0f);
    Zombie zombie6 = Zombie(10.0f, 25.0f, 1.0f, 100.0f, 20.0f, 122.0f, 66.0f);
    Zombie zombie7 = Zombie(10.0f, 25.0f, 1.0f, 100.0f, 20.0f, 122.0f, 66.0f);
    Zombie zombie8 = Zombie(10.0f, 25.0f, 1.0f, 100.0f, 20.0f, 122.0f, 66.0f);
    Zombie zombie9 = Zombie(10.0f, 25.0f, 1.0f, 100.0f, 20.0f, 122.0f, 66.0f);
    Zombie zombie10 = Zombie(10.0f, 25.0f, 1.0f, 100.0f, 20.0f, 122.0f, 66.0f);
    
    ZombieSystem zombieSystem;
    PlayerSystem inputSystem;
    
    Scene scene = Scene();
    scene.AddEntity(&player);
    scene.AddEntity(&zombie1);
    scene.AddEntity(&zombie2);
    scene.AddEntity(&zombie3);
    scene.AddEntity(&zombie4);
    scene.AddEntity(&zombie5);
    scene.AddEntity(&zombie6);
    scene.AddEntity(&zombie7);
    scene.AddEntity(&zombie8);
    scene.AddEntity(&zombie9);
    scene.AddEntity(&zombie10);
    scene.AddSystem(&inputSystem);
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
