#ifndef ZOMBIE_TARGETING_SYSTEM_H
#define ZOMBIE_TARGETING_SYSTEM_H

#include <vector>
#include <raylib-cpp.hpp>
#include <iostream>

#include "../../Config.h"
#include "../../core/Bootstrap.h"
#include "../../components/Bootstrap.h"

class ZombieTargetingSystem : public System {
  public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
    void Draw(std::vector<Entity*> *entities) override;
  
    bool IsFoodNear(Vector2 zombiePosition, Vector2 playerPosition, float zombieRadius, float playerSoundRadius);
    Vector2 RandomTarget(float xMax, float yMax);
    bool TargetReached(Vector2 targetPos, Vector2 curPos);
    bool TargetReachable(Vector2 targetPos, Vector2 curPos, TerrainComponent *terrain, WallsMapComponent *wallsMap);
};

#endif // ZOMBIE_TARGETING_SYSTEM_H
