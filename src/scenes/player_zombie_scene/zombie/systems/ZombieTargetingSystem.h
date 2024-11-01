#ifndef ZOMBIE_TARGETING_SYSTEM_H
#define ZOMBIE_TARGETING_SYSTEM_H

#include <vector>
#include <raylib-cpp.hpp>
#include <iostream>

#include "../../../../Config.h"
#include "../../../../core/Bootstrap.h"
#include "../../map/components/Bootstrap.h"
#include "../components/Bootstrap.h"
#include "../../player/components/Bootstrap.h"
#include "../../collider/components/Bootstrap.h"

class ZombieTargetingSystem : public System {
  public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
    void Draw(std::vector<Entity*> *entities) override;

    Vector2 RandomTarget(float xMax, float yMax);
    bool TargetReached(Vector2 targetPos, Vector2 curPos);
    bool TargetReachable(Vector2 targetPos, Vector2 curPos, float zombieRadius, TerrainComponent *terrain, WallsMapComponent *wallsMap);
};

#endif // ZOMBIE_TARGETING_SYSTEM_H
