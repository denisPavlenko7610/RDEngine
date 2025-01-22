#pragma once

struct Vector2 {
    float x;
    float y;

    Vector2(float x = 0.0f, float y = 0.0f);

    float Length() const;
    Vector2 Normalized() const;
    static float Dot(const Vector2& a, const Vector2& b);
    static float Distance(const Vector2& a, const Vector2& b);
    
    Vector2 operator-(const Vector2& other) const;
};
