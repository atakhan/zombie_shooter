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
        player->AddComponent<CameraComponent>(CameraComponent());
        player->AddComponent<BreathSoundComponent>(BreathSoundComponent(0.0f, 20.0f));
        player->AddComponent<AdrenalinComponent>(AdrenalinComponent(1.0, 3.0f));
        player->AddComponent<CircleColliderComponent>(CircleColliderComponent(health));
        
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
  
    
    // static void CreateHumanWithDefaultComponents(Entity *human) {
    //     human->AddComponent<HumanComponent>(HumanComponent());
    //     human->AddComponent<StaminaComponent>(StaminaComponent(
    //         Config::HUMAN_DEFAULT_STAMINA
    //     ));
    //     human->AddComponent<HealthComponent>(HealthComponent(
    //         Config::HUMAN_DEFAULT_HEALTH
    //     ));
    //     human->AddComponent<PositionComponent>(PositionComponent(
    //         Config::HUMAN_SPAWN_POSITION_X, 
    //         Config::HUMAN_SPAWN_POSITION_Y
    //     ));
    //     human->AddComponent<AttackComponent>(AttackComponent(
    //         Config::HUMAN_DEFAULT_STRENGTH, 
    //         Config::HUMAN_ATTACK_RADIUS
    //     ));
    //     human->AddComponent<SpeedComponent>(SpeedComponent(
    //         Config::HUMAN_DEFAULT_AGILITY
    //     ));
    //     human->AddComponent<SoundComponent>(SoundComponent(
    //         Config::SOUND_MIN_RADIUS, 
    //         Config::SOUND_MIN_RADIUS, 
    //         Config::SOUND_MAX_RADIUS,
    //         true
    //     ));
    //     human->AddComponent<CameraComponent>(CameraComponent());
    //     human->AddComponent<TargetComponent>(TargetComponent(
    //         Config::HUMAN_DEFAULT_TARGET_X, 
    //         Config::HUMAN_DEFAULT_TARGET_Y
    //     ));
    // }

    // static Entity* SpawnHumanInPosWithStatusAndTarget(float posX, float posY, HumanComponent::Status status, float tarX, float tarY) {
    //     Entity *human = new Entity();
    //     CreateHumanWithDefaultComponents(human);
    //     human->ReplaceComponent<HumanComponent>(HumanComponent(status));
    //     human->ReplaceComponent<PositionComponent>(PositionComponent(posX, posY));
    //     human->ReplaceComponent<TargetComponent>(TargetComponent(tarX, tarY));
    //     return human;
    // }
    // static Entity* SpawnHumanInPosWithStatus(float posX, float posY, HumanComponent::Status status) {
    //     Entity *human = new Entity();
    //     CreateHumanWithDefaultComponents(human);
    //     human->ReplaceComponent<HumanComponent>(HumanComponent(status));
    //     human->ReplaceComponent<PositionComponent>(PositionComponent(posX, posY));
    //     return human;
        
    // }
    // static Entity* SpawnHumanInPos(float posX, float posY) {
    //     Entity *human = new Entity();
    //     CreateHumanWithDefaultComponents(human);
    //     human->ReplaceComponent<PositionComponent>(PositionComponent(posX, posY));
    //     return human;

    // }

    // static Entity* SpawnHuman() {
    //     // CREATE HUMAN
    //     Entity *human = new Entity();
    //     CreateHumanWithDefaultComponents(human);
    //     return human;
    // }

    // static Entity* SpawnLoot() {
    //     // CREATE LOOT
    //     Entity *loot = new Entity();
    //     loot->AddComponent<LootComponent>(LootComponent(
    //         Config::DEFAULT_LOOT_AMOUNT
    //     ));
    //     loot->AddComponent<PositionComponent>(PositionComponent(
    //         Config::DEFAULT_LOOT_SPAWN_POSITION_X, 
    //         Config::DEFAULT_LOOT_SPAWN_POSITION_Y
    //     ));
    //     return loot;
    // }

};

#endif // SRC_UTILS_SCENE_TOOLS_H