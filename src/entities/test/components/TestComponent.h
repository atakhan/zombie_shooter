#ifndef SRC_SCENES_MANAGE_SCENES_SCENE_MENU_COMPONENTS_TEST_COMPONENT_H
#define SRC_SCENES_MANAGE_SCENES_SCENE_MENU_COMPONENTS_TEST_COMPONENT_H

#include <raylib-cpp.hpp>

struct TestComponent {
    bool isVisible_;
    
    TestComponent()
        : isVisible_(true)
    {}
};

#endif // SRC_SCENES_MANAGE_SCENES_SCENE_MENU_COMPONENTS_TEST_COMPONENT_H
