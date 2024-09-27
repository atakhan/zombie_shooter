#ifndef CAMERASYSTEM_H
#define CAMERASYSTEM_H

#include "../core/System.h"
#include "../core/Entity.h"
#include "../entities/Player.h"

class CameraSystem : public System {
  public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
};

#endif // CAMERASYSTEM_H
