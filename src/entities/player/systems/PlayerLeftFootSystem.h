#ifndef PLAYER_LEFT_FOOT_SYSTEM_H
#define PLAYER_LEFT_FOOT_SYSTEM_H

#include <vector>
#include <raylib-cpp.hpp>
#include <iostream>

#include "../../../Config.h"
#include "../../../core/Bootstrap.h"
#include "../../../scenes/Tools.h"
#include "../components/Bootstrap.h"


class PlayerLeftFootSystem : public System {
 public:
  void Init(std::vector<Entity*> *entities) override;
  void Update(std::vector<Entity*> *entities) override;
  void Draw(std::vector<Entity*> *entities) override;

  bool GoalReached(LeftFootComponent *foot);
  void MoveToGoal(LeftFootComponent *foot);
};

#endif // PLAYER_LEFT_FOOT_SYSTEM_H
