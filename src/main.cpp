#include <raylib-cpp.hpp>

#include "Config.h"
#include "core/Bootstrap.h"
#include "components/Bootstrap.h"
#include "systems/Bootstrap.h"
#include "scenes/Bootstrap.h"

int main() {
    Game game(Game::Mode::CHOOSE_SCENE);
    // SCENE MANAGER index 0
    game.AddScene(new ManageScenesScene);

    // SCENES index++
    game.AddScene(new PlayerZombieScene());
    game.AddScene(new HumanTrainingScene());
    
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
