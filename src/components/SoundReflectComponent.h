// SpawnMapComponent.h
#ifndef SRC_COMPONENTS_SOUND_REFLECT_COMPONENT_H
#define SRC_COMPONENTS_SOUND_REFLECT_COMPONENT_H

#include <vector>

struct SoundReflectComponent {
    std::vector<std::pair<int, int>> frequencies_;

    
    SoundReflectComponent(std::vector<std::pair<int, int>> frequencies)
        : frequencies_(frequencies)
        {}
};

#endif // SRC_COMPONENTS_SOUND_REFLECT_COMPONENT_H
