#ifndef WALLS_DRAW_SYSTEM_H
#define WALLS_DRAW_SYSTEM_H

#include <vector>
#include <raylib-cpp.hpp>
#include <iostream>

#include "../../Config.h"
#include "../../utils/Bootstrap.h"
#include "../../core/Bootstrap.h"
#include "../../components/Bootstrap.h"

class WallsDrawSystem : public System {
  public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
    void Draw(std::vector<Entity*> *entities) override;

    void DrawWallsMapCell(float posx, float posy, int w, int h);
};

#endif // WALLS_DRAW_SYSTEM_H
