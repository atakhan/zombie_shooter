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
    
    static float AngleBetweenVectors(const Vector2& a, const Vector2& b) {        
        // Calculate the dot product
        float dotProduct = a.x * b.x + a.y * b.y;

        // Calculate the magnitudes
        float magnitudeA = std::sqrt(a.x * a.x + a.y * a.y);
        float magnitudeB = std::sqrt(b.x * b.x + b.y * b.y);

        // Avoid division by zero
        if (magnitudeA == 0 || magnitudeB == 0) {
            return 0; // or handle as needed
        }

        // Calculate the cosine of the angle
        float cosTheta = dotProduct / (magnitudeA * magnitudeB);

        // Clamp the value to the range [-1, 1] to avoid NaN from acos
        cosTheta = std::fmax(-1.0f, std::fmin(1.0f, cosTheta));

        // Calculate the angle in radians
        float angleRadians = std::acos(cosTheta);

        // Convert to degrees
        float angleDegrees = angleRadians * (180.0f / M_PI);

        return angleDegrees;
    }
    
    static float NormalizeToRange(float value, float minValue, float maxValue) {
        // Ensure the minValue is less than maxValue
        if (minValue >= maxValue) {
            throw std::invalid_argument("minValue must be less than maxValue");
        }

        // Normalize the value to the range [0, 1]
        float normalizedValue = (value - minValue) / (maxValue - minValue);
        
        // Clamp the normalized value to the range [0, 1]
        normalizedValue = std::max(0.0f, std::min(1.0f, normalizedValue));

        // Return as a Vector2, using normalizedValue for both x and y for simplicity
        return normalizedValue;
    }
};


#endif // SRC_UTILS_MAP_TOOLS_H