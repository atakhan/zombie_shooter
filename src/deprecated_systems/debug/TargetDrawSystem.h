#ifndef TARGET_DRAW_SYSTEM_H
#define TARGET_DRAW_SYSTEM_H

#include <vector>
#include <raylib-cpp.hpp>

#include "../../Config.h"
#include "../../core/Bootstrap.h"
#include "../../components/Bootstrap.h"

class TargetDrawSystem : public System {
  public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
    void Draw(std::vector<Entity*> *entities) override;
};

#endif // TARGET_DRAW_SYSTEM_H
