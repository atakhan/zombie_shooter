#include <raylib-cpp.hpp>

#include "Config.h"
#include "core/Bootstrap.h"
#include "components/Bootstrap.h"
#include "systems/Bootstrap.h"
#include "scenes/Bootstrap.h"

int main() {
    Game game;
    HumanTrainingScene humanTrainingScene = HumanTrainingScene();

    game.AddScene(&humanTrainingScene);
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
