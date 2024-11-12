#ifndef PLAYER_FEET_SYSTEM_H
#define PLAYER_FEET_SYSTEM_H

#include <vector>
#include <raylib-cpp.hpp>
#include <iostream>

#include "../../../Config.h"
#include "../../../core/Bootstrap.h"
#include "../../../scenes/Tools.h"
#include "../components/Bootstrap.h"


class PlayerFeetSystem : public System {
  public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
    void Draw(std::vector<Entity*> *entities) override;

    void LeftFoot(LeftFootComponent *leftFoot, RightFootComponent *rightFoot, bool goalReached, Vector2 newGoalPos);
    void RightFoot(LeftFootComponent *leftFoot, RightFootComponent *rightFoot, bool goalReached, Vector2 newGoalPos);
    };

#endif // PLAYER_FEET_SYSTEM_H
