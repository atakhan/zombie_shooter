#ifndef MENU_H
#define MENU_H

#include "../Bullet/Bullet.h"
#include <raylib-cpp.hpp>

class Menu
{
public:
  
  Menu();

  void update(Vector2 pPos);
  void draw();
};

#endif  // MENU_H