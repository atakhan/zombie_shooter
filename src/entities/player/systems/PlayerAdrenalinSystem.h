#ifndef SRC_SCENES_PLAYER_ZOMBIE_SCENE_PLAYER_SYSTEMS_ADRENALIN_SYSTEM_H
#define SRC_SCENES_PLAYER_ZOMBIE_SCENE_PLAYER_SYSTEMS_ADRENALIN_SYSTEM_H

#include <vector>
#include <raylib-cpp.hpp>
#include <iostream>

#include "../../../Config.h"
#include "../../../core/Bootstrap.h"
#include "../components/Bootstrap.h"
#include "../../zombie/components/Bootstrap.h"


class PlayerAdrenalinSystem : public System {
  public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
    void Draw(std::vector<Entity*> *entities) override;

    void DecreaseAdrenaline(AdrenalinComponent *playerAdrenalin);
    void IncreaseAdrenaline(AdrenalinComponent *playerAdrenalin);
};

#endif // SRC_SCENES_PLAYER_ZOMBIE_SCENE_PLAYER_SYSTEMS_ADRENALIN_SYSTEM_H
