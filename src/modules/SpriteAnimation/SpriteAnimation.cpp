#include "SpriteAnimation.h"

SpriteAnimation::SpriteAnimation() {}

SpriteAnimation::SpriteAnimation(Texture2D _texture, int rows, int cols, int _speed) {
  texture = _texture;
  frameWidth = (float)(texture.width/cols);
  frameHeight = (float)(texture.height/rows);
  frameRec = { 0, 0, frameWidth, frameHeight };
  framesSpeed = _speed;
  framesCounter = 0;
  currentFrame = 0;
  currentLine = 0;
}

void SpriteAnimation::SetCurrentFrame(int frame) {
  currentFrame = frame;
}

void SpriteAnimation::SetCurrentLine(int line) {
  currentLine = line;
}

void SpriteAnimation::DrawFrame(Vector2 pos) {
  DrawTextureRec(texture, frameRec, pos, WHITE);
}

void SpriteAnimation::DrawFramePro(Vector2 pos, float rotation) {
  DrawTexturePro(
    texture, 
    (Rectangle){frameRec.x, frameRec.y, 72, 72}, 
    (Rectangle){pos.x, pos.y, 72, 72},
    (Vector2){36, 36}, 
    rotation * 180 / PI, 
    WHITE
  );
}

void SpriteAnimation::PlayAnimation(int from, int to, int currentFrame) {
  SetCurrentFrame(currentFrame);
  framesCounter++;
  if (framesCounter >= 60/framesSpeed){
    framesCounter = 0;
    currentLine++;
    if (currentLine > to) {
      currentLine = from;
    }
  }
}

void SpriteAnimation::UpdateFrameRec() {
  frameRec.x = frameWidth * currentFrame;
  frameRec.y = frameHeight * currentLine;
}