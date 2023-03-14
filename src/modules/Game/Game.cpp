#include "Game.h"

Game::Game() : enemies() {
  player_texture = LoadTexture("assets/character.png");
  game_bg = LoadTexture("assets/background.png");
  enemy_texture = LoadTexture("assets/zombies_v2.png");
  player = Player(SpriteAnimation(player_texture, 12, 8, 8));
  tick = 1;
  killed = 0;
  isOver = false;
  spawnTime = 60;
}

void Game::Restart() {
  tick = 1;
  killed = 0;
  isOver = false;
  spawnTime = 60;
  enemies = std::vector<Enemy>();
  player.reloadPosition();
}

void Game::DrawStats() {
  DrawFPS(10,10);
  
  // enemies count
  std::string ec = std::to_string(enemies.size());
  raylib::DrawText(ec, 300, 10, 16, DARKGREEN);

  // killed enemies count
  std::string kec = std::to_string(killed);
  raylib::DrawText(kec, 400, 10, 16, DARKGREEN);
}

void Game::DrawGameOver() {
  raylib::Text gameover = raylib::Text("GAME OVER", 64); 
  int width = gameover.Measure();
  raylib::DrawText(
    "GAME OVER", 
    GetScreenWidth() / 2 - (width / 2), 
    GetScreenHeight() / 2 - 64, 
    64, RED
  );

  // FINAL SCORE
  raylib::Text final_score_text = raylib::Text("KILLED: " + std::to_string(killed), 32);
  width = final_score_text.Measure();
  raylib::DrawText(
    "KILLED: " + std::to_string(killed), 
    GetScreenWidth() / 2 - (width / 2), 
    GetScreenHeight() / 2, 
    32, WHITE
  );
}

void Game::Draw() {
  if (!isOver) {
    DrawTexture(game_bg, 0,0, WHITE);
    DrawStats();
    player.Draw();
    Enemy::DrawAll(enemies);
    Bullet::DrawAll(player.bullets);
  } else {
    ClearBackground(BLACK);
    DrawGameOver();
  }
}

void Game::Update() {
  if (!isOver) {
    player.Update(killed);
    enemy.spawn(enemy_texture, enemies, &tick, killed, &spawnTime);
    Collider<Player>::Update(player, enemies, &isOver, &killed);
  } else {
    if (IsKeyPressed(KEY_SPACE)) {
      Restart();
    }
  }
}