// Zombie.cpp
#include "Zombie.h"

Zombie::Zombie(float health, float strength, float agility, float hearingRadius, float attackingRadius, float posX, float posY)
    : healthComponent(health)
    , attackComponent(strength)
    , speedComponent(agility)
    , hearingRadius(hearingRadius)
    , attackingRadius(attackingRadius)
    , currentState(IDLE)
    , goalComponent(posX, posY)
    , positionComponent(posX, posY) {}

void Zombie::Update() {
    if (goalComponent.Reached(positionComponent.GetPositionX(), positionComponent.GetPositionY())) {
        ChangeState(IDLE);
    } else {
        ChangeState(WALKING);
    }
    
    Move();
}

void Zombie::TakeDamage(float damage) {
    healthComponent.TakeDamage(damage);
}

void Zombie::SetGoal(float x, float y) {
    goalComponent.SetPosition(x, y);
}

void Zombie::Move() {
    float newPosX = 0.0f;
    float newPosY = 0.0f;
    switch (currentState) {
        case IDLE:
            std::cout << "Zombie is idle." << std::endl;
            break;
        case WALKING:
            MoveTo(speedComponent.GetSpeed() * 0.5f);
            break;
        case RUNNING:
            MoveTo(speedComponent.GetSpeed());
            newPosX = positionComponent.GetPositionX() + speedComponent.GetSpeed();
            newPosY = positionComponent.GetPositionY();
            positionComponent.SetPosition(newPosX, newPosY);
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

void Zombie::Draw() {
    DrawCircle(positionComponent.GetPositionX(), positionComponent.GetPositionY(), healthComponent.GetHealth(), GRAY);
}

void Zombie::MoveTo(float speed) {
    // Calculate the direction vector
    float targetX = goalComponent.GetPositionX();
    float targetY = goalComponent.GetPositionY();
    float posX = positionComponent.GetPositionX();
    float posY = positionComponent.GetPositionY();
    float deltaX = targetX - posX;
    float deltaY = targetY - posY;
    float distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);

    // Normalize the direction vector
    if (distance > 0) {
        float moveX = (deltaX / distance) * speed;
        float moveY = (deltaY / distance) * speed;

        // Update position
        posX += moveX;
        posY += moveY;

        positionComponent.SetPosition(posX, posY);

        // Check if the circle has reached the target
        if (std::abs(deltaX) < speed && std::abs(deltaY) < speed) {
            posX = targetX;
            posY = targetY;
        }
    }
}
