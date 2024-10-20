#ifndef TERRAIN_DRAW_SYSTEM_H
#define TERRAIN_DRAW_SYSTEM_H

#include <vector>
#include <raylib-cpp.hpp>
#include <iostream>

#include "../../Config.h"
#include "../../utils/Bootstrap.h"
#include "../../core/Bootstrap.h"
#include "../../components/Bootstrap.h"

class TerrainDrawSystem : public System {
  public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
    void Draw(std::vector<Entity*> *entities) override;

    void DrawSpawnMapColors(TerrainComponent* terrain, SpawnMapComponent *spawnMap, int x, int y);
    void DrawWallsColors(TerrainComponent* terrain, WallsMapComponent *wallsMap, int x, int y);
    void DrawFloorColors(TerrainComponent* terrain, WallsMapComponent *wallsMap, int x, int y);
};

#endif // TERRAIN_DRAW_SYSTEM_H
