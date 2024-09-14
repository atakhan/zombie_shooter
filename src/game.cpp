#include "game.h"

void Game::Init() {
    LoadResources();
    CreatePlayer();
    CreateEnemies();
    CreateLoot();
}

void Game::LoadResources() {
    // Загрузка текстур
    // Пример: playerSprite.texture = LoadTexture("player.png");
}

void Game::CreatePlayer() {
    Entity player;
    player.id = 1;
    player.components.push_back(new Position{400, 300});
    player.components.push_back(new Velocity{0, 0});
    player.components.push_back(new Health{100, 100});
    // player.components.push_back(new Sprite{LoadTexture("player.png")});
    player.components.push_back(new Circle(400, 300, 10, raylib::Color(30U, 30U, 225U)));
    player.components.push_back(new Power{1});
    entities.push_back(player);
}

void Game::CreateEnemies() {
    for (int i = 0; i < 5; i++) {
        Entity enemy;
        enemy.id = 2 + i;
        enemy.components.push_back(new Position{700, 500});
        enemy.components.push_back(new Velocity{0, 0});
        enemy.components.push_back(new Health{50, 50});
        // enemy.components.push_back(new Sprite{LoadTexture("enemy.png")});
        enemy.components.push_back(new Circle(700, 500, 10, raylib::Color(220U, 25U, 40U)));
        enemy.components.push_back(new Enemy{true});
        enemy.components.push_back(new Power{0.5});
        enemy.components.push_back(new MovementAI{true, 1});
        entities.push_back(enemy);
    }
}

void Game::CreateLoot() {
    Entity loot;
    loot.id = 100;
    loot.components.push_back(new Position{550, 340});
    loot.components.push_back(new Loot{10});
    entities.push_back(loot);
}

void Game::Update() {
    InputSystem(entities);
    MovementSystem(entities);
    CollisionSystem(entities);
    LootSystem(entities);
    AIMovementSystem(entities);
}

void Game::Draw() {
    ClearBackground(RAYWHITE);
    RenderSystem(entities);
    HealthUISystem(entities);
}
