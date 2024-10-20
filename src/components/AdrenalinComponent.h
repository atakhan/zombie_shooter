// AdrenalinComponent.h
#ifndef ADRENALIN_COMPONENT_H
#define ADRENALIN_COMPONENT_H

struct AdrenalinComponent {
    float currentValue;
    float minValue;
    float maxValue;

    AdrenalinComponent(float min, float max)
        : currentValue(min)
        , minValue(min)
        , maxValue(max)
        {}
};

#endif // ADRENALIN_COMPONENT_H
