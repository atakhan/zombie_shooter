#ifndef SPRITE_ANIMATION_H
#define SPRITE_ANIMATION_H

#include <iostream>
#include <raylib-cpp.hpp>

class SpriteAnimation
{
public:
  Texture2D texture;
  float frameWidth;
  float frameHeight;
  Rectangle frameRec;
  int framesSpeed;
  int framesCounter;
  int currentFrame;
  int currentLine;
  
  
  SpriteAnimation();
  SpriteAnimation(Texture2D _texture, int rows, int cols, int speed);

  void PlayAnimation(int, int, int);
  void DrawFrame(Vector2);
  void DrawFramePro(Vector2, float rotation);
  void SetCurrentFrame(int);
  void SetCurrentLine(int);
  void UpdateFrameRec();

};

#endif  // SPRITE_ANIMATION_H