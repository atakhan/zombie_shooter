// InputSystem.h
#ifndef CAMERA_SYSTEM_H
#define CAMERA_SYSTEM_H

#include "../core/System.h"
#include "../core/Entity.h"
#include "../entities/Player.h"
#include "../entities/CameraEntity.h"

class CameraSystem : public System {
public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
};

#endif // CAMERA_SYSTEM_H
