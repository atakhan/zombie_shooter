#include <raylib-cpp.hpp>

#include "Config.h"
#include "core/Bootstrap.h"
#include "components/Bootstrap.h"
#include "systems/Bootstrap.h"

int main() {
    Game game;
    Scene scene = Scene();

    // CREATE PLAYER
    Entity player;
    player.AddComponent<HealthComponent>(HealthComponent(
        Config::PLAYER_HEALTH
    ));
    player.AddComponent<AttackComponent>(AttackComponent(
        Config::PLAYER_STRENGTH, 
        Config::PLAYER_ATTACK_RADIUS
    ));
    player.AddComponent<PositionComponent>(PositionComponent(
        Config::PLAYER_SPAWN_POSITION_X, 
        Config::PLAYER_SPAWN_POSITION_Y
    ));
    player.AddComponent<SpeedComponent>(SpeedComponent(
        Config::PLAYER_AGILITY
    ));
    player.AddComponent<SoundComponent>(SoundComponent(
        Config::SOUND_MIN_RADIUS, 
        Config::SOUND_MIN_RADIUS, 
        Config::SOUND_MAX_RADIUS,
        true
    ));
    player.AddComponent<PlayerComponent>(PlayerComponent());
    player.AddComponent<CameraComponent>(CameraComponent());
    scene.AddEntity(&player);

    // CREATE ZOMBIES
    for (size_t i = 0; i < Config::ZOMBIES_COUNT; i++) {
        Entity *zombie = new Entity();
        zombie->AddComponent<PositionComponent>(PositionComponent(
            Config::ZOMBIE_SPAWN_POSITION_X + i,
            Config::ZOMBIE_SPAWN_POSITION_Y + i
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
        zombie->AddComponent<SoundComponent>(SoundComponent(
            Config::SOUND_MIN_RADIUS, 
            Config::SOUND_MIN_RADIUS, 
            Config::SOUND_MAX_RADIUS,
            true
        ));
        zombie->AddComponent<ZombieComponent>(ZombieComponent());
        scene.AddEntity(zombie);
    }

    // Systems
    PlayerDrawSystem playerDrawSystem;
    PlayerControlSystem playerControlSystem;
    ZombieDrawSystem zombieDrawSystem;

    scene.AddSystem(&playerDrawSystem);
    scene.AddSystem(&playerControlSystem);
    scene.AddSystem(&zombieDrawSystem);

    game.AddScene(&scene);
    game.Init();

    InitWindow(
        Config::WINDOW_WIDTH,
        Config::WINDOW_HEIGHT,
        Config::WINDOW_TITLE
    );

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        game.Update();

        BeginDrawing();
            ClearBackground(RAYWHITE);
            game.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
