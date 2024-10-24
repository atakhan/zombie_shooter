#ifndef SRC_UTILS_SCENE_TOOLS_H
#define SRC_UTILS_SCENE_TOOLS_H

#include <string>
#include "../Config.h"
#include "../core/Bootstrap.h"
#include "../components/Bootstrap.h"
#include "../systems/Bootstrap.h"

class SceneTools {  
  public:
    // CREATE GAME
    static Entity* CreateScene(const std::string& gameTitle, const std::string& sceneTitle) {
        Entity *sceneEntity = new Entity();
        sceneEntity->AddComponent<GameTitleComponent>(GameTitleComponent(gameTitle));
        sceneEntity->AddComponent<SceneComponent>(SceneComponent(sceneTitle));
        
        return sceneEntity;
    }

    // CREATE PLAYER
    static Entity* CreatePlayer(
        Vector2 pos, 
        float health, 
        float strength, 
        float agility, 
        float attackRadius, 
        float soundRadius
    ) {
        Entity *player = new Entity();
        player->AddComponent<PlayerComponent>(PlayerComponent());
        player->AddComponent<PositionComponent>(PositionComponent(pos));
        player->AddComponent<HealthComponent>(HealthComponent(health));
        player->AddComponent<AttackComponent>(AttackComponent(strength, attackRadius));
        player->AddComponent<SpeedComponent>(SpeedComponent(agility));
        player->AddComponent<SoundComponent>(SoundComponent(soundRadius));
        CameraComponent camera = CameraComponent();
        player->AddComponent<CameraComponent>(camera);
        player->AddComponent<BreathSoundComponent>(BreathSoundComponent(0.5f, 55.0f));
        player->AddComponent<AdrenalinComponent>(AdrenalinComponent(1.0f, 5.0f, 0.005f));
        player->AddComponent<CircleColliderComponent>(CircleColliderComponent(health));

        Rectangle leftFoot = {0.0f, 0.0f, 0.0f, 0.0f};
        Rectangle rightFoot = {0.0f, 0.0f, 0.0f, 0.0f};
        Vector2 leftOrigin = { 0.0f, 0.0f };
        Vector2 rightOrigin = { 0.0f, 0.0f };
        player->AddComponent<FeetComponent>(FeetComponent(leftFoot, rightFoot, leftOrigin, rightOrigin));
        
        Vector2 worldPos = GetScreenToWorld2D(GetMousePosition(), camera.camera_);
        player->AddComponent<DirectionComponent>(DirectionComponent(0.0f, worldPos)); // degrees
        
        return player;
    }


    // CREATE ZOMBIES
    static Entity* CreateZombie(
        PositionComponent pos,
        TargetComponent targetPos,
        HealthComponent health, 
        AttackComponent attack,
        SpeedComponent speed,
        SoundComponent sound
    ) {
        Entity *zombie = new Entity();
        zombie->AddComponent<ZombieComponent>(ZombieComponent());
        zombie->AddComponent<PositionComponent>(pos);
        zombie->AddComponent<TargetComponent>(targetPos);
        zombie->AddComponent<HealthComponent>(health);
        zombie->AddComponent<AttackComponent>(attack);
        zombie->AddComponent<SpeedComponent>(speed);
        zombie->AddComponent<SoundComponent>(sound);
        zombie->AddComponent<CircleColliderComponent>(CircleColliderComponent(health.health_));

        return zombie;
    }
};

#endif // SRC_UTILS_SCENE_TOOLS_H