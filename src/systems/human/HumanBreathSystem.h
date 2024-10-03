#ifndef HUMAN_BREATH_SYSTEM_H
#define HUMAN_BREATH_SYSTEM_H

#include <vector>
#include <string>
#include <iostream>
#include "../../core/System.h"

class HumanBreathSystem : public System {
  public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
    void Draw(std::vector<Entity*> *entities) override;
    void MakeInhale(HumanBreathComponent* humanBreath, HumanPhysiologicalComponent *physiology);
    void MakeExhale(HumanBreathComponent* humanBreath, HumanPhysiologicalComponent *physiology);
    void DecreaseAirValue(HumanPhysiologicalComponent *physiology, HumanComponent::Status currentStatus);
    void IncreaseAirValue(HumanPhysiologicalComponent *physiology, HumanComponent::Status currentStatus);

};

#endif // HUMAN_BREATH_SYSTEM_H
