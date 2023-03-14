#ifndef SHAPE_H
#define SHAPE_H

#include <stdio.h>
#include "RigidBody.h"

enum typeShape {
    circle, 
    obb
};

struct Shape {
    real radius; 
    Vec2 width;
    typeShape type;
    RigidBody* body;

    virtual Shape* newShape(void) = 0;
    virtual void CalculateMassInertia(const real&) = 0;
};

struct Circle : virtual public Shape {	
    Circle(const real& _radius);
    ~Circle(void) {;}

    Shape* newShape(void) override;
    void CalculateMassInertia(const real&) override;
};

struct OBB : virtual public Shape
{
    OBB(const Vec2& _width);
    OBB(const real& x, const real& y);
    ~OBB(void) {;}
  
    Shape* newShape(void) override;
    void CalculateMassInertia(const real&) override;
};

#endif