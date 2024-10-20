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
    WallsMapComponent* wallsMap = terrain->GetComponent<WallsMapComponent>();
    
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
                // is current target reachable?
                if (TargetReachable(
                    target->position_, 
                    zombiePos->position_, 
                    zombieRadius->health_, 
                    terrainComponent, 
                    wallsMap)
                ) {
                    // is current target reached?
                    if (TargetReached(target->position_, zombiePos->position_)) {
                        Vector2 newTarget = RandomTarget(
                            terrainComponent->width_ * terrainComponent->cellWidth_, 
                            terrainComponent->height_ * terrainComponent->cellHeight_
                        );
                        target->position_ = newTarget;
                    }
                // current target not reachable
                } else {
                    // create a new target
                    Vector2 newTarget = RandomTarget(
                        terrainComponent->width_ * terrainComponent->cellWidth_, 
                        terrainComponent->height_ * terrainComponent->cellHeight_
                    );
                    target->position_ = newTarget;
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
    
    if (10.0f >= distance) {
        return true;
    }
    return false;
}

bool ZombieTargetingSystem::TargetReachable(Vector2 targetPos, Vector2 curPos, float zombieRadius, TerrainComponent *terrain, WallsMapComponent *wallsMap) {
    for (size_t y = 0; y < wallsMap->map_.size(); y++) {
        for (size_t x = 0; x < wallsMap->map_[y].size(); x++) {
            if (wallsMap->map_[y][x] == 1) {
                // Check if path from curPos to Target Pos
                // collide with one of ABCD lines
                // 
                //          A------B
                //          |      |
                //          |      |
                //          |      |
                //          C------D
                // 
                //
                Vector2 cornerA = {
                    (float)x * terrain->cellWidth_, 
                    (float)y * terrain->cellHeight_
                };
                Vector2 cornerB = {
                    ((float)x * terrain->cellWidth_) + terrain->cellWidth_, 
                    (float)y * terrain->cellHeight_
                };
                Vector2 cornerC = {
                    (float)x * terrain->cellWidth_, 
                    ((float)y * terrain->cellHeight_) + terrain->cellHeight_
                };
                Vector2 cornerD = {
                    (float)x * terrain->cellWidth_ + terrain->cellWidth_, 
                    (float)y * terrain->cellHeight_ + terrain->cellHeight_
                };

                // Check if target in a wall
                if (CheckCollisionCircleRec(
                    targetPos, 
                    zombieRadius, 
                    (Rectangle){
                        cornerA.x,
                        cornerA.y, 
                        terrain->cellWidth_,
                        terrain->cellHeight_
                    })
                ) {
                    return false;
                }

                Vector2 *collisionPoint = nullptr;
                if (CheckCollisionLines(cornerA, cornerB, curPos, targetPos, collisionPoint)) { return false; }  // Check if path collide with walls AB
                if (CheckCollisionLines(cornerB, cornerD, curPos, targetPos, collisionPoint)) { return false; }  // Check if path collide with walls BD
                if (CheckCollisionLines(cornerC, cornerD, curPos, targetPos, collisionPoint)) { return false; }  // Check if path collide with walls CD
                if (CheckCollisionLines(cornerA, cornerC, curPos, targetPos, collisionPoint)) { return false; }  // Check if path collide with walls AC
            }
        }
    }

    return true;
}

