#ifndef SRC_SCENES_TOOLS_H
#define SRC_SCENES_TOOLS_H

#include "../core/Bootstrap.h"
#include "manage_scenes_scene/menu/components/Bootstrap.h"
#include "player_zombie_scene/map/components/Bootstrap.h"

class Tools {
  public:
    static Entity* Tools::CreateScene(const std::string& gameTitle, const std::string& sceneTitle) {
        Entity *sceneEntity = new Entity();
        sceneEntity->AddComponent<SceneComponent>(SceneComponent(sceneTitle));
        sceneEntity->AddComponent<GameTitleComponent>(GameTitleComponent(gameTitle));
        
        return sceneEntity;
    }

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
};

#endif  // SRC_SCENES_BOOTSTRAP_H