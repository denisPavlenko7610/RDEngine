#include "Vector3.h"

#include <cmath>

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

float Vector3::Length() const {
    return std::sqrt(x * x + y * y + z * z);
}

Vector3 Vector3::Normalized() const {
    float length = Length();
    if (length == 0) return Vector3(0, 0, 0);
    return Vector3(x / length, y / length, z / length);
}

float Vector3::Dot(const Vector3& a, const Vector3& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector3 Vector3::Cross(const Vector3& a, const Vector3& b) {
    return Vector3(
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    );
}

float Vector3::Distance(const Vector3& a, const Vector3& b) {
    return (b - a).Length();
}

Vector3 Vector3::operator-(const Vector3& other) const {
    return Vector3(x - other.x, y - other.y, z - other.z);
}
