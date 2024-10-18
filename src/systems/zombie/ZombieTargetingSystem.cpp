#include "ZombieTargetingSystem.h"

void ZombieTargetingSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Zombie targeting System Initialized" << std::endl;
}

void ZombieTargetingSystem::Draw(std::vector<Entity*> *entities) {}

void ZombieTargetingSystem::Update(std::vector<Entity*> *entities) {
    Entity *terrain = GetEntityByComponent<TerrainComponent>(entities);
    if (terrain == nullptr) { return; }
    
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    if (player == nullptr) { return; }
    
    TerrainComponent* terrainComponent = terrain->GetComponent<TerrainComponent>();
    
    PositionComponent* playerPosition = player->GetComponent<PositionComponent>();
    SoundComponent* playerSound = player->GetComponent<SoundComponent>();
    HealthComponent* playerHealth = player->GetComponent<HealthComponent>();

    for (auto& entity : *entities) {
        if (!entity->HasComponent<ZombieComponent>()) {
            continue;
        }
        ZombieComponent* zombie = entity->GetComponent<ZombieComponent>();
        TargetComponent* target = entity->GetComponent<TargetComponent>();
        PositionComponent* zombiePos = entity->GetComponent<PositionComponent>();
        HealthComponent* zombieRadius = entity->GetComponent<HealthComponent>();
        SpeedComponent* speed = entity->GetComponent<SpeedComponent>();
        AttackComponent* attack = entity->GetComponent<AttackComponent>();
        CircleColliderComponent* collider = entity->GetComponent<CircleColliderComponent>();
        
        if (target && zombiePos && zombieRadius && speed && attack && collider) {
            bool foodNear = IsFoodNear(
                zombiePos->position_, 
                playerPosition->position_, 
                zombieRadius->health_, 
                playerSound->currentRadius
            );

            if (foodNear) {
                zombie->currentState = ZombieComponent::Status::RUN;
                target->position_ = playerPosition->position_;
            } else {
                zombie->currentState = ZombieComponent::Status::WALK;
                if (TargetReached(target->position_, zombiePos->position_)) {
                    target->position_ = RandomTarget(
                        terrainComponent->width_ * terrainComponent->cellWidth_, 
                        terrainComponent->height_ * terrainComponent->cellHeight_
                    );
                }
                if (collider->isCollide_) {
                    target->position_ = RandomTarget(
                        terrainComponent->width_ * terrainComponent->cellWidth_, 
                        terrainComponent->height_ * terrainComponent->cellHeight_
                    );
                }
            }
        }
    }
}

bool ZombieTargetingSystem::IsFoodNear(Vector2 zombiePos,Vector2 playerPos, float zombieRadius, float playerSoundRadius) {
    Vector2 result;

    float posXDif = playerPos.x - zombiePos.x;
    float posYDif = playerPos.y - zombiePos.y;
    float radiusSum = playerSoundRadius + zombieRadius;
    
    if (fabs(((posXDif * posXDif) + (posYDif * posYDif))) <= (radiusSum * radiusSum)) {
        return true;
    }

    return false;
}

Vector2 ZombieTargetingSystem::RandomTarget(float xMax, float yMax) {
    int min = 10;
    int randX = rand() % ((int)xMax - min + 1) + min;
    int randY = rand() % ((int)yMax - min + 1) + min;

    return (Vector2){static_cast<float>(randX), static_cast<float>(randY)};
}

bool ZombieTargetingSystem::TargetReached(Vector2 targetPos, Vector2 curPos) {
    float distanceX = targetPos.x - curPos.x;
    float distanceY = targetPos.y - curPos.y;
    float distance = std::sqrt(std::pow(distanceX, 2) + std::pow(distanceY, 2));
    
    if (Config::HUMAN_MOVE_TRESHOLD >= distance) {
        return true;
    }
    return false;
}

