#ifndef HUMAN_TARGETING_SYSTEM_H
#define HUMAN_TARGETING_SYSTEM_H

#include <vector>
#include <raylib-cpp.hpp>
#include <iostream>

#include "../../Config.h"
#include "../../core/Bootstrap.h"
#include "../../components/Bootstrap.h"

class HumanTargetingSystem : public System {
  public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
    void Draw(std::vector<Entity*> *entities) override;

    bool TargetReached(Vector2 targetPos, Vector2 curPos);
    Vector2 FindTarget(HumanComponent *human, std::vector<Entity*> *entities);
    Vector2 RandomTarget();
};

#endif // HUMAN_TARGETING_SYSTEM_H
