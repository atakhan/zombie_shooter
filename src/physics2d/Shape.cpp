#include "Shape.h"					

Circle::Circle(const real& _radius) {
  type = circle; 
  radius = _radius;
}

Shape* Circle::newShape(void) {
  return new Circle(this->radius);
}

void Circle::CalculateMassInertia(const real& density) {
  body->m = PI * radius * radius * density;
  body->invm = body->m ? 1.0f / body->m : 0.0f;
  body->I = body->m * radius * radius * 0.5f;
  body->invI = body->I ? 1.0f / body->I : 0.0f;
}

OBB::OBB(const Vec2& _width) {
  type = obb; width = _width;
}

OBB::OBB(const real& x, const real& y) {
  type = obb; width.Set(x, y);
}

Shape* OBB::newShape(void) {
  return new OBB(this->width);
}

void OBB::CalculateMassInertia(const real& density) {
  body->m = width.x * width.y * density;
  body->invm = body->m ? 1.0f / body->m : 0.0f;
  body->I = body->m * width.SquareMagnitude() / 12.0f; 
  body->invI = body->I ? 1.0f / body->I : 0.0f;
}