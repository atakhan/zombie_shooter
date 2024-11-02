#ifndef SRC_ENTITIES_MENU_SYSTEMS_MENU_CONTROL_SYSTEM_H
#define SRC_ENTITIES_MENU_SYSTEMS_MENU_CONTROL_SYSTEM_H

#include <vector>
#include <raylib-cpp.hpp>
#include <iostream>

#include "../../../Config.h"
#include "../../../core/Bootstrap.h"
#include "../../../scenes/Tools.h"
#include "../components/Bootstrap.h"


class MenuControlSystem : public System {
  public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
    void Draw(std::vector<Entity*> *entities) override;
};

#endif // SRC_ENTITIES_MENU_SYSTEMS_MENU_CONTROL_SYSTEM_H
