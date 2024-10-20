#ifndef PLAYER_BREATH_SYSTEM_H
#define PLAYER_BREATH_SYSTEM_H

#include <vector>
#include <raylib-cpp.hpp>
#include <iostream>

#include "../../Config.h"
#include "../../core/Bootstrap.h"
#include "../../components/Bootstrap.h"


class PlayerBreathSystem : public System {
  public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
    void Draw(std::vector<Entity*> *entities) override;

    void IncreaseSoundRadius(SoundComponent *sound);
    void DecreaseSoundRadius(SoundComponent *sound);
    void Idle(SoundComponent *sound);
    void MoveRight(SoundComponent *sound, PositionComponent *position, SpeedComponent *speed);
    void MoveLeft(SoundComponent *sound, PositionComponent *position, SpeedComponent *speed);
    void MoveTop(SoundComponent *sound, PositionComponent *position, SpeedComponent *speed);
    void MoveBottom(SoundComponent *sound, PositionComponent *position, SpeedComponent *speed);
};

#endif // PLAYER_BREATH_SYSTEM_H
