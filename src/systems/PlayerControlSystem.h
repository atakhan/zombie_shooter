#ifndef PLAYER_CONTROL_SYSTEM_H
#define PLAYER_CONTROL_SYSTEM_H

#include <vector>

#include "../core/System.h"
#include "../core/Entity.h"
#include "../Config.h"
#include "../components/Bootstrap.h"

class PlayerControlSystem : public System {
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

#endif // PLAYER_CONTROL_SYSTEM_H
