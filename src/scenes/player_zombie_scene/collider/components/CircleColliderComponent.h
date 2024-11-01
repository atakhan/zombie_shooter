#ifndef SRC_SCENES_PLAYER_ZOMBIE_SCENE_COLLIDER_COMPONENTS_CIRCLE_COLLIDER_COMPONENT_H
#define SRC_SCENES_PLAYER_ZOMBIE_SCENE_COLLIDER_COMPONENTS_CIRCLE_COLLIDER_COMPONENT_H

#include <raylib-cpp.hpp>
#include <queue>

struct CircleColliderComponent {
    bool isCollide_;
    float radius_;
    std::queue<unsigned> collisions_;

    CircleColliderComponent(float radius)
        : isCollide_(false)
        , radius_(radius)
        , collisions_() 
    {}
};

#endif // SRC_SCENES_PLAYER_ZOMBIE_SCENE_COLLIDER_COMPONENTS_CIRCLE_COLLIDER_COMPONENT_H
