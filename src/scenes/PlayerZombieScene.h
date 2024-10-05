#ifndef PLAYER_ZOMBIE_SCENE
#define PLAYER_ZOMBIE_SCENE

#include "../core/Bootstrap.h"
#include "../components/Bootstrap.h"
#include "../systems/Bootstrap.h"
#include "SceneTools.h"

class PlayerZombieScene : public Scene {
    void Init() override;
    void Update() override;
    void Draw() override;
};

#endif // PLAYER_ZOMBIE_SCENE