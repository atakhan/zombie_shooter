#include "Bullet.h"
#include <iostream>

Bullet::Bullet(Vector2 _pos, Vector2 _vel) {
  radius = 5;
  color = YELLOW;
  pos = _pos;
  vel = _vel;
}

bool Bullet::WallCollider() {
  if ((pos.x + radius >= GetScreenWidth()) || (pos.x - radius < 0)) {
    return true;
  }
  if (pos.y + radius >= GetScreenHeight() || (pos.y - radius < 0)) {
    return true;
  }
  return false;
}

void Bullet::update() {
  pos.x += vel.x;
  pos.y += vel.y;
  
}

void Bullet::draw() {
  DrawCircle(
    pos.x,
    pos.y,
    radius,
    color
  );
}