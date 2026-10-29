//
// Created by dawid on 10/29/26.
//

#include "Vector3.hpp"

Vector3 Vector3::operator+(const Vector3 &other) const {
    return {x + other.x, y + other.y, z + other.z};
}

Vector3 Vector3::operator-(const Vector3 &other) const {
    return {x - other.x, y - other.y, z - other.z};
}

Vector3 Vector3::operator*(float scalar) const {
    return {x * scalar, y * scalar, z * scalar};
}

Vector3 Vector3::operator/(float scalar) const {
    return {x / scalar, y / scalar, z / scalar};
}

float Vector3::dot(const Vector3 &other) const {
    return x * other.x + y * other.y + z * other.z;
}

Vector3 Vector3::cross(const Vector3 &other) const {
    return {
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    };
}

float Vector3::magnitude() const {
    return std::sqrt(x * x + y * y + z * z);
}

float Vector3::magnitudeSquared() const {
    return x * x + y * y + z * z;
}

void Vector3::normalize() {
    float len = length();
    if (len > 0) {
        x /= len;
        y /= len;
        z /= len;
    }
}
