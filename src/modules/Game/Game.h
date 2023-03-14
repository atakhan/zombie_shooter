#ifndef GAME_H
#define GAME_H

#include "../Bullet/Bullet.h"
#include "../Player/Player.h"
#include "../Collider/Collider.h"
#include <raylib-cpp.hpp>

class Game {
public:
  Player player;
  Enemy enemy;
  std::vector<Enemy> enemies;
  int tick;
  int killed;
  int spawnTime;
  bool isOver;
  Texture2D player_texture;
  Texture2D game_bg;
  Texture2D enemy_texture;

  Game();

  void Restart();
  void DrawStats();
  void DrawGameOver();
  void Draw();
  void Update();

};

#endif  // GAME_H