#ifndef PLAYER_ZOMBIE_SCENE
#define PLAYER_ZOMBIE_SCENE

#include <string>
#include <iostream>

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
};

#endif // PLAYER_ZOMBIE_SCENE