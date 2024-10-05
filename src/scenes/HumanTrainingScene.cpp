#include "HumanTrainingScene.h"

void HumanTrainingScene::Init() {
    SpawnPlayer();
    SpawnZombie();
    // SpawnHumanInPosWithStatus(50.0f, 100.0f, HumanComponent::Status::ATTACK);
    // SpawnHumanInPosWithStatus(150.0f, 100.0f, HumanComponent::Status::IDLE);
    // SpawnHumanInPosWithStatusAndTarget(250.0f, 100.0f, HumanComponent::Status::RUN, 250.0f, 400.0f);
    // SpawnHumanInPosWithStatusAndTarget(150.0f, 100.0f, HumanComponent::Status::RUN, 150.0f, 400.0f);
    // SpawnHumanInPosWithStatusAndTarget(350.0f, 100.0f, HumanComponent::Status::RUN, 350.0f, 400.0f);
    // SpawnHumanInPosWithStatus(450.0f, 100.0f, HumanComponent::Status::SLEEP);
    // SpawnLoot();

    // Systems
    Scene::AddSystem(new PlayerDrawSystem);
    Scene::AddSystem(new PlayerControlSystem);
    Scene::AddSystem(new ZombieDrawSystem);
    Scene::AddSystem(new ZombieMoveSystem);
    Scene::AddSystem(new ZombieTargetingSystem);

    // Scene::AddSystem(new HumanStaminaSystem());
    // Scene::AddSystem(new HumanMoveSystem());
    // Scene::AddSystem(new HumanTargetingSystem());
    // Scene::AddSystem(new HumanDrawSystem());

    // Scene::AddSystem(new LootRandomSeedSystem());
    // Scene::AddSystem(new HumanBreathSystem());
    // Scene::AddSystem(new HumanPhysiologicalSystem());

    // Scene::AddSystem(new LootDrawSystem());


    for (auto& system : systems_) {
        if (system == nullptr) {
            std::cerr << "System pointer is null!" << std::endl;
            continue;
        }
        system->Init(&entities_);
    }
}

void HumanTrainingScene::Update() {
    for (auto& system : systems_) {
        if (system == nullptr) {
            std::cerr << "System pointer is null!" << std::endl;
            continue;
        }
        system->Update(&entities_);
    }
}

void HumanTrainingScene::Draw() {
    for (auto& system : systems_) {
        if (system == nullptr) {
            std::cerr << "System pointer is null!" << std::endl;
            continue;
        }
        system->Draw(&entities_);
    }
}

void HumanTrainingScene::CreateHumanWithDefaultComponents(Entity *human) {
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

void HumanTrainingScene::SpawnHumanInPosWithStatusAndTarget(float posX, float posY, HumanComponent::Status status, float tarX, float tarY) {
    Entity *human = new Entity();
    CreateHumanWithDefaultComponents(human);
    human->ReplaceComponent<HumanComponent>(HumanComponent(status));
    human->ReplaceComponent<PositionComponent>(PositionComponent(posX, posY));
    human->ReplaceComponent<TargetComponent>(TargetComponent(tarX, tarY));
    Scene::AddEntity(human);
}
void HumanTrainingScene::SpawnHumanInPosWithStatus(float posX, float posY, HumanComponent::Status status) {
    Entity *human = new Entity();
    CreateHumanWithDefaultComponents(human);
    human->ReplaceComponent<HumanComponent>(HumanComponent(status));
    human->ReplaceComponent<PositionComponent>(PositionComponent(posX, posY));
    Scene::AddEntity(human);
    
}
void HumanTrainingScene::SpawnHumanInPos(float posX, float posY) {
    Entity *human = new Entity();
    CreateHumanWithDefaultComponents(human);
    human->ReplaceComponent<PositionComponent>(PositionComponent(posX, posY));
    Scene::AddEntity(human);

}

void HumanTrainingScene::SpawnHuman() {
    // CREATE HUMAN
    Entity *human = new Entity();
    CreateHumanWithDefaultComponents(human);
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