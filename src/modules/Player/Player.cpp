#include "Player.h"
#include "../Bullet/Bullet.h"
#include <iostream>

Player::Player() {}

Player::Player(SpriteAnimation _sprite) : sprite()
{
  radius = 20;
  pos = {(float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2};
  color = PINK;
  rifleStart = {1, 1};
  rifleEnd = {1, 1};
  speed = 3;
  sprite = _sprite;
  sprite.SetCurrentFrame(4);
  sprite.SetCurrentLine(6);
}

void Player::UpdateAnimation() {
  if (IsKeyDown(KEY_W) && !IsKeyDown(KEY_A) && !IsKeyDown(KEY_D)) {
    sprite.PlayAnimation(5, 7, 0);
  } else if (IsKeyDown(KEY_D) && IsKeyDown(KEY_W)) {
    sprite.PlayAnimation(5, 7, 1);
  } else if (IsKeyDown(KEY_D) && !IsKeyDown(KEY_W) && !IsKeyDown(KEY_S)) {
    sprite.PlayAnimation(5, 7, 2);
  } else if (IsKeyDown(KEY_D) && IsKeyDown(KEY_S)) {
    sprite.PlayAnimation(5, 7, 3);
  } else if (IsKeyDown(KEY_S) && !IsKeyDown(KEY_A) && !IsKeyDown(KEY_D)) {
    sprite.PlayAnimation(5, 7, 4);
  } else if (IsKeyDown(KEY_A) && IsKeyDown(KEY_S)) {
    sprite.PlayAnimation(5, 7, 5);
  } else if (IsKeyDown(KEY_A) && !IsKeyDown(KEY_W) && !IsKeyDown(KEY_S)) {
    sprite.PlayAnimation(5, 7, 6);
  } else if (IsKeyDown(KEY_A) && IsKeyDown(KEY_W)) {
    sprite.PlayAnimation(5, 7, 7);
  } else {
    sprite.PlayAnimation(6, 6, 4);
  }
}

void Player::move() {
  if (IsKeyDown(KEY_A)) {
    if (pos.x - radius > 0) {
      pos.x -= speed;
    }
  }
  if (IsKeyDown(KEY_D)) {
    if (pos.x + radius < GetScreenWidth()) {
      pos.x += speed;
    }
  }
  if (IsKeyDown(KEY_W)) {
    if (pos.y - radius > 0) {
      pos.y -= speed;
    }
  }
  if (IsKeyDown(KEY_S)) {
    if (pos.y + radius < GetScreenHeight()) {
      pos.y += speed;
    }
  }
}

void Player::rifleUpdate() {
  rifleStart = GetMousePosition();
  float dx = rifleStart.x - pos.x;
  float dy = rifleStart.y - pos.y;
  
  float angle = atan2f(dy, dx);
  
  float dxx = radius * cosf(angle);
  float dyy = radius * sinf(angle);

  float dxx2 = (radius + 5) * cosf(angle);
  float dyy2 = (radius + 5) * sinf(angle);

  rifleStart.x = pos.x + dxx;
  rifleStart.y = pos.y + dyy;
  
  rifleEnd.x = pos.x + dxx2;
  rifleEnd.y = pos.y + dyy2;
}

void Player::shoot() {
  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    float vx = (rifleStart.x - pos.x);
    float vy = (rifleStart.y - pos.y);
    bullets.push_back(
      Bullet(pos, (Vector2){vx, vy})
    );
  }
}

void Player::reloadPosition() {
  pos.x = GetScreenWidth() / 2;
  pos.y = GetScreenHeight() / 2;
}

void Player::Update(int killed) {
  move();
  UpdateAnimation();
  rifleUpdate();
  shoot();
  sprite.UpdateFrameRec();
}

void Player::DrawBody() {
  DrawCircle(pos.x, pos.y, radius, color);
}

void Player::DrawGun() {
  DrawLineEx(rifleStart, rifleEnd, 2, BLACK);
}

void Player::Draw() {
  // DrawBody();
  // DrawGun();
  Vector2 spritePos = {pos.x - radius + 4, pos.y - radius};
  sprite.DrawFrame(spritePos);
}