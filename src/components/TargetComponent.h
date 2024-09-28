#ifndef TARGET_COMPONENT_H
#define TARGET_COMPONENT_H

#include <raylib-cpp.hpp>

struct TargetComponent {
    Vector2 position_;
    bool active_;

    TargetComponent(float x, float y) : position_((Vector2){x, y}), active_(true) {}
};
// bool TargetComponent::Reached(float currentPosX, float currentPosY) {
//     const float epsilon = 1.0f; // Define a small threshold for comparison

//     // Check if the current position is within epsilon of the target position
//     if (std::abs(currentPosX - posX) < epsilon && std::abs(currentPosY - posY) < epsilon) {
//         return true;
//     }
//     return false;
// }
#endif // TARGET_COMPONENT_H
