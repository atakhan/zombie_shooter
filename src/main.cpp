#include <raylib-cpp.hpp>


#include "core/Game.h"
#include "core/Config.h"
#include "core/Scene.h"
#include "entities/Zombie.h"

int main() {
    Game game;
    Scene scene;
    Zombie zombie = Zombie(200.0f, 25.0f, 5.0f, 100.0f, 20.0f);

    scene.AddEntity(zombie);
    game.AddScene();
    game.Init();
    InitWindow(800, 600, "Top-Down RPG Demo");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        game.Update();
        
        BeginDrawing();
            game.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
