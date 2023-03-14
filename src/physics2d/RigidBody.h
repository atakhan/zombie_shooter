#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "PhysicsMath.h"
#include <raylib-cpp.hpp>

struct Shape;

struct RigidBody {
    Vec2 position;
    Vec2 velocity;
    Vec2 force;
    real orientation;
    real angularVelocity;
    real torque;
    real m;  // Mass
    real invm;  // inverse mass
    real I;  // Inertia
    real invI;  // inverse inertia
    real friction;  // трение
    real restitution;  // отскок
    real linearDamping;  // амортизация гашение
    real angularDamping;
    real gravityScale;
    Color color;

    Shape* shape;

    RigidBody(Shape&, const Vec2&, const real&);
    void Dynamic(const real& Density);  // Density - плотность
    void Static(void);
};

#endif  // RIGIDBODY_H