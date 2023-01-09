#ifndef __VECTOR3D_H__
#define __VECTOR3D_H__

class Vector3d {
    double x;
    double y;
    double z;

    Vector3d(double d, double d2, double d3) {
        x = d;
        y = d2;
        z = d3;
    }

    void set(Vector3d vector3d) {
        x = vector3d.x;
        y = vector3d.y;
        z = vector3d.z;
    }

    void set(double d, double d2, double d3) {
        x = d;
        y = d2;
        z = d3;
    }

    void scale(double d) {
        x *= d;
        y *= d;
        z *= d;
    }

    void add(Vector3d vector3d) {
        x += vector3d.x;
        y += vector3d.y;
        z += vector3d.z;
    }
};
#endif // __VECTOR3D_H__