#pragma once

#include <cmath>

class Vector3 {
public:
    float x, y, z;

    Vector3() : x(0), y(0), z(0) {
    }

    Vector3(float x, float y, float z) : x(x), y(y), z(z) {
    }

    Vector3 operator+(const Vector3 &other) const;

    Vector3 operator-(const Vector3 &other) const;

    Vector3 operator*(float scalar) const;

    Vector3 operator/(float scalar) const;

    float dot(const Vector3 &other) const;

    Vector3 cross(const Vector3 &other) const;

    float magnitude() const;

    float magnitudeSquared() const;

    float length() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    void normalize();
};
