#ifndef SRC_SYSTEMS_PLAYER_PLAYER_CAMERA_SYSTEM_H
#define SRC_SYSTEMS_PLAYER_PLAYER_CAMERA_SYSTEM_H

#include "../../../../Config.h"
#include "../../../../core/Bootstrap.h"
#include "../components/Bootstrap.h"

class PlayerCameraSystem : public System {
  public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
    void Draw(std::vector<Entity*> *entities) override;
};

#endif // SRC_SYSTEMS_PLAYER_PLAYER_CAMERA_SYSTEM_H
