#ifndef SRC_SCENES_MANAGE_SCENES_SCENE_MENU_SYSTEMS_HUMAN_DRAW_SYSTEM_H
#define SRC_SCENES_MANAGE_SCENES_SCENE_MENU_SYSTEMS_HUMAN_DRAW_SYSTEM_H

#include <vector>
#include <string>

#include "../../../Config.h"
#include "../../../core/Bootstrap.h"
#include "../components/Bootstrap.h"

class HumanDrawSystem : public System {
  public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
    void Draw(std::vector<Entity*> *entities) override;

    void DrawBody(HumanComponent *human);
    void DrawHumanInfo(Entity *entity);
    void DEBUG_DrawTitleValueText(
      Color color, 
      Vector2 position, 
      float padding, 
      float rowNum, 
      std::string title, 
      std::string value
    );
};

#endif // SRC_SCENES_MANAGE_SCENES_SCENE_MENU_SYSTEMS_HUMAN_DRAW_SYSTEM_H
