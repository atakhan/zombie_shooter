#ifndef SRC_ENTITIES_ZOMBIE_SYSTEMS_ZOMBIE_DRAW_SYSTEM_H
#define SRC_ENTITIES_ZOMBIE_SYSTEMS_ZOMBIE_DRAW_SYSTEM_H

#include <vector>
#include <raylib-cpp.hpp>
#include <iostream>

#include "../../../Config.h"
#include "../../../core/Bootstrap.h"
#include "../components/Bootstrap.h"


class ZombieDrawSystem : public System {
  public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
    void Draw(std::vector<Entity*> *entities) override;
};

#endif // SRC_ENTITIES_ZOMBIE_SYSTEMS_ZOMBIE_DRAW_SYSTEM_H
