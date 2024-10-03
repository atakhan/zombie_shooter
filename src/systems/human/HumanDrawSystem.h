#ifndef HUMAN_DRAW_SYSTEM_H
#define HUMAN_DRAW_SYSTEM_H

#include <vector>
#include <string>
#include "../../core/System.h"

class HumanDrawSystem : public System {
  public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
    void Draw(std::vector<Entity*> *entities) override;

    void DrawBody(PositionComponent *pos, HealthComponent *health, bool isAlive);
    void DrawMessArea(PositionComponent* position, SoundComponent* sound);
    void DrawHumanInfo(HumanComponent *human, PositionComponent* position, HealthComponent* health, HumanPhysiologicalComponent* physiology, HumanBreathComponent *breath);
    void DrawTitleValueText(PositionComponent* position, std::string title, std::string value);
};

#endif // HUMAN_DRAW_SYSTEM_H
