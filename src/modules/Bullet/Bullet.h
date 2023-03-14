#ifndef BULLET_H
#define BULLET_H

#include "../Enemy/Enemy.h"
#include <raylib-cpp.hpp>

class Bullet
{
public:
  int radius;
  Vector2 pos;
  Vector2 vel;
  Color color;

  Bullet(Vector2 _pos, Vector2 _vel);
  
  bool WallCollider();
  
  void update();
  void draw();

  static void DrawAll(std::vector<Bullet> &bullets) {
    for(auto bullet = bullets.begin(); bullet != bullets.end(); bullet++) 
      bullet->draw();
  }

};

#endif  // BULLET_H