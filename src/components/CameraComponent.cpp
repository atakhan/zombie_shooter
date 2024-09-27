#include "CameraComponent.h"

CameraComponent::CameraComponent() 
    : camera_{ 0 }
{}

Vector2 CameraComponent::GetTarget() const {
    return camera_.target;
}

Vector2 CameraComponent::GetOffset() const {
    return camera_.offset;
}

float CameraComponent::GetRotation() const {
    return camera_.rotation;
}

float CameraComponent::GetZoom() const {
    return camera_.zoom;
}

void CameraComponent::SetTarget(Vector2 target) {
    camera_.target = target;
}

void CameraComponent::SetOffset(Vector2 offset) {
    camera_.offset = offset;
}

void CameraComponent::SetRotation(float rotation) {
    camera_.rotation = rotation;
}

void CameraComponent::SetZoom(float zoom) {
    camera_.zoom = zoom;
}

Camera2D CameraComponent::GetCamera() {
    return camera_;
}
