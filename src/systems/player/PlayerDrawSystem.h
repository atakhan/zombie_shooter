#ifndef PLAYER_DRAW_SYSTEM_H
#define PLAYER_DRAW_SYSTEM_H

#include <vector>
#include <raylib-cpp.hpp>
#include <iostream>

#include "../../Config.h"
#include "../../core/Bootstrap.h"
#include "../../components/Bootstrap.h"

class PlayerDrawSystem : public System {
  public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
    void Draw(std::vector<Entity*> *entities) override;
};

#endif // PLAYER_DRAW_SYSTEM_H
