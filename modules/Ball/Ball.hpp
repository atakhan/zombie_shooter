#ifndef BALL_H_
#define BALL_H_

#include "../Vector2D/Vector2D.hpp"

#include <raylib-cpp.hpp>
#include <float.h>
#include <list>
#include <iostream>
#include <string>

#define BALLS_COUNT 1000
#define MIN_RADIUS 6
#define MAX_RADIUS 12

#define MIN_MASS 1
#define MAX_MASS 5000

#define RESTITUTION 0.9f
#define EPSILON 0.000009f


class Ball {
public:
    Vector2D pos;
    Vector2D vel;
    Vector2D acc;
    float radius;
    float mass;
    Color color;
    const double newton_G = 0.1;

    Ball();
    Ball(Vector2);
    Ball(Vector2D, Vector2D, Vector2D, float, Color);
    ~Ball();

    void Init();
    void Init(Vector2);

    void Draw();
    void Update();
    void Move();
    void WallCollider();
    bool DoBallsOverlap(Ball);
    bool IsPointInBall(Vector2);
    void ResolveCollision(Ball);
};

#endif  // BALL_H_