#ifndef MANAGE_SCENES_SCENE
#define MANAGE_SCENES_SCENE

#include <string>
#include "../core/Bootstrap.h"
#include "../components/Bootstrap.h"
#include "../systems/Bootstrap.h"
#include "../utils/Bootstrap.h"

class ManageScenesScene : public Scene {
  public:
  
    ManageScenesScene(std::string title) : Scene(title) {};
  
    void Init() override;
    void Update() override;
    void Draw() override;
};

#endif // MANAGE_SCENES_SCENE