// Zombie.cpp
#include "Zombie.h"

Zombie::Zombie(float health, float strength, float agility, float hearingRadius)
    : healthComponent(health), attackComponent(strength), speedComponent(agility), hearingRadius(hearingRadius), currentState(IDLE), positionComponent(0, 0) {}

void Zombie::Update(float playerX, float playerY) {
    float distanceToPlayer = std::sqrt(std::pow(playerX - positionComponent.GetPositionX(), 2) + std::pow(playerY - positionComponent.GetPositionY(), 2));

    if (distanceToPlayer < hearingRadius) {
        ChangeState(ATTACKING);
    } else if (currentState == ATTACKING) {
        ChangeState(WALKING);
    } else {
        ChangeState(IDLE);
    }

    Move();
}

void Zombie::Move() {
    switch (currentState) {
        case IDLE:
            std::cout << "Zombie is idle." << std::endl;
            break;
        case WALKING:
            positionComponent.SetPosition(positionComponent.GetPositionX() + speedComponent.GetSpeed() * 0.5f, positionComponent.GetPositionY());
            std::cout << "Zombie is walking. Position: (" << positionComponent.GetPositionX() << ", " << positionComponent.GetPositionY() << ")" << std::endl;
            break;
        case RUNNING:
            positionComponent.SetPosition(positionComponent.GetPositionX() + speedComponent.GetSpeed(), positionComponent.GetPositionY());
            std::cout << "Zombie is running. Position: (" << positionComponent.GetPositionX() << ", " << positionComponent.GetPositionY() << ")" << std::endl;
            break;
        case ATTACKING:
            Attack();
            break;
    }
}

void Zombie::Attack() {
    std::cout << "Zombie attacks with strength: " << attackComponent.GetAttackStrength() << std::endl;
}

void Zombie::Die() {
    std::cout << "Zombie died." << std::endl;
    healthComponent.TakeDamage(healthComponent.GetHealth()); // Уменьшаем здоровье до 0
}

void Zombie::ChangeState(State newState) {
    if (newState != currentState) {
        currentState = newState;
        switch (currentState) {
            case IDLE:
                std::cout << "Zombie changed to IDLE state." << std::endl;
                break;
            case WALKING:
                std::cout << "Zombie changed to WALKING state." << std::endl;
                break;
            case RUNNING:
                std::cout << "Zombie changed to RUNNING state." << std::endl;
                break;
            case ATTACKING:
                std::cout << "Zombie changed to ATTACKING state." << std::endl;
                break;
        }
    }
}
