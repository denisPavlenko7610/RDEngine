#pragma once

struct Vector3 {
    float x;
    float y;
    float z;

    Vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f);

    float Length() const;
    Vector3 Normalized() const;
    static float Dot(const Vector3& a, const Vector3& b);
    static Vector3 Cross(const Vector3& a, const Vector3& b);
    static float Distance(const Vector3& a, const Vector3& b);
    
    Vector3 operator-(const Vector3& other) const;
};
