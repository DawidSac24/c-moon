//
// Created by dawid on 10/29/26.
//

#include "../../include/math/Vector3.hpp"

void Vector3::clear() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

double Vector3::length() const {
    return std::sqrt(x * x + y * y + z * z);
}

double Vector3::dot(const Vector3 &other) const {
    return x * other.x + y * other.y + z * other.z;
}

Vector3 Vector3::cross(const Vector3 &other) const {
    return {
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    };
}

double Vector3::magnitudeSquared() const {
    return x * x + y * y + z * z;
}

Vector3 Vector3::abs() const {
    return {std::abs(x), std::abs(y), std::abs(z)};
}

Vector3 Vector3::normalized() {
    Vector3 res = *this;
    float len = length();
    if (len > 0) {
        res.x /= len;
        res.y /= len;
        res.z /= len;
    }
    return res;
}


Vector3 Vector3::operator+(const Vector3 &other) const {
    return {x + other.x, y + other.y, z + other.z};
}

void Vector3::operator+=(const Vector3 &other) {
    x += other.x;
    y += other.y;
    z += other.z;
}

Vector3 Vector3::operator-(const Vector3 &other) const {
    return {x - other.x, y - other.y, z - other.z};
}

void Vector3::operator-=(const Vector3 &other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
}

Vector3 Vector3::operator*(double scalar) const {
    return {x * scalar, y * scalar, z * scalar};
}

Vector3 Vector3::operator/(double scalar) const {
    return {x / scalar, y / scalar, z / scalar};
}
