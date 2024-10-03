#ifndef LOOT_COMPONENT_H
#define LOOT_COMPONENT_H

struct LootComponent {
    enum class Type {
        FOOD = 1,
    };
    float amount;
    Type current;

    LootComponent(float amount_ = 1.0f) 
        : current(Type::FOOD)
        , amount(amount_) 
    {}

};

#endif // LOOT_COMPONENT_H
