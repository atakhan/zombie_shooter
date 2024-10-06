// SoundComponent.h
#ifndef SRC_COMPONENTS_SOUND_COMPONENT_H
#define SRC_COMPONENTS_SOUND_COMPONENT_H

struct SoundComponent {
    float maxRadius;
    float currentRadius;
    float minRadius;
    float isActive;
    
    SoundComponent(float radius)
        : minRadius(0.0f)
        , maxRadius(radius)
        , currentRadius(radius)
        , isActive(true) {}
};

#endif // SRC_COMPONENTS_SOUND_COMPONENT_H
