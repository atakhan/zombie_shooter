#ifndef HUMAN_MOVE_SYSTEM_H
#define HUMAN_MOVE_SYSTEM_H

#include <vector>
#include <raylib-cpp.hpp>
#include <iostream>

#include "../../Config.h"
#include "../../core/Bootstrap.h"
#include "../../components/Bootstrap.h"

class HumanMoveSystem : public System {
  public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
    void Draw(std::vector<Entity*> *entities) override;

    void MoveTo(TargetComponent *targetPos, PositionComponent *curPos, float speed);
    
};

#endif // HUMAN_MOVE_SYSTEM_H
