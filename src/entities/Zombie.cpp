// Zombie.cpp
#include "Zombie.h"

Zombie::Zombie(float health, float strength, float agility, float hearingRadius, float attackingRadius, float posX, float posY)
    : health_(health)
    , attack_(strength)
    , speed_(agility)
    , hearingRadius_(hearingRadius)
    , attackingRadius_(attackingRadius)
    , currentState_(IDLE)
    , goal_(posX, posY)
    , position_(posX, posY)
    , sound_(100.0f, true) {}

void Zombie::TakeDamage(float damage) {
    health_.TakeDamage(damage);
}

void Zombie::SetGoal(float x, float y) {
    goal_.SetPosition(x, y);
}

bool Zombie::GoalReached() {
    return goal_.Reached(position_.GetPositionX(), position_.GetPositionY());
}

bool Zombie::HasGoal() {
    return goal_.IsActive();
}

void Zombie::FindRandomGoal() {
    int min = 0;
    int xmax = Config::WINDOW_WIDTH;
    int ymax = Config::WINDOW_HEIGHT;
    int randX = rand()%(xmax-min + 1) + min;
    int randY = rand()%(ymax-min + 1) + min;

    SetGoal(randX, randY);
}

// TODO
PositionComponent *Zombie::FindEat(std::vector<Entity*> *entities) {
    Player *player = nullptr;
    for (const auto& entity : *entities) {
        if (dynamic_cast<Player*>(entity)) {
            player = static_cast<Player*>(entity);
        }
    }
    if (player) {
        float player_pos_x = player->GetPositionX();
        float player_pos_y = player->GetPositionY();
        player->GetSoundRadius();
    }
    // return new PositionComponent(400.0f, 400.0f);
    return nullptr;
}

void Zombie::Idle() {
    ChangeState(IDLE);
    goal_.SetActive(false);
}

void Zombie::Move() {
    if (goal_.Reached(position_.GetPositionX(), position_.GetPositionY())) {
        Idle();
    } else {
        ChangeState(WALKING);
        goal_.SetActive(true);
        float newPosX = 0.0f;
        float newPosY = 0.0f;
        switch (currentState_) {
            case IDLE:
                std::cout << "Zombie is idle." << std::endl;
                break;
            case WALKING:
                MoveTo(speed_.GetSpeed() * 0.5f);
                break;
            case RUNNING:
                MoveTo(speed_.GetSpeed());
                break;
            case ATTACKING:
                Attack();
                break;
        }
    }
}

void Zombie::Attack() {
    std::cout << "Zombie attacks with strength: " << attack_.GetAttackStrength() << std::endl;
}

void Zombie::Die() {
    std::cout << "Zombie died." << std::endl;
    health_.TakeDamage(health_.GetHealth());
}

void Zombie::ChangeState(State newState) {
    if (newState != currentState_) {
        currentState_ = newState;
        switch (currentState_) {
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
    DrawCircle(position_.GetPositionX(), position_.GetPositionY(), health_.GetHealth(), GRAY);
    DrawCircle(goal_.GetPositionX(), goal_.GetPositionY(), 3, raylib::Color(255U, 155U, 155U, 255U));
    DrawLine(position_.GetPositionX(), position_.GetPositionY(), goal_.GetPositionX(), goal_.GetPositionY(), RED);
}

void Zombie::MoveTo(float speed) {
    // Calculate the direction vector
    float targetX = goal_.GetPositionX();
    float targetY = goal_.GetPositionY();
    float posX = position_.GetPositionX();
    float posY = position_.GetPositionY();
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

        position_.SetPosition(posX, posY);

        // Check if the circle has reached the target
        if (std::abs(deltaX) < speed && std::abs(deltaY) < speed) {
            posX = targetX;
            posY = targetY;
        }
    }
}
