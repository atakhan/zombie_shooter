#ifndef HEALTH_COMPONENT_H
#define HEALTH_COMPONENT_H

struct HealthComponent {
    float health_;
    
    HealthComponent(float initialHealth) : health_(initialHealth) {}
};

#endif // HEALTH_COMPONENT_H
