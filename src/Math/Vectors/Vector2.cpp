#include "Vector2.h"
#include <cmath>

Vector2::Vector2(float x, float y) : x(x), y(y) {}

float Vector2::Length() const {
    return std::sqrt(x * x + y * y);
}

Vector2 Vector2::Normalized() const {
    float length = Length();
    if (length == 0) return Vector2(0, 0);
    return Vector2(x / length, y / length);
}

float Vector2::Dot(const Vector2& a, const Vector2& b) {
    return a.x * b.x + a.y * b.y;
}

float Vector2::Distance(const Vector2& a, const Vector2& b) {
    return (b - a).Length();
}

Vector2 Vector2::operator-(const Vector2& other) const {
    return Vector2(x - other.x, y - other.y);
}
