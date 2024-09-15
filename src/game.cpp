#include "game.h"

// Диапазон идентификаторов
// 0-99         - UI entities
// 100-999      - Agent entities
// 1000-9999    - Other entities

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

void Game::CreateEntity(int id, std::vector<Component*> components) {
    entities.push_back((Entity) { id, components });
}

void Game::CreatePlayer() {
    CreateEntity(1, {
        new Position{400, 500},
        new Velocity{0, 0},
        new Health{100, 100},
        new Power{1},
    });
}

void Game::CreateEnemies() {
    const int AGENTS_COUNT = 30;
    for (int i = 0; i < AGENTS_COUNT; i++) {
        CreateEntity(2 + i, {
            new Position{400, 300},
            new Velocity{0, 0},
            new Health{35, 40},
            new Power{0.5},
            new MovementAI{true, 1},
            new Enemy{true}
        });
    }
}

void Game::CreateTerrain() {
    CreateEntity(100, {
        new Position{550, 340},
        new Loot{10}
    });
}

void Game::CreateLoot() {
    CreateEntity(100, {
        new Position{550, 340},
        new Loot{10}
    });
}

void Game::Update() {
    PlayerControl::handleKeyboardInputs(entities);
    AI::NPCRandomMove(entities);
    Movement::Update(entities);
    Collision::Update(entities);
    LootSystem(entities);
}

void Game::Draw() {
    ClearBackground(RAYWHITE);
    RenderPrototypeSystem(entities);
    HealthUISystem(entities);
}
