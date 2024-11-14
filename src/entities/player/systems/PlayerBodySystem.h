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

    void Idle(LeftFootComponent *leftFoot, RightFootComponent *rightFoot, PlayerComponent *player);

    float GetLimitAngle(float angle);
    void Move(LeftFootComponent *leftFoot, PositionComponent *playerPosition);
    void MoveRight(PositionComponent *playerPosition, LeftFootComponent *leftFoot, RightFootComponent *rightFoot);
    void MoveLeft(SoundComponent *sound, PositionComponent *position, SpeedComponent *speed);
    void MoveTop(SoundComponent *sound, PositionComponent *position, SpeedComponent *speed);
    void MoveBottom(SoundComponent *sound, PositionComponent *position, SpeedComponent *speed);
};

#endif // PLAYER_BODY_SYSTEM_H
