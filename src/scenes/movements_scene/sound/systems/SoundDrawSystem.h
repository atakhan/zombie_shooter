#ifndef SRC_SCENES_MOVEMENTS_SCENE_SOUND_SOUND_DRAW_SYSTEM_H
#define SRC_SCENES_MOVEMENTS_SCENE_SOUND_SOUND_DRAW_SYSTEM_H

#include <vector>
#include <raylib-cpp.hpp>
#include <iostream>

#include "../../../../Config.h"
#include "../../../../core/Bootstrap.h"
#include "../components/Bootstrap.h"

class SoundDrawSystem : public System {
  public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
    void Draw(std::vector<Entity*> *entities) override;
    // void DrawMessArea(PositionComponent* position, SoundComponent* sound);
};

#endif // SRC_SCENES_MOVEMENTS_SCENE_SOUND_SOUND_DRAW_SYSTEM_H
