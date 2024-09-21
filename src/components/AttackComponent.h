// AttackComponent.h
#ifndef ATTACKCOMPONENT_H
#define ATTACKCOMPONENT_H

class AttackComponent {
public:
    AttackComponent(float attackStrength);
    float GetAttackStrength() const;

private:
    float attackStrength;
};

#endif // ATTACKCOMPONENT_H
