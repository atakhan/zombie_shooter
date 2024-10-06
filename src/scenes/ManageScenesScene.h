#ifndef MANAGE_SCENES_SCENE
#define MANAGE_SCENES_SCENE

#include <string>
#include "../core/Bootstrap.h"
#include "../components/Bootstrap.h"
#include "../systems/Bootstrap.h"
#include "../utils/Bootstrap.h"

class ManageScenesScene : public Scene {
  public:
    ManageScenesScene(int index, bool isContinue, float width, float height, std::string title) 
      : Scene(index, isContinue, width, height, title) {};
  
    void Init() override;
    void Update(int *currentSceneIndex) override;
    void Draw() override;
};

#endif // MANAGE_SCENES_SCENE