#include "HumanTrainingScene.h"

void HumanTrainingScene::Init() {
    // SpawnPlayer();
    SpawnHuman();
    // SpawnLoot();
    
    // Systems
    // Scene::AddSystem(new PlayerDrawSystem);
    // Scene::AddSystem(new PlayerControlSystem);
    
    Scene::AddSystem(new HumanDrawSystem());
    Scene::AddSystem(new HumanMoveSystem());
    Scene::AddSystem(new HumanBreathSystem());
    Scene::AddSystem(new HumanPhysiologicalSystem());
    
    // Scene::AddSystem(new LootDrawSystem());
    
    // Scene::AddSystem(new ZombieDrawSystem);
    // Scene::AddSystem(new ZombieMoveSystem);

    for (auto& system : systems_) {
        if (system == nullptr) {
            std::cerr << "System pointer is null!" << std::endl;
            continue; // Skip this iteration
        }
        system->Init(&entities_);
    }
}

void HumanTrainingScene::Update() {
    for (auto& system : systems_) {
        if (system == nullptr) {
            std::cerr << "System pointer is null!" << std::endl;
            continue; // Skip this iteration
        }
        system->Update(&entities_);
    }
}

void HumanTrainingScene::Draw() {
    for (auto& system : systems_) {
        if (system == nullptr) {
            std::cerr << "System pointer is null!" << std::endl;
            continue; // Skip this iteration
        }
        system->Draw(&entities_);
    }
}

void HumanTrainingScene::SpawnPlayer() {
    // CREATE PLAYER
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
    Scene::AddEntity(player);
}

void HumanTrainingScene::SpawnHuman() {
    // CREATE HUMAN
    Entity *human = new Entity();
    human->AddComponent<HumanComponent>(HumanComponent());
    human->AddComponent<HealthComponent>(HealthComponent(
        Config::HUMAN_HEALTH
    ));
    human->AddComponent<HumanBreathComponent>(HumanBreathComponent(
        true,
        Config::HUMAN_LUNGS_DEFAULT_CAPACITY,
        Config::HUMAN_LUNGS_DEFAULT_CAPACITY
    ));

    human->AddComponent<HumanPhysiologicalComponent>(HumanPhysiologicalComponent(
        Config::HUMAN_AIR_DEFAULT_NEED_VALUE,
        Config::HUMAN_WATER_DEFAULT_NEED_VALUE,
        Config::HUMAN_FOOD_DEFAULT_NEED_VALUE,
        Config::HUMAN_HEAT_DEFAULT_NEED_VALUE,
        Config::HUMAN_CLOTHES_DEFAULT_NEED_VALUE,
        Config::HUMAN_SLEEP_DEFAULT_NEED_VALUE,
        Config::HUMAN_SHELTER_DEFAULT_NEED_VALUE,
        Config::HUMAN_REPRODUCTION_DEFAULT_NEED_VALUE
    ));
    human->AddComponent<AttackComponent>(AttackComponent(
        Config::HUMAN_STRENGTH, 
        Config::HUMAN_ATTACK_RADIUS
    ));
    human->AddComponent<PositionComponent>(PositionComponent(
        Config::HUMAN_SPAWN_POSITION_X, 
        Config::HUMAN_SPAWN_POSITION_Y
    ));
    human->AddComponent<SpeedComponent>(SpeedComponent(
        Config::HUMAN_AGILITY
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
    Scene::AddEntity(human);
}

void HumanTrainingScene::SpawnLoot() {
    // CREATE LOOT
    Entity *loot = new Entity();
    loot->AddComponent<LootComponent>(LootComponent(
        Config::DEFAULT_LOOT_AMOUNT
    ));
    loot->AddComponent<PositionComponent>(PositionComponent(
        Config::DEFAULT_LOOT_SPAWN_POSITION_X, 
        Config::DEFAULT_LOOT_SPAWN_POSITION_Y
    ));
    Scene::AddEntity(loot);
}

void HumanTrainingScene::SpawnZombie() {
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
    Scene::AddEntity(zombie);
}