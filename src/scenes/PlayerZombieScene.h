#ifndef PLAYER_ZOMBIE_SCENE
#define PLAYER_ZOMBIE_SCENE

#include <string>
#include <iostream>
#include <raylib-cpp.hpp>

#include "../core/Bootstrap.h"
#include "../components/Bootstrap.h"
#include "../systems/Bootstrap.h"
#include "../utils/Bootstrap.h"

class PlayerZombieScene : public Scene {
  public:
    PlayerZombieScene(int index, bool isContinue, float width, float height, std::string title) 
      : Scene(index, isContinue, width, height, title) {};

    void Init() override;
    void Update(int *currentSceneIndex) override;
    void Draw() override;

    void GenerateMapEntities(Entity *mapEntity, std::vector<std::vector<int>> spawnMap, std::vector<std::vector<int>> wallsMap);
    std::vector<std::vector<int>> GetSpawnMap();
    std::vector<std::vector<int>> GetWallsMap();
};

#endif // PLAYER_ZOMBIE_SCENE