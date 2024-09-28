// AttackComponent.h
#ifndef CAMERA_COMPONENT_H
#define CAMERA_COMPONENT_H

#include <raylib-cpp.hpp>

struct CameraComponent {
    Camera2D camera_;

    CameraComponent::CameraComponent() 
        : camera_{0}
    {}
};

#endif // CAMERA_COMPONENT_H
