// Entity.h
#ifndef ENTITY_H
#define ENTITY_H

#include <unordered_map>
#include <typeindex>
#include <typeinfo>

class Entity {
public:
    std::unordered_map<std::type_index, void*> components; // Stores components by type

    // Method to add a component to the entity
    template <typename T>
    void AddComponent(T component) {
        components[typeid(T)] = new T(component);
    }

    // Method to check if the entity has a specific component type
    template <typename T>
    bool HasComponent() const {
        return components.find(typeid(T)) != components.end();
    }

    template<typename T>
    T* GetComponent() {
        auto it = components.find(typeid(T));
        if (it != components.end()) {
            return static_cast<T*>(it->second);
        }
        return nullptr;
    }

};
#endif // ENTITY_H
