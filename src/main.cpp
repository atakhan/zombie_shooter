#include <raylib-cpp.hpp>
#include <iostream>
#include <string>

#include "Config.h"
#include "core/Bootstrap.h"
#include "components/Bootstrap.h"
#include "systems/Bootstrap.h"
#include "scenes/Bootstrap.h"
#include "utils/Bootstrap.h"

int main() {
    Game *game = new Game(
        Game::Mode::CHOOSE_SCENE
    );
    
    // // SCENE MANAGER index 0
    game->AddScene(new ManageScenesScene(0, true, 1000, 1000, "choose a scene"));
    game->AddScene(new PlayerZombieScene(1, false, 1000, 1000, "player vs zombie scene"));
    game->AddScene(new HumanTrainingScene(2, false, 1000, 1000, "try to create a human entity scene"));
    
    game->Init();

    InitWindow(
        Config::WINDOW_WIDTH,
        Config::WINDOW_HEIGHT,
        Config::GAME_TITLE
    );

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        if ((int)game->currentMode_ == 2) {
            break;
        }

        game->Update();

        BeginDrawing();
            ClearBackground(RAYWHITE);
            game->Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
