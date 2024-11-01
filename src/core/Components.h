// Component.h
#ifndef SRC_CORE_COMPONENTS_H
#define SRC_CORE_COMPONENTS_H

#include <raylib-cpp.hpp>

struct PositionComponent {
    Vector2 position_;

    PositionComponent(float x, float y) : position_((Vector2){x, y}) {}
    PositionComponent(Vector2 pos) : position_(pos) {}
};

struct HealthComponent {
    float health_;
    
    HealthComponent(float initialHealth) : health_(initialHealth) {}
};

struct TextComponent {
    float fontSize_;
    float textSpacing_;
    float lineSpacing_;
    Color primaryColor_;
    Color accentColor_;
    Vector2 position_;

    TextComponent(float fontSize, float ts, float ls, Color primary, Color accent) 
        : fontSize_(fontSize)
        , textSpacing_(ts)
        , lineSpacing_(ls)
        , primaryColor_(primary)
        , accentColor_(accent)
        , position_({0.0f, 0.0f})
    {}
};

struct ColorComponent {
    Color value_;
    ColorComponent(Color color) : value_(color) {}
    ColorComponent(unsigned int hexValue) : value_(raylib::Color(hexValue)) {}
    ColorComponent(Vector3 hsv) : value_(raylib::Color(hsv)) {}
    ColorComponent(unsigned char r, unsigned char g, unsigned char b, unsigned char a) : value_(raylib::Color(r, g, b, a)) {}
};

#endif // SRC_CORE_COMPONENTS_H
