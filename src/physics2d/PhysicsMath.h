#ifndef PHYSICMATH_H
#define PHYSICMATH_H

#include <math.h>
#include <cfloat>

typedef float real;

const real PI = 3.141592653589f;
const real RAD = PI / 180;
const real DEG = 180 / PI;

#if !defined(min) || !defined(max)
#define min(a,b) ((a > b) ? (b) : (a))
#define max(a,b) ((a > b) ? (a) : (b))
#endif

#define absf(a) ((a < 0) ? -(real)(a) : (a))
#define pow2(a) ((a) * (a))

struct Vec2
{
    real x, y;

    Vec2(void) : x(0), y(0) {;}
    Vec2(real _x, real _y) : x(_x), y(_y) {;}

    void Set(const real& _x, const real& _y) {
        x = _x;
        y = _y;
    }

    // Vector Magnitude --> Pythagoras theorem |C| = sqrt(A^2 + B^2)
    real Magnitude(void) {
        return sqrtf(x * x + y * y);
    }

    real SquareMagnitude(void) {
        return x * x + y * y;
    }

    Vec2 normalize(void) {
        real mag = Magnitude();
        return mag ? *this * (1.0f / mag) : Vec2();
    }

    void operator += (const Vec2& v) {
        x += v.x;
        y += v.y;
    }

    void operator -= (const Vec2& v) {
        x -= v.x;
        y -= v.y;
    }

    void operator *= (const real& s) {
        x *= s;
        y *= s;
    }

    Vec2 operator + (const Vec2& v) {
        return Vec2(x + v.x, y + v.y);
    }

    Vec2 operator - (const Vec2& v) {
        return Vec2(x - v.x, y - v.y);
    }

    Vec2 operator - (void) {
        return Vec2(-x, -y);
    }

    Vec2 GetAbs(void) {
        return Vec2(absf(x), absf(y));
    }

    real operator * (const Vec2& v) {
        return (x * v.x + y * v.y);
    }

    Vec2 operator * (const real& s) {
        return Vec2 (x * s, y * s);
    }

    void SetZero(void) {x = y = 0.0f;}
};

// The dot product tells us how much the Vector 'A' is pointing over the Vector 'B'.
inline real Dot(const Vec2& v1, const Vec2& v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

// If vectors are not parallel, there is only one solution, either there are infinite number of solutions
inline real Cross(const Vec2& v1, const Vec2& v2) {
    return v1.x * v2.y - v1.y * v2.x;
}

// Cross Product between Vector and Scalar - Counterclockwise Direction
inline Vec2 Cross(const Vec2& v, const real& s) {
    return Vec2(s * v.y, -s * v.x);
}

// Function to limit the minimum and maximum value of the variable
inline real clamp(const real& min, const real& max, const real& v) {
    if (v < min) return min;
    if (v > max) return max;
    return v;
}


// These matrices describe rotations about the origin.
class Mat2 
{
private:
    
    real m00, m01;
    real m10, m11;

public:
    
    Mat2() : m00(0.0f), m01(0.0f), m10(0.0f), m11(0.0f) {;}
    
    Mat2(const real& rad) {
        m00 = cosf(rad);    m01 = -sinf(rad);
        m10 = -m01;         m11 = m00;
    }

    // Returns the Rotation Matrix (Radian - Distance)
    Vec2 Rotate(const real& rad, const Vec2& v) {
        m00 = cosf(rad);    m01 = -sinf(rad);
        m10 = -m01;         m11 = m00;

        return Vec2(
            v.x * m00 + v.y * m01, 
            v.x * m10 + v.y * m11
        );
    }

    // Returns the Rotation Matrix
    Vec2 Rotate(const Vec2& v) {
        return Vec2(
            v.x * m00 + v.y * m01, 
            v.x * m10 + v.y * m11
        );
    }

    Vec2 operator * (const Vec2& v) {
        return Vec2(
            v.x * m00 + v.y * m01, 
            v.x * m10 + v.y * m11
        );
    }

    Vec2 Column0(void) {return Vec2(m00,m10);}
    Vec2 Column1(void) {return Vec2(m01,m11);}

    void Transpose(void) {real temp = m01; m01 = m10; m10 = temp;}

    void SetTranspose(Vec2& v) {
        real x = v.x, y = v.y;
        v.x = x * m00 + y * m10;
        v.y = x * m01 + y * m11;
    }

    Vec2 Transpose(const Vec2& v) {
        return Vec2(
            v.x * m00 + v.y * m10,
            v.x * m01 + v.y * m11
        );
    }
};

#endif  // PHYSICMATH_H