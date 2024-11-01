#ifndef SRC_SCENES_MANAGE_SCENES_SCENE_MENU_COMPONENTS_STAMINA_COMPONENT_H
#define SRC_SCENES_MANAGE_SCENES_SCENE_MENU_COMPONENTS_STAMINA_COMPONENT_H

#include <raylib-cpp.hpp>

struct StaminaComponent {
    float current_;
    float max_;
    float min_;

    StaminaComponent()
        : current_(100.0f)
        , max_(100.0f)
        , min_(1.0f)
    {}
};

#endif // SRC_SCENES_MANAGE_SCENES_SCENE_MENU_COMPONENTS_STAMINA_COMPONENT_H
