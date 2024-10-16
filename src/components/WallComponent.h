#ifndef SRC_COMPONENTS_WALL_COMPONENT_H
#define SRC_COMPONENTS_WALL_COMPONENT_H

#include <raylib-cpp.hpp>

struct WallComponent {
    bool active_;

    WallComponent() : active_(true) {}
};
// bool WallComponent::Reached(float currentPosX, float currentPosY) {
//     const float epsilon = 1.0f; // Define a small threshold for comparison

//     // Check if the current position is within epsilon of the target position
//     if (std::abs(currentPosX - posX) < epsilon && std::abs(currentPosY - posY) < epsilon) {
//         return true;
//     }
//     return false;
// }
#endif // SRC_COMPONENTS_WALL_COMPONENT_H
