#ifndef SRC_SCENES_PLAYER_ZOMBIE_SCENE_PLAYER_ZOMBIE_SCENE_H
#define SRC_SCENES_PLAYER_ZOMBIE_SCENE_PLAYER_ZOMBIE_SCENE_H

#include <string>
#include <iostream>
#include <raylib-cpp.hpp>

#include "../../Config.h"
#include "../../core/Bootstrap.h"
#include "../Tools.h"

#include "PlayerZombieSceneMaps.h"

#include "player/Bootstrap.h"
#include "zombie/Bootstrap.h"
#include "collider/Bootstrap.h"
#include "debug/Bootstrap.h"

class PlayerZombieScene : public Scene {
  public:
    PlayerZombieScene(int index, bool isContinue, float width, float height, std::string title) 
      : Scene(index, isContinue, width, height, title) {};

    void Init() override;
    void Update(int *currentSceneIndex) override;
    void Draw() override;

    void GenerateMapEntities(Entity *mapEntity, std::vector<std::vector<int>> spawnMap, std::vector<std::vector<int>> wallsMap);
    std::vector<std::vector<int>> GetSpawnMap(int index);
    std::vector<std::vector<int>> GetWallsMap(int index);
};

#endif // SRC_SCENES_PLAYER_ZOMBIE_SCENE_PLAYER_ZOMBIE_SCENE_H