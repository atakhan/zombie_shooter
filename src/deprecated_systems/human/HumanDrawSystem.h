#ifndef HUMAN_DRAW_SYSTEM_H
#define HUMAN_DRAW_SYSTEM_H

#include <vector>
#include <string>
#include "../../core/System.h"
#include "../../utils/Bootstrap.h"

class HumanDrawSystem : public System {
  public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
    void Draw(std::vector<Entity*> *entities) override;

    void DrawBody(PositionComponent *pos, HealthComponent *health, bool isAlive);
    void DrawMessArea(PositionComponent* position, SoundComponent* sound);
    void DrawHumanInfo(Entity *entity);
};

#endif // HUMAN_DRAW_SYSTEM_H
