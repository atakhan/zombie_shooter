#include "CameraEntity.h"
#include <iostream>

void CameraEntity::SetTarget(Vector2 pos) {
    camera_.target = pos;
}
void CameraEntity::SetOffset(Vector2 offset) {
    camera_.offset = offset;
}
void CameraEntity::SetRotation(float rotation) {
    camera_.rotation = rotation;
}
void CameraEntity::SetZoom(float zoom) {
    camera_.zoom = zoom;
}

Camera2D CameraEntity::GetCamera() {
    return camera_;
}
