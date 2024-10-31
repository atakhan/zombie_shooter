#ifndef SRC_COMPONENTS_HEALTH_COMPONENT_H
#define SRC_COMPONENTS_HEALTH_COMPONENT_H

struct HealthComponent {
    float health_;
    
    HealthComponent(float initialHealth) : health_(initialHealth) {}
};

#endif // SRC_COMPONENTS_HEALTH_COMPONENT_H
