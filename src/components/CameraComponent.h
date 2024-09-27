// AttackComponent.h
#ifndef CAMERACOMPONENT_H
#define CAMERACOMPONENT_H

#include <raylib-cpp.hpp>

class CameraComponent {
public:
    CameraComponent();
    Vector2 GetTarget() const;
    Vector2 GetOffset() const;
    float GetRotation() const;
    float GetZoom() const;
    void SetTarget(Vector2 target);
    void SetOffset(Vector2 offset);
    void SetRotation(float rotation);
    void SetZoom(float zoom);
    Camera2D GetCamera();

private:
    Camera2D camera_;
};

#endif // CAMERACOMPONENT_H
