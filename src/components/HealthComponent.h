// HealthComponent.h
#ifndef HEALTHCOMPONENT_H
#define HEALTHCOMPONENT_H

class HealthComponent {
public:
    HealthComponent(float initialHealth);
    void TakeDamage(float damage);
    float GetHealth() const;

private:
    float health;
};

#endif // HEALTHCOMPONENT_H
