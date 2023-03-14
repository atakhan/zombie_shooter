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
  
  SetTargetFPS(60);

  Game game = Game();

  while (!window.ShouldClose()) {
      
      game.Update();

      BeginDrawing();
        ClearBackground(RAYWHITE);
        game.Draw();
      EndDrawing();
      
      game.tick++;
  }

  return 0;
}
