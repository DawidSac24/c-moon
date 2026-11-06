#pragma once

#include <cmath>

class Vector3 {
public:
    double x, y, z;

    Vector3() : x(0), y(0), z(0) {
    }

    Vector3(double x, double y, double z) : x(x), y(y), z(z) {
    }

    void clear();

    double length() const;

    double dot(const Vector3 &other) const;

    Vector3 cross(const Vector3 &other) const;

    double magnitudeSquared() const;

    Vector3 abs() const;

    Vector3 normalized();


    Vector3 operator+(const Vector3 &other) const;

    void operator+=(const Vector3 &other);

    Vector3 operator-(const Vector3 &other) const;

    void operator-=(const Vector3 &other);

    Vector3 operator*(double scalar) const;

    Vector3 operator/(double scalar) const;
};
