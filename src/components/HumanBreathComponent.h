#ifndef HUMAN_BREATH_COMPONENT_H
#define HUMAN_BREATH_COMPONENT_H

struct HumanBreathComponent {
    float inhale;
    float inhaleValue;
    float lungsCapacity;
    
    HumanBreathComponent(bool in, float value, float capacity)
        : inhale(in)
        , inhaleValue(value)
        , lungsCapacity(capacity)
    {}
};

#endif // HUMAN_BREATH_COMPONENT_H
