// BreathComponent.h
#ifndef BREATH_COMPONENT_H
#define BREATH_COMPONENT_H

struct BreathComponent {
    float currentValue;
    float minValue;
    float maxValue;

    BreathComponent(float min, float max)
        : currentValue(min)
        , minValue(min)
        , maxValue(max)
        {}
};

#endif // BREATH_COMPONENT_H
