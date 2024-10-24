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
            spawnMap.at(0).size(), // width
            spawnMap.size(), // height
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
            for (size_t y = 0; y < terrain->height_; y++) {
                for (size_t x = 0; x < terrain->width_; x++) {
                    // PLAYER SPAWN POINT
                    if (spawnMap->map_[y][x] == 1) {  
                        return (Vector2) {
                            (y * terrain->cellHeight_) + (terrain->cellHeight_ / 2),
                            (x * terrain->cellWidth_) + (terrain->cellWidth_ / 2)
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
    
    static float AngleBetweenVectors(const Vector2& mousePos, const Vector2& playerPos) {        
        float dx = mousePos.x - playerPos.x;
        float dy = playerPos.y - mousePos.y;
        float theta_radians = atan2f(dy, dx);
        
        return theta_radians * (-180.0/3.141592653589793238463);
    }
};


#endif // SRC_UTILS_MAP_TOOLS_H