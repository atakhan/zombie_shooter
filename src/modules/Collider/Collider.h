#ifndef COLLIDER_H
#define COLLIDER_H

#include "../Enemy/Enemy.h"
#include "../Bullet/Bullet.h"
#include "../Player/Player.h"
#include <raylib-cpp.hpp>

template<typename T>
class Collider
{
public:
  static bool EnemyCollider(T &gameObject, Enemy &enemy) {
    return fabs(
      (gameObject.pos.x - enemy.pos.x) * (gameObject.pos.x - enemy.pos.x) + 
      (gameObject.pos.y - enemy.pos.y) * (gameObject.pos.y - enemy.pos.y) 
    ) <= (
      (gameObject.radius + enemy.radius) * (gameObject.radius + enemy.radius)
    );
  }
  
  static void Update(
    Player &player, 
    std::vector<Enemy> &enemies, 
    bool *isOver,
    int *killed
  )
  {
    for(auto enemy = enemies.begin(); enemy!=enemies.end(); enemy++) {
      enemy->update(player.pos);
      if (Collider<Player>::EnemyCollider(player, *enemy))
        *isOver = true;
    }

    for(auto bullet = player.bullets.begin(); bullet!=player.bullets.end();) {
      bullet->update();
      
      bool isBulletCollideWithEnemy = false;
      for(auto enemy = enemies.begin(); enemy!=enemies.end();) {
        if (Collider<Bullet>::EnemyCollider(*bullet, *enemy)) {
          enemy = enemies.erase(enemy);
          isBulletCollideWithEnemy = true;
          *killed += 1;
        } else {
          enemy++;
        }
      }
      
      if (bullet->WallCollider() || isBulletCollideWithEnemy)
        bullet = player.bullets.erase(bullet);
      else
        bullet++;
    }
  }
};

#endif  // COLLIDER_H