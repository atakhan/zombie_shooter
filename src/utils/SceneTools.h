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
    static void CreateScene(const std::string& gameTitle, const std::string& sceneTitle, Scene *scene) {
        // logic entities
        Entity *game = new Entity();
        game->AddComponent<GameTitleComponent>(GameTitleComponent(gameTitle));
        game->AddComponent<SceneComponent>(SceneComponent(sceneTitle));
        scene->AddEntity(game);
        
        // ui entities
        scene->AddEntity(UiTools::CreateUIEntity(
            (Vector2){10.0f, 10.0f},
            gameTitle,
            16.0f, 1, 1, 3.0f, RED
        ));
        scene->AddEntity(UiTools::CreateUIEntity(
            (Vector2){10.0f, 10.0f},
            sceneTitle,
            16.0f, 1, 2, 3.0f, RED
        ));
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
        
        return player;
    }


    // CREATE ZOMBIES
    static Entity* CreateZombie(
        Vector2 pos,
        Vector2 targetPos,
        float health, 
        float strength, 
        float agility,
        float attackRadius, 
        float soundRadius
    ) {
        Entity *zombie = new Entity();
        zombie->AddComponent<ZombieComponent>(ZombieComponent());
        zombie->AddComponent<PositionComponent>(PositionComponent(pos));
        zombie->AddComponent<HealthComponent>(HealthComponent(health));
        zombie->AddComponent<AttackComponent>(AttackComponent(strength, attackRadius));
        zombie->AddComponent<SpeedComponent>(SpeedComponent(agility));
        zombie->AddComponent<TargetComponent>(TargetComponent(targetPos));
        zombie->AddComponent<SoundComponent>(SoundComponent(soundRadius));

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