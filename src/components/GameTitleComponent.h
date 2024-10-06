#ifndef SRC_COMPONENTS_GAME_TITLE_COMPONENT_H
#define SRC_COMPONENTS_GAME_TITLE_COMPONENT_H

#include <raylib-cpp.hpp>

struct GameTitleComponent {
    std::string title;

    GameTitleComponent(std::string gameTitle)
        : title(gameTitle)
    {}
};

#endif // SRC_COMPONENTS_GAME_TITLE_COMPONENT_H
