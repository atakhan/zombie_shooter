#ifndef MANAGE_SCENES_SCENE
#define MANAGE_SCENES_SCENE

#include "../core/Bootstrap.h"
#include "../components/Bootstrap.h"
#include "../systems/Bootstrap.h"
#include "SceneTools.h"

class ManageScenesScene : public Scene {
    void Init() override;
    void Update() override;
    void Draw() override;
};

#endif // MANAGE_SCENES_SCENE