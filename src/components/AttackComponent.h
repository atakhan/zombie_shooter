// AttackComponent.h
#ifndef ATTACKCOMPONENT_H
#define ATTACKCOMPONENT_H

class AttackComponent {
public:
    AttackComponent(float attackStrength, float radius);
    float GetAttackStrength() const;
    float GetRadius() const;

private:
    float attackStrength_;
    float radius_;
};

#endif // ATTACKCOMPONENT_H
