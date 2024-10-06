#ifndef SRC_COMPONENTS_LOOT_COMPONENT_H
#define SRC_COMPONENTS_LOOT_COMPONENT_H

struct LootComponent {
    enum class Type {
        FOOD = 1,
    };
    float amount;
    Type lootType;

    LootComponent(float amount_ = 10.0f) 
        : lootType(Type::FOOD)
        , amount(amount_) 
    {}

};

#endif // SRC_COMPONENTS_LOOT_COMPONENT_H
