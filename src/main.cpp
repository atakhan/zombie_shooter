#include <raylib-cpp.hpp>

#include "modules/Player/Player.h"
#include "modules/Bullet/Bullet.h"
#include "modules/Enemy/Enemy.h"
#include "modules/Collider/Collider.h"
#include "modules/Game/Game.h"

#include <iostream>
#include <vector>
#include <iterator>

int main() {
  int screenWidth = 1024;
  int screenHeight = 1024;

  raylib::Color textColor(LIGHTGRAY);
  raylib::Window window(screenWidth, screenHeight, "Zombie Shooter");

  InitAudioDevice();

  // raylib::Music backgroundMusic = LoadMusicStream("assets/sounds/zombie_sound.mp3");

  // PlayMusicStream(backgroundMusic);

  SetTargetFPS(60);

  Game game = Game();

  float timePlayed = 0.0f;

  while (!window.ShouldClose()) {
      // UpdateMusicStream(backgroundMusic);
      // PlayMusicStream(backgroundMusic);
      // timePlayed = GetMusicTimePlayed(backgroundMusic)/GetMusicTimeLength(backgroundMusic);

      // if (timePlayed > 1.0f) timePlayed = 1.0f;   // Make sure time played is no longer than music
      game.Update();
      BeginDrawing();
        ClearBackground(RAYWHITE);
        game.Draw();
      EndDrawing();
      
      game.tick++;
  }
    // UnloadMusicStream(backgroundMusic);   // Unload music stream buffers from RAM

    CloseAudioDevice();         // Close audio device (music streaming is automatically stopped)

    CloseWindow();
    return 0;
}
