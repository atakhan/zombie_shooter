// SoundComponent.h
#ifndef SOUND_COMPONENT_H
#define SOUND_COMPONENT_H

struct SoundComponent {
    float maxRadius;
    float currentRadius;
    float minRadius;
    float isActive;
    
    SoundComponent(float currentR, float minR, float maxR, bool active)
        : maxRadius(currentR)
        , currentRadius(minR)
        , minRadius(maxR)
        , isActive(active) {}
};

#endif // SOUND_COMPONENT_H
