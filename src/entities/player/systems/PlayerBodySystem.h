#ifndef PLAYER_BODY_SYSTEM_H
#define PLAYER_BODY_SYSTEM_H

#include <vector>
#include <raylib-cpp.hpp>
#include <iostream>

#include "../../../Config.h"
#include "../../../core/Bootstrap.h"
#include "../../../scenes/Tools.h"
#include "../components/Bootstrap.h"


class PlayerBodySystem : public System {
 public:
  Entity *player_;
  PlayerBodyComponent *body_;
  LeftFootComponent *leftFoot_;
  RightFootComponent *rightFoot_;
  DirectionComponent *direction_;
  float leftAngle_;
  float rightAngle_;

  void Init(std::vector<Entity*> *entities) override;
  void Update(std::vector<Entity*> *entities) override;
  void Draw(std::vector<Entity*> *entities) override;

  float GetLimitAngle(float angle);
  void Idle(PlayerComponent *player);
  void SetLeftRightLimits();
  bool isPositive(float value);
  bool isNegative(float value);
  void LocateBody();
  void SetShadowRotation();
  void RotateBody();
  void RotateToLeft();
  void RotateToRight();
};

#endif // PLAYER_BODY_SYSTEM_H
