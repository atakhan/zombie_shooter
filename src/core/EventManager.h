#include <vector>
#include <functional>
#include <iostream>

#include "Entity.h"

// Определение структуры CollisionEvent
struct CollisionEvent {
    Entity* entityA;
    Entity* entityB;
};

class EventManager {
public:
    void Subscribe(std::function<void(CollisionEvent)> callback) {
        callbacks.push_back(callback);
    }

    void Dispatch(CollisionEvent event) {
        for (const auto& callback : callbacks) {
            callback(event);
        }
    }

private:
    std::vector<std::function<void(CollisionEvent)>> callbacks;
};
