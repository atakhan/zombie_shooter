#ifndef PLAYER_STEP_SYSTEM_H
#define PLAYER_STEP_SYSTEM_H

#include <vector>
#include <raylib-cpp.hpp>
#include <iostream>

#include "../../../Config.h"
#include "../../../core/Bootstrap.h"
#include "../../../scenes/Tools.h"
#include "../components/Bootstrap.h"


class PlayerStepSystem : public System {
 public:
  void Init(std::vector<Entity*> *entities) override;
  void Update(std::vector<Entity*> *entities) override;
  void Draw(std::vector<Entity*> *entities) override;

  void Idle(LeftFootComponent *leftFoot, RightFootComponent *rightFoot, PlayerComponent *player);
  void WhoIsFirst(LeftFootComponent *leftFoot, RightFootComponent *rightFoot, bool leftFirst);

  void MoveLeftFoot(LeftFootComponent *leftFoot, RightFootComponent *rightFoot, bool condition, Vector2 newGoal);
  void MoveRightFoot(LeftFootComponent *leftFoot, RightFootComponent *rightFoot, bool condition, Vector2 newGoal);

  void Move(LeftFootComponent *leftFoot, RightFootComponent *rightFoot);
};

#endif // PLAYER_STEP_SYSTEM_H
