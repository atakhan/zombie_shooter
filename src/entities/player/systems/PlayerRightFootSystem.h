#ifndef PLAYER_RIGHT_FOOT_SYSTEM_H
#define PLAYER_RIGHT_FOOT_SYSTEM_H

#include <vector>
#include <raylib-cpp.hpp>
#include <iostream>

#include "../../../Config.h"
#include "../../../core/Bootstrap.h"
#include "../../../scenes/Tools.h"
#include "../components/Bootstrap.h"


class PlayerRightFootSystem : public System {
 public:
  void Init(std::vector<Entity*> *entities) override;
  void Update(std::vector<Entity*> *entities) override;
  void Draw(std::vector<Entity*> *entities) override;

  bool GoalReached(RightFootComponent *foot);
  void MoveToGoal(RightFootComponent *foot);
  void MoveFromBody(RightFootComponent *foot, PlayerBodyComponent *body);
};

#endif // PLAYER_RIGHT_FOOT_SYSTEM_H