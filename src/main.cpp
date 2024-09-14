#include <raylib-cpp.hpp>
#include "game.h"

int main() {
    InitWindow(800, 600, "Top-Down RPG Demo");
    SetTargetFPS(60);

    Game game;
    game.Init();

    while (!WindowShouldClose()) {
        game.Update();
        BeginDrawing();
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}