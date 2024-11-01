#ifndef SRC_SCENES_MOVEMENTS_SCENE_MOVEMENTS_SCENE_H
#define SRC_SCENES_MOVEMENTS_SCENE_MOVEMENTS_SCENE_H

#include <string>
#include <iostream>

#include <raylib-cpp.hpp>

#include "../../Config.h"
#include "../../core/Bootstrap.h"
#include "../../entities/Bootstrap.h"
#include "../Tools.h"


#include "MovementsSceneMaps.h"

class MovementsScene : public Scene {
  public:
    MovementsScene(int index, bool isContinue, float width, float height, std::string title) 
      : Scene(index, isContinue, width, height, title) {};

    void Init() override;
    void Update(int *currentSceneIndex) override;
    void Draw() override;

    void GenerateMapEntities(Entity *mapEntity, std::vector<std::vector<int>> spawnMap, std::vector<std::vector<int>> wallsMap);
    std::vector<std::vector<int>> GetSpawnMap(int index);
    std::vector<std::vector<int>> GetWallsMap(int index);
};

#endif // SRC_SCENES_MOVEMENTS_SCENE_MOVEMENTS_SCENE_H
