#include <raylib-cpp.hpp>
#include "game.h"

int main() {

    Game game;
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