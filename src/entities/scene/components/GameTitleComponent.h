#ifndef SRC_ENTITIES_SCENE_COMPONENTS_GAME_TITLE_COMPONENT_H
#define SRC_ENTITIES_SCENE_COMPONENTS_GAME_TITLE_COMPONENT_H

#include <raylib-cpp.hpp>

struct GameTitleComponent {
    std::string title;

    GameTitleComponent(std::string gameTitle)
        : title(gameTitle)
    {}
};

#endif // SRC_ENTITIES_SCENE_COMPONENTS_GAME_TITLE_COMPONENT_H
