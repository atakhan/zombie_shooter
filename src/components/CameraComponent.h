// AttackComponent.h
#ifndef CAMERA_COMPONENT_H
#define CAMERA_COMPONENT_H

#include <raylib-cpp.hpp>

struct CameraComponent {
    Camera2D camera_;

    CameraComponent() : camera_() {}
};

#endif // CAMERA_COMPONENT_H
