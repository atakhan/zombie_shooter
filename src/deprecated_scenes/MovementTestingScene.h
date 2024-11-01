#ifndef MOVEMENT_TESTING_SCENE_H
#define MOVEMENT_TESTING_SCENE_H

#include <string>
#include <iostream>
#include <raylib-cpp.hpp>

#include "../core/Bootstrap.h"
#include "../components/Bootstrap.h"
#include "../systems/Bootstrap.h"
#include "../utils/Bootstrap.h"

#include "MovementTestingSceneMaps.h"

class MovementTestingScene : public Scene {
  public:
    MovementTestingScene(int index, bool isContinue, float width, float height, std::string title) 
      : Scene(index, isContinue, width, height, title) {};

    void Init() override;
    void Update(int *currentSceneIndex) override;
    void Draw() override;

    void GenerateMapEntities(Entity *mapEntity, std::vector<std::vector<int>> spawnMap, std::vector<std::vector<int>> wallsMap);
    std::vector<std::vector<int>> GetSpawnMap(int index);
    std::vector<std::vector<int>> GetWallsMap(int index);
};

#endif // MOVEMENT_TESTING_SCENE_H
