#ifndef ENEMY_H
#define ENEMY_H
#include "../Bullet/Bullet.h"
#include "../SpriteAnimation/SpriteAnimation.h"
#include <raylib-cpp.hpp>

#define SPAWN_TIME 60
#define MAX_ENEMY_AMOUNT 10

class Enemy
{
public:
  int radius;
  Vector2 pos;
  Vector2 vel;
  Color color;
  float speed = 1;
  float angle;
  SpriteAnimation sprite;

  Enemy();
  Enemy(SpriteAnimation sprite);

  int randomWall();
  int randomPos(int a);

  void move(Vector2 pPos);
  void update(Vector2 pPos);
  void draw();
  void spawn(Texture2D texture, std::vector<Enemy> &enemies, int *tick, int killed, int *spawn_time);

  static void DrawAll(std::vector<Enemy> &enemies) {
    for(auto enemy = enemies.begin(); enemy!=enemies.end(); enemy++)
      enemy->draw();
  }

};

#endif  // ENEMY_H