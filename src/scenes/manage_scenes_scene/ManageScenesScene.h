#ifndef MANAGE_SCENES_SCENE
#define MANAGE_SCENES_SCENE

#include <string>
#include <raylib-cpp.hpp>

#include "../../Config.h"
#include "../../core/Bootstrap.h"
#include "../Tools.h"
#include "./menu/Bootstrap.h"

class ManageScenesScene : public Scene {
  struct TextPack {
      float fontSize_;
      float textSpacing_;
      float lineSpacing_;
      Color defaultColor_;
      Color selectedColor_;
      Vector2 position_;
  };

  public:
    ManageScenesScene(int index, bool isContinue, float width, float height, std::string title) 
      : Scene(index, isContinue, width, height, title) {};
  
    void Init() override;
    void Update(int *currentSceneIndex) override;
    void Draw() override;

    Entity* CreateMenu(MenuComponent* menu);
    Entity* CreateMenuItem(MenuComponent *menu, MenuItemComponent *menuItem);
};

#endif // MANAGE_SCENES_SCENE