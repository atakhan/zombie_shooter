#include <raylib-cpp.hpp>
#include <iostream>
#include <string>

#include "core/Bootstrap.h"

#include "Config.h"

// Scene
#include "scenes/Bootstrap.h"


int main() {
    Game *game = new Game(
        Game::Mode::CHOOSE_SCENE
    );
    
    // // SCENE MANAGER index 0
    game->AddScene(new ManageScenesScene(0, true, 10, 10, "choose a scene"));
    game->AddScene(new PlayerZombieScene(1, false, 20, 20, "player vs zombie scene"));
    // game->AddScene(new MovementTestingScene(1, false, 20, 20, "Movement Testing Scene"));
    // game->AddScene(new HumanTrainingScene(3, false, 10, 10, "try to create a human entity scene"));
    
    game->Init();

    InitWindow(
        Config::WINDOW_WIDTH,
        Config::WINDOW_HEIGHT,
        Config::GAME_TITLE
    );

    Scene *currentScene = game->scenes[game->currentSceneIndex_];

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        if ((int)game->currentMode_ == 2) {
            break;
        }

        game->Update();

        BeginDrawing();
            
            ClearBackground(BLACK);
            game->Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
