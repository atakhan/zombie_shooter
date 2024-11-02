#ifndef SRC_ENTITIES_ZOMBIE_SYSTEMS_ZOMBIE_MOVE_SYSTEM_H
#define SRC_ENTITIES_ZOMBIE_SYSTEMS_ZOMBIE_MOVE_SYSTEM_H

#include <vector>
#include <raylib-cpp.hpp>
#include <iostream>

#include "../../../Config.h"
#include "../../../core/Bootstrap.h"
#include "../components/Bootstrap.h"
#include "../../player/components/Bootstrap.h"


class ZombieMoveSystem : public System {
  public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
    void Draw(std::vector<Entity*> *entities) override;
    // bool GetRandomHalfProbability(int percent);
    
    // PositionComponent *FindFood(PositionComponent *zombie_position, PositionComponent *player_position, float zombie_radius, float player_sound_radius);
    void MoveTo(TargetComponent *targetPos, PositionComponent *curPos, float speed);
};

#endif // SRC_ENTITIES_ZOMBIE_SYSTEMS_ZOMBIE_MOVE_SYSTEM_H
