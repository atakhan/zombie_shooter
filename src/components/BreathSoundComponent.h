// BreathSoundComponent.h
#ifndef BREATH_SOUND_COMPONENT_H
#define BREATH_SOUND_COMPONENT_H

struct BreathSoundComponent {
    bool inhale;
    float currentValue;
    float minValue;
    float maxValue;

    BreathSoundComponent(float min, float max)
        : currentValue(min)
        , minValue(min)
        , maxValue(max)
        {}
};

#endif // BREATH_SOUND_COMPONENT_H
