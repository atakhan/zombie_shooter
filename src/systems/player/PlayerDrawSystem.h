#ifndef PLAYER_DRAW_SYSTEM_H
#define PLAYER_DRAW_SYSTEM_H

#include <vector>

#include "../../core/System.h"

class PlayerDrawSystem : public System {
  public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
    void Draw(std::vector<Entity*> *entities) override;
};

#endif // PLAYER_DRAW_SYSTEM_H
