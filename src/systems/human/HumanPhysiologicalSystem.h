#ifndef HUMAN_PHYSIOLOGICAL_SYSTEM_H
#define HUMAN_PHYSIOLOGICAL_SYSTEM_H

#include <vector>
#include <raylib-cpp.hpp>
#include <iostream>

#include "../../core/Bootstrap.h"

class HumanPhysiologicalSystem : public System {
  public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
    void Draw(std::vector<Entity*> *entities) override;
};

#endif // HUMAN_PHYSIOLOGICAL_SYSTEM_H
