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
    
    bool TargetNotReached(Vector2 targetPos, Vector2 curPos);
    float GetSpeed(HumanComponent::Status state);
    void MoveTo(HumanPhysiologicalComponent *physiology, TargetComponent *targetPos, PositionComponent *curPos, HumanComponent::Status *state, float speed);
    
};

#endif // HUMAN_MOVE_SYSTEM_H
