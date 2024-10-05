#ifndef SCENE_TOOLS_H
#define SCENE_TOOLS_H

#include <string>
#include "../core/Bootstrap.h"
#include "../components/Bootstrap.h"
#include "../systems/Bootstrap.h"

class SceneTools {  
  public:
    // CREATE GAME
    static Entity* InitGameComponent(const std::string& sceneTitle) {
        Entity *game = new Entity();
        game->AddComponent<GameComponent>(GameComponent(Config::GAME_TITLE, sceneTitle));
        return game;
    }

    // CREATE PLAYER
    static Entity* SpawnPlayer() {
        Entity *player = new Entity();
        player->AddComponent<PlayerComponent>(PlayerComponent());
        player->AddComponent<HealthComponent>(HealthComponent(
            Config::PLAYER_HEALTH
        ));
        player->AddComponent<AttackComponent>(AttackComponent(
            Config::PLAYER_STRENGTH, 
            Config::PLAYER_ATTACK_RADIUS
        ));
        player->AddComponent<PositionComponent>(PositionComponent(
            Config::PLAYER_SPAWN_POSITION_X, 
            Config::PLAYER_SPAWN_POSITION_Y
        ));
        player->AddComponent<SpeedComponent>(SpeedComponent(
            Config::PLAYER_AGILITY
        ));
        player->AddComponent<SoundComponent>(SoundComponent(
            Config::SOUND_MIN_RADIUS, 
            Config::SOUND_MIN_RADIUS, 
            Config::SOUND_MAX_RADIUS,
            true
        ));
        player->AddComponent<CameraComponent>(CameraComponent());
        
        return player;
    }


    static Entity* SpawnZombie() {
        // CREATE ZOMBIES
        Entity *zombie = new Entity();
        zombie->AddComponent<PositionComponent>(PositionComponent(
            Config::ZOMBIE_SPAWN_POSITION_X,
            Config::ZOMBIE_SPAWN_POSITION_Y
        ));
        zombie->AddComponent<HealthComponent>(HealthComponent(
            Config::ZOMBIE_HEALTH
        ));
        zombie->AddComponent<AttackComponent>(AttackComponent(
            Config::ZOMBIE_STRENGTH, 
            Config::ZOMBIE_ATTACK_RADIUS
        ));
        zombie->AddComponent<SpeedComponent>(SpeedComponent(
            Config::ZOMBIE_AGILITY
        ));
        zombie->AddComponent<TargetComponent>(TargetComponent(
            Config::ZOMBIE_DEFAULT_TARGET_POSITION_X,
            Config::ZOMBIE_DEFAULT_TARGET_POSITION_X
        ));
        zombie->AddComponent<SoundComponent>(SoundComponent(
            Config::SOUND_MIN_RADIUS, 
            Config::SOUND_MIN_RADIUS, 
            Config::SOUND_MAX_RADIUS,
            true
        ));
        zombie->AddComponent<ZombieComponent>(ZombieComponent());

        return zombie;
    }
    
    
    static void CreateHumanWithDefaultComponents(Entity *human) {
        human->AddComponent<HumanComponent>(HumanComponent());
        human->AddComponent<StaminaComponent>(StaminaComponent(
            Config::HUMAN_DEFAULT_STAMINA
        ));
        human->AddComponent<HealthComponent>(HealthComponent(
            Config::HUMAN_DEFAULT_HEALTH
        ));
        human->AddComponent<PositionComponent>(PositionComponent(
            Config::HUMAN_SPAWN_POSITION_X, 
            Config::HUMAN_SPAWN_POSITION_Y
        ));
        human->AddComponent<AttackComponent>(AttackComponent(
            Config::HUMAN_DEFAULT_STRENGTH, 
            Config::HUMAN_ATTACK_RADIUS
        ));
        human->AddComponent<SpeedComponent>(SpeedComponent(
            Config::HUMAN_DEFAULT_AGILITY
        ));
        human->AddComponent<SoundComponent>(SoundComponent(
            Config::SOUND_MIN_RADIUS, 
            Config::SOUND_MIN_RADIUS, 
            Config::SOUND_MAX_RADIUS,
            true
        ));
        human->AddComponent<CameraComponent>(CameraComponent());
        human->AddComponent<TargetComponent>(TargetComponent(
            Config::HUMAN_DEFAULT_TARGET_X, 
            Config::HUMAN_DEFAULT_TARGET_Y
        ));
    }

    static Entity* SpawnHumanInPosWithStatusAndTarget(float posX, float posY, HumanComponent::Status status, float tarX, float tarY) {
        Entity *human = new Entity();
        CreateHumanWithDefaultComponents(human);
        human->ReplaceComponent<HumanComponent>(HumanComponent(status));
        human->ReplaceComponent<PositionComponent>(PositionComponent(posX, posY));
        human->ReplaceComponent<TargetComponent>(TargetComponent(tarX, tarY));
        return human;
    }
    static Entity* SpawnHumanInPosWithStatus(float posX, float posY, HumanComponent::Status status) {
        Entity *human = new Entity();
        CreateHumanWithDefaultComponents(human);
        human->ReplaceComponent<HumanComponent>(HumanComponent(status));
        human->ReplaceComponent<PositionComponent>(PositionComponent(posX, posY));
        return human;
        
    }
    static Entity* SpawnHumanInPos(float posX, float posY) {
        Entity *human = new Entity();
        CreateHumanWithDefaultComponents(human);
        human->ReplaceComponent<PositionComponent>(PositionComponent(posX, posY));
        return human;

    }

    static Entity* SpawnHuman() {
        // CREATE HUMAN
        Entity *human = new Entity();
        CreateHumanWithDefaultComponents(human);
        return human;
    }

    static Entity* SpawnLoot() {
        // CREATE LOOT
        Entity *loot = new Entity();
        loot->AddComponent<LootComponent>(LootComponent(
            Config::DEFAULT_LOOT_AMOUNT
        ));
        loot->AddComponent<PositionComponent>(PositionComponent(
            Config::DEFAULT_LOOT_SPAWN_POSITION_X, 
            Config::DEFAULT_LOOT_SPAWN_POSITION_Y
        ));
        return loot;
    }

};

#endif // SCENE_TOOLS_H