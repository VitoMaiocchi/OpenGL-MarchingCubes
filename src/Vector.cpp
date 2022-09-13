#include "Vector.h"
#include <math.h>
#include <iostream>

Vector3f::Vector3f(float x, float y, float z) {
    Vector3f::x = x;
    Vector3f::y = y;
    Vector3f::z = z;
};

Vector3f::Vector3f() {
};

void Vector3f::set(float x, float y, float z) {
    Vector3f::x = x;
    Vector3f::y = y;
    Vector3f::z = z;
};

Vector3i::Vector3i(int x, int y, int z) {
    Vector3i::x = x;
    Vector3i::y = y;
    Vector3i::z = z;
};

Vector3f addVector(Vector3f v1, Vector3f v2) {
    return Vector3f(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Vector3i addVector(Vector3i v1, Vector3i v2) {
    return Vector3i(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

float dotProduct(Vector3f v1, Vector3f v2) {
    return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

Vector3i floor(Vector3f vector) {
    return Vector3i( (int)floor(vector.x), (int)floor(vector.y), (int)floor(vector.z) );
}

Vector3f subtractVector(Vector3f v1, Vector3f v2) {
    return Vector3f(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

Vector3f subtractVector(Vector3f v1, Vector3i v2) {
    return Vector3f(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

std::string Vector3f::print() {
    return "Vector{ x: "+ std::to_string(Vector3f::x) +", y: "+ std::to_string(Vector3f::y) +", z: "+ std::to_string(Vector3f::z)+ " }";
}

std::string Vector3i::print() {
    return "Vector{ x: "+ std::to_string(Vector3i::x) +", y: "+ std::to_string(Vector3i::y) +", z: "+ std::to_string(Vector3i::z)+ " }";
}