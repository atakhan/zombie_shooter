#ifndef SRC_UTILS_MAP_TOOLS_H
#define SRC_UTILS_MAP_TOOLS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "../Config.h"
#include "../core/Bootstrap.h"
#include "../components/Bootstrap.h"
#include "../systems/Bootstrap.h"

class MapTools {  
  public:
    // CREATE GAME
    static Entity* CreateMap(
        std::vector<std::vector<int>> spawnMap,
        std::vector<std::vector<int>> wallsMap,
        float cellWidth, 
        float cellHeight
    ) {
        Entity *mapEntity = new Entity();
        mapEntity->AddComponent<TerrainComponent>(TerrainComponent(
            spawnMap.size(), // width
            spawnMap.at(0).size(), // height
            cellWidth,
            cellHeight
        ));

        mapEntity->AddComponent<SpawnMapComponent>(SpawnMapComponent(spawnMap));
        mapEntity->AddComponent<WallsMapComponent>(WallsMapComponent(wallsMap));

        return mapEntity;
    }

    static Vector2 GetPlayerSpawnPositionFromMap(Entity *entity) {
        SpawnMapComponent *spawnMap = entity->GetComponent<SpawnMapComponent>();
        TerrainComponent *terrain = entity->GetComponent<TerrainComponent>();
        if (spawnMap && terrain) {
            for (size_t i = 0; i < terrain->height_; i++) {
                for (size_t j = 0; j < terrain->width_; j++) {
                    // PLAYER SPAWN POINT
                    if (spawnMap->map_[i][j] == 1) {  
                        return (Vector2) {
                            (i * terrain->cellHeight_) + (terrain->cellHeight_ / 2),
                            (j * terrain->cellWidth_) + (terrain->cellWidth_ / 2)
                        };
                    }
                }
            }
        }
        std::cout << "spawn point not found. set custom pos 0,0" << std::endl;
        return (Vector2){0.0f,0.0f};
    }

    static Entity* CreateWall(
        PositionComponent position,
        HealthComponent health,
        SoundReflectComponent soundReflect,
        RectangleColliderComponent rectCollider
    ) {
        Entity *wall = new Entity();
        wall->AddComponent<WallComponent>(WallComponent());
        wall->AddComponent<PositionComponent>(position);
        wall->AddComponent<HealthComponent>(health);
        wall->AddComponent<SoundReflectComponent>(soundReflect);
        wall->AddComponent<RectangleColliderComponent>(rectCollider);

        return wall;
    }  
};

#endif // SRC_UTILS_MAP_TOOLS_H