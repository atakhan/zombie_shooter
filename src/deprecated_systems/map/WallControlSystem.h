#ifndef WALL_CONTROL_SYSTEM_H
#define WALL_CONTROL_SYSTEM_H

#include <vector>
#include <raylib-cpp.hpp>
#include <iostream>

#include "../../Config.h"
#include "../../utils/Bootstrap.h"
#include "../../core/Bootstrap.h"
#include "../../components/Bootstrap.h"

class WallControlSystem : public System {
  public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
    void Draw(std::vector<Entity*> *entities) override;

    void DrawSpawnMapColors(TerrainComponent* terrain, SpawnMapComponent *spawnMap, int x, int y);
    void DrawWallsColors(TerrainComponent* terrain, WallsMapComponent *wallsMap, int x, int y);
    void DrawFloorColors(TerrainComponent* terrain, WallsMapComponent *wallsMap, int x, int y);
};

#endif // WALL_CONTROL_SYSTEM_H
