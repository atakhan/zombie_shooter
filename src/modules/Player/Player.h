#ifndef PLAYER_H
#define PLAYER_H

#include "../Bullet/Bullet.h"
#include "../SpriteAnimation/SpriteAnimation.h"
#include <raylib-cpp.hpp>

class Player
{
public:
  int radius;
  Vector2 pos;
  Vector2 rifleStart;
  Vector2 rifleEnd;
  Color color;
  std::vector<Bullet> bullets;
  int speed;

  SpriteAnimation sprite;

  int activeAnimation;

  Player();
  Player(SpriteAnimation sprite);

  void move();
  void UpdateAnimation();
  
  void rifleUpdate();
  void shoot();
  void reloadPosition();  
  void Update(int killed);

  void DrawBody();
  void DrawEyes();
  void DrawGun();
  void Draw();

};

#endif  // PLAYER_H