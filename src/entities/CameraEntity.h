#ifndef CAMERA_ENTITY_H
#define CAMERA_ENTITY_H

#include <iostream>
#include <cmath>
#include <raylib-cpp.hpp>

#include "../Config.h"
#include "../core/Entity.h"

class CameraEntity : public Entity {
public:
    CameraEntity() : camera_{0} {}
    void Draw() override;
    void SetTarget(Vector2 pos);
    void SetOffset(Vector2 offset);
    void SetRotation(float rotation);
    void SetZoom(float zoom);
    
    Camera2D GetCamera();

private:
    Camera2D camera_;
};

#endif // CAMERA_ENTITY_H
