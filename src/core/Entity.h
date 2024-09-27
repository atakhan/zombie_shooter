// Entity.h
#ifndef ENTITY_H
#define ENTITY_H

class Entity {
public:
    virtual void Draw() = 0;
    virtual ~Entity() {}
};

#endif // ENTITY_H


// #include <unordered_map>
// #include <typeindex>
// #include <typeinfo>

// class Entity {
// public:
//     // Method to add a component to the entity
//     template <typename T>
//     void AddComponent(T component) {
//         components[typeid(T)] = new T(component);
//     }

//     // Method to check if the entity has a specific component type
//     template <typename T>
//     bool HasComponent() const {
//         return components.find(typeid(T)) != components.end();
//     }

// private:
//     std::unordered_map<std::type_index, void*> components; // Stores components by type
// };