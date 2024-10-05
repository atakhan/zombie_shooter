#ifndef STAMINA_COMPONENT_H
#define STAMINA_COMPONENT_H

struct StaminaComponent {
    float currentValue_;
    float maxValue_;
    
    StaminaComponent(float initial) : maxValue_(initial), currentValue_(initial) {}
};

#endif // STAMINA_COMPONENT_H
