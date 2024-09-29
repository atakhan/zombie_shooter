// AttackComponent.h
#ifndef ATTACK_COMPONENT_H
#define ATTACK_COMPONENT_H

struct AttackComponent {
    float attackStrength_;
    float radius_;
    AttackComponent(float attackStrength, float radius)
        : attackStrength_(attackStrength)
        , radius_(radius) {}
};

#endif // ATTACK_COMPONENT_H
