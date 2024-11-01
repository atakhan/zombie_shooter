#ifndef SOUND_DRAW_SYSTEM_H
#define SOUND_DRAW_SYSTEM_H

#include <vector>
#include <raylib-cpp.hpp>

#include "../../../Config.h"
#include "../../../core/Bootstrap.h"
#include "../components/Bootstrap.h"

class SoundDrawSystem : public System {
  public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
    void Draw(std::vector<Entity*> *entities) override;
};

#endif // SOUND_DRAW_SYSTEM_H
