// Zombie.cpp
#include "Zombie.h"

Zombie::Zombie(float posX, float posY, float health, float strength, float agility, float hearingRadius, float attackingRadius)
    : health_(health)
    , attack_(strength)
    , speed_(agility)
    , hearingRadius_(hearingRadius)
    , attackingRadius_(attackingRadius)
    , currentState_(IDLE)
    , goal_(posX, posY)
    , position_(posX, posY)
    , sound_(Config::SOUND_MIN_RADIUS, Config::SOUND_MIN_RADIUS, Config::SOUND_MAX_RADIUS, true)
    {}

void Zombie::TakeDamage(float damage) {
    health_.TakeDamage(damage);
}

void Zombie::SetGoal(float x, float y) {
    goal_.SetPosition(x, y);
}

bool Zombie::GoalReached() {
    return goal_.Reached(position_.GetX(), position_.GetY());
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

PositionComponent *Zombie::FindFood(std::vector<Entity*> *entities) {
    PositionComponent *result = nullptr;
    Player *player = nullptr;
    for (const auto& entity : *entities) {
        if (dynamic_cast<Player*>(entity)) {
            player = static_cast<Player*>(entity);
        }
    }
    if (player) {
        float player_pos_x = player->GetPositionX();
        float player_pos_y = player->GetPositionY();
        float pos_x_dif = player_pos_x - position_.GetX();
        float pos_y_dif = player_pos_y - position_.GetY();
        float radius_dif = player->GetSoundRadius() + health_.GetHealth();
        // if collide
        if (fabs(((pos_x_dif * pos_x_dif) + (pos_y_dif * pos_y_dif))) <= (radius_dif * radius_dif)) {
            if (!result) {
                result = new PositionComponent(player_pos_x, player_pos_y);
            }
        }
    }

    return result;
}

void Zombie::Walk() {
    MoveToGoal(speed_.GetSpeed() * Config::WALK_COEF);
}

void Zombie::Run() {
    MoveToGoal(speed_.GetSpeed() * Config::RUN_COEF);
}

void Zombie::Move() {
    if (goal_.Reached(position_.GetX(), position_.GetY())) {
        IdleState();
    } else {
        goal_.SetActive(true);
        float newPosX = 0.0f;
        float newPosY = 0.0f;
        switch (currentState_) {
            case IDLE:
                std::cout << "Zombie is idle." << std::endl;
                break;
            case WALKING:
                MoveToGoal(speed_.GetSpeed() * 0.5f);
                break;
            case RUNNING:
                MoveToGoal(speed_.GetSpeed() * 1.5);
                break;
            case ATTACKING:
                Attack();
                break;
        }
    }
}

void Zombie::IdleState() {
    ChangeState(IDLE);
    goal_.SetActive(false);
}

void Zombie::AttackState() {
    ChangeState(RUNNING);
}

void Zombie::RunningState() {
    ChangeState(RUNNING);
}

void Zombie::WalkingState() {
    ChangeState(WALKING);
}

void Zombie::Attack() {
    std::cout << "Zombie attacked." << std::endl;
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
    DrawCircle(position_.GetX(), position_.GetY(), health_.GetHealth(), Config::ZOMBIE_COLOR);
    DrawCircle(goal_.GetX(), goal_.GetY(), 3, Config::GOAL_COLOR);
    DrawLine(position_.GetX(), position_.GetY(), goal_.GetX(), goal_.GetY(), RED);
}

void Zombie::MoveToGoal(float speed) {
    // Calculate the direction vector
    float targetX = goal_.GetX();
    float targetY = goal_.GetY();
    float posX = position_.GetX();
    float posY = position_.GetY();
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
