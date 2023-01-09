#ifndef __VECTOR3D_H__
#define __VECTOR3D_H__

class Vector3d {
    public:
    double x;
    double y;
    double z;

    Vector3d(double d, double d2, double d3);
    void set(Vector3d vector3d);
    void set(double d, double d2, double d3);
    void scale(double d);
    void add(Vector3d vector3d);
};
#endif // __VECTOR3D_H__