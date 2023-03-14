#include "Ball.hpp"
#include <raylib-cpp.hpp>

Ball::Ball() {
    Init();
}

Ball::Ball(Vector2 pos) {
    Init(pos);
}

Ball::Ball(Vector2D pos, Vector2D vel, Vector2D acc, float radius, Color color) {
    this->pos.x = pos.x;
    this->pos.y = pos.y;
    this->vel.x = vel.x;
    this->vel.y = vel.y;
    this->acc.x = acc.x;
    this->acc.y = acc.y;
    this->radius = radius;
    this->mass = radius * 10.0f;
    this->color = color;
}

Ball::~Ball() {}

void Ball::Init() {
    this->pos.x = GetScreenWidth()/2;
    this->pos.y = GetScreenHeight()/2;
    this->vel.x = 0.0f;
    this->vel.y = 0.0f;
    this->acc.x = 0.0f;
    this->acc.y = 0.0f;
    int randomRadius = MIN_RADIUS + (std::rand() % MAX_RADIUS);
    // int randomMass = MIN_MASS + (std::rand() % MAX_MASS);
    // if (randomMass == 0) randomMass = 1;
    this->radius = randomRadius;
    this->mass = randomRadius * 2;
    // this->mass = randomMass;
    this->color = raylib::Color(GetRandomValue(0, 240), GetRandomValue(0, 240), GetRandomValue(0, 250), 255);
}

void Ball::Init(Vector2 pos) {
    this->Init();
    this->pos.x = pos.x;
    this->pos.y = pos.y;
}

void Ball::Draw() {
    DrawCircle(pos.x, pos.y, radius, color);
    // std::string text = std::to_string(mass);
    // raylib::DrawText(text, pos.x - 10, pos.y, 12, BLACK);
}

void Ball::Update() {
    this->Move();
    this->WallCollider();
}

void Ball::Move() {
    // acc.x = -vel.x * 0.005f;
    // acc.y = -vel.y * 0.005f;

    vel.x += acc.x;
    vel.y += acc.y;

    vel.y = vel.y + newton_G;
    pos.x += vel.x;
    pos.y += vel.y;

    // Clamp velocity near zero
    if (fabs(vel.x * vel.x + vel.y * vel.y) < 0.01f)
    {
        vel.x = 0;
        vel.y = 0;
    }
}

void Ball::WallCollider() {
    if ((pos.x + radius >= GetScreenWidth())) {
        vel.x *= -0.85f;
        pos.x = GetScreenWidth() - radius;
    } else if (pos.x - radius < 0) {
        vel.x *= -0.85f;
        pos.x = radius;
    }
    if (pos.y + radius >= GetScreenHeight()) {
        vel.y *= -0.85f;
        pos.y = GetScreenHeight() - radius;
    } else if (pos.y - radius < 0) {
        vel.y *= -0.85f;
        pos.y = radius;
    }
}

bool Ball::DoBallsOverlap(Ball ball) {
    return fabs(
        (pos.x - ball.pos.x) * (pos.x - ball.pos.x) + 
        (pos.y - ball.pos.y) * (pos.y - ball.pos.y) 
    ) <= (
        (radius + ball.radius) * (radius + ball.radius)
    );
}

bool Ball::IsPointInBall(Vector2 mousePos) {
    return fabs(
        (pos.x - mousePos.x) * (pos.x - mousePos.x) + 
        (pos.y - mousePos.y) * (pos.y - mousePos.y) 
    ) < (
        (radius * radius)
    );
}


// solution from
// https://stackoverflow.com/questions/345838/ball-to-ball-collision-detection-and-handling?rq=1
void Ball::ResolveCollision(Ball ball2) {
    // get the mtd
    Vector2D delta = (pos.subtract(ball2.pos));
    float d = delta.getLength();
    // minimum translation distance to push balls apart after intersecting
    Vector2D mtd = delta.multiply(((radius + ball2.radius) - d) / d); 

    // resolve intersection --
    // inverse mass quantities
    float im1 = 1 / mass; 
    float im2 = 1 / ball2.mass;

    // push-pull them apart based off their mass
    pos = pos.add(mtd.multiply(im1 / (im1 + im2)));
    ball2.pos = ball2.pos.subtract(mtd.multiply(im2 / (im1 + im2)));

    // impact speed
    Vector2D v = (vel.subtract(ball2.vel));
    float vn = v.dot(mtd.normalize());

    // sphere intersecting but moving away from each other already
    if (vn > 0.0f) return;

    // collision impulse
    float i = (-(1.0f + RESTITUTION) * vn) / (im1 + im2);
    Vector2D impulse = mtd.normalize().multiply(i);

    // change in momentum
    vel = vel.add(impulse.multiply(im1));
    ball2.vel = ball2.vel.subtract(impulse.multiply(im2));
}
