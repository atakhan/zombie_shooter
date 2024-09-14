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
    player.components.push_back(new Circle(400, 300, 10, raylib::Color(255U, 10U, 10U)));
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
        enemy.components.push_back(new Circle(700, 500, 10, raylib::Color(10U, 255U, 10U)));
        enemy.components.push_back(new Enemy{true});
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
    MovementSystem(entities);
    CollisionSystem(entities);
    LootSystem(entities);
}

void Game::Draw() {
    ClearBackground(RAYWHITE);
    RenderSystem(entities);
}
