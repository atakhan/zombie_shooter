#ifndef SRC_UTILS_MAP_TOOLS_H
#define SRC_UTILS_MAP_TOOLS_H

#include <string>
#include "../Config.h"
#include "../core/Bootstrap.h"
#include "../components/Bootstrap.h"
#include "../systems/Bootstrap.h"

class MapTools {  
  public:
    // CREATE GAME
    static Entity* CreateTerrain(float width, float height, float cellWidth, float cellHeight) {
        // logic entities
        Entity *terrain = new Entity();
        terrain->AddComponent<TerrainComponent>(TerrainComponent(
            width, 
            height,
            cellWidth,
            cellHeight
        ));

        return terrain;
    }
};

#endif // SRC_UTILS_MAP_TOOLS_H