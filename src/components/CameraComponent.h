#ifndef SRC_COMPONENTS_CAMERA_COMPONENT_H
#define SRC_COMPONENTS_CAMERA_COMPONENT_H

#include <raylib-cpp.hpp>

struct CameraComponent {
    Camera2D camera_;

    CameraComponent() : camera_({0}) {}
};

#endif // SRC_COMPONENTS_CAMERA_COMPONENT_H
