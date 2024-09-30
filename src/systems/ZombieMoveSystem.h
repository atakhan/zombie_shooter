#ifndef ZOMBIE_MOVE_SYSTEM_H
#define ZOMBIE_MOVE_SYSTEM_H

#include <vector>
#include <raylib-cpp.hpp>
#include <iostream>

#include "../Config.h"
#include "../core/Bootstrap.h"
#include "../components/Bootstrap.h"

class ZombieMoveSystem : public System {
  public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
    void Draw(std::vector<Entity*> *entities) override;
    bool GetRandomHalfProbability(int percent);
    PositionComponent* FindFood(Entity *player, Entity *zombie);
};

#endif // ZOMBIE_MOVE_SYSTEM_H
