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
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
    void Draw(std::vector<Entity*> *entities) override;

    float GetLimitAngle(float angle);
    void Idle(LeftFootComponent *leftFoot, RightFootComponent *rightFoot, PlayerComponent *player);
    void MoveBodyDirectionToRight(PlayerBodyComponent *playerBody);
    void MoveBodyDirectionToLeft(PlayerBodyComponent *playerBody);
    bool isPositive(float value);
    void RotateToLeft(PlayerBodyComponent *playerBody);
    void RotateToRight(PlayerBodyComponent *playerBody);
};

#endif // PLAYER_BODY_SYSTEM_H
