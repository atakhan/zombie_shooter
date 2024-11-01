#ifndef UI_DRAW_SYSTEM_H
#define UI_DRAW_SYSTEM_H

#include <vector>
#include <raylib-cpp.hpp>

#include "../../../Config.h"
#include "../../../core/Bootstrap.h"
#include "../../menu/components/Bootstrap.h"

class UIDrawSystem : public System {
  public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
    void Draw(std::vector<Entity*> *entities) override;
};

#endif // UI_DRAW_SYSTEM_H
