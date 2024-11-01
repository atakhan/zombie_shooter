#ifndef SRC_COMPONENTS_STAMINA_COMPONENT_H
#define SRC_COMPONENTS_STAMINA_COMPONENT_H

struct StaminaComponent {
    float currentValue_;
    float maxValue_;
    
    StaminaComponent(float initial) : maxValue_(initial), currentValue_(initial) {}
};

#endif // SRC_COMPONENTS_STAMINA_COMPONENT_H
