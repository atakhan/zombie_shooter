// #ifndef VECTOR2D_H_
// #define VECTOR2D_H_

// #include <raylib-cpp.hpp>

// class Vector2D {
// public:
//     float x;
//     float y;

//     Vector2D() {
//         x = 0.0f;
//         y = 0.0f;
//     }

//     Vector2D(float x, float y) {
//         this->x = x;
//         this->y = y;
//     }

//     ~Vector2D() {}

//     float dot(Vector2D v2) {
// 		float result = 0.0f;
// 		result = this->x * v2.x + this->y * v2.y;
// 		return result;
// 	}

// 	float getLength() {
// 		return (float) sqrtf(this->x * this->x + this->y * this->y);
// 	}

// 	float getDistance(Vector2D v2)
// 	{
// 		return (float) sqrtf(
//             (v2.x - x) * 
//             (v2.x - x) + 
//             (v2.y - y) * 
//             (v2.y - y)
//         );
// 	}

// 	Vector2D add(Vector2D v2)
// 	{
// 		Vector2D result = Vector2D();
// 		result.x = (x + v2.x);
// 		result.y = (y + v2.y);
// 		return result;
// 	}

// 	Vector2D subtract(Vector2D v2)
// 	{
// 		Vector2D result = Vector2D();
// 		result.x = (x - v2.x);
// 		result.y = (y - v2.y);
// 		return result;
// 	}

// 	Vector2D multiply(float scaleFactor)
// 	{
// 		Vector2D result = Vector2D();
// 		result.x = (x * scaleFactor);
// 		result.y = (y * scaleFactor);
// 		return result;
// 	}

// 	Vector2D normalize()
// 	{
// 		float len = getLength();
// 		if (len != 0.0f) {
// 			x = (x / len);
// 			y = (y / len);
// 		} else {
// 			x = 0.0f;
// 			y = 0.0f;
// 		}
// 		return *this;
// 	}

// };
// #endif  // VECTOR2D_H_