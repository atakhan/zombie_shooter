#include <raylib-cpp.hpp>

#include "Config.h"
#include "core/Bootstrap.h"
#include "components/Bootstrap.h"
#include "systems/Bootstrap.h"
#include "scenes/Bootstrap.h"
#include "utils/Bootstrap.h"

int main() {
    Game *game = new Game(Game::Mode::CHOOSE_SCENE);
    // // SCENE MANAGER index 0
    game->AddScene(new ManageScenesScene("choose a scene"));

    // // SCENES index++
    game->AddScene(new PlayerZombieScene("player vs zombie scene"));
    game->AddScene(new HumanTrainingScene("try to create a human entity scene"));
    
    game->Init();

    InitWindow(
        Config::WINDOW_WIDTH,
        Config::WINDOW_HEIGHT,
        Config::WINDOW_TITLE
    );

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        game->Update();

        BeginDrawing();
            ClearBackground(RAYWHITE);
            game->Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
