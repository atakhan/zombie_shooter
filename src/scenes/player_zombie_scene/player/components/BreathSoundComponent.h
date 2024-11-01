// BreathSoundComponent.h
#ifndef BREATH_SOUND_COMPONENT_H
#define BREATH_SOUND_COMPONENT_H

struct BreathSoundComponent {
    bool inhale_;
    float current_;
    float step_;
    float min_;
    float max_;

    BreathSoundComponent(float min, float max)
        : inhale_(true)
        , current_(min)
        , step_(min)
        , min_(min)
        , max_(max)
        {}
};

#endif // BREATH_SOUND_COMPONENT_H
