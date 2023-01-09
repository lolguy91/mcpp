#include <src/com/mojang/math/Vector3d.h>

Vector3d::Vector3d(double d, double d2, double d3) {
    x = d;
    y = d2;
    z = d3;
}

void Vector3d::set(Vector3d vector3d) {
    x = vector3d.x;
    y = vector3d.y;
    z = vector3d.z;
}

void Vector3d::set(double d, double d2, double d3) {
    x = d;
    y = d2;
    z = d3;
}

void Vector3d::scale(double d) {
    x *= d;
    y *= d;
    z *= d;
}

void Vector3d::add(Vector3d vector3d) {
    x += vector3d.x;
    y += vector3d.y;
    z += vector3d.z;
}