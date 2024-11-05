#ifndef PLAYER_MOVE_SYSTEM_H
#define PLAYER_MOVE_SYSTEM_H

#include <vector>
#include <raylib-cpp.hpp>
#include <iostream>

#include "../../../Config.h"
#include "../../../core/Bootstrap.h"
#include "../components/Bootstrap.h"


class PlayerMoveSystem : public System {
  public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
    void Draw(std::vector<Entity*> *entities) override;

    void SetDefaultPosition(FeetComponent* feet, HealthComponent *playerHealth, PositionComponent *playerPosition);
    void SetRotationCenter(FeetComponent* feet);

    void Idle(LeftFootComponent* leftFoot, PositionComponent *playerPosition);
    void Move(LeftFootComponent *leftFoot, PositionComponent *playerPosition);
    void MoveRight(PositionComponent *playerPosition, LeftFootComponent *leftFoot, RightFootComponent *rightFoot);
    void MoveLeft(SoundComponent *sound, PositionComponent *position, SpeedComponent *speed);
    void MoveTop(SoundComponent *sound, PositionComponent *position, SpeedComponent *speed);
    void MoveBottom(SoundComponent *sound, PositionComponent *position, SpeedComponent *speed);
};

#endif // PLAYER_MOVE_SYSTEM_H
