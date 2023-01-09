#ifndef __QUATERNION_H__
#define __QUATERNION_H__
#include <src/com/mojang/math/Vector3f.h>
class Quaternion {
public:
    float i;
    float j;
    float k;
    float r;
    Quaternion(float f, float f2, float f3, float f4);
    Quaternion(Vector3f vector3f, float f, bool bl);
    Quaternion(float f, float f2, float f3, bool bl);
    Quaternion fromYXZ(float f, float f2, float f3);
    Quaternion fromXYZDegrees(Vector3f vector3f);
    Quaternion fromXYZ(Vector3f vector3f);
    Quaternion fromXYZ(float f, float f2, float f3);
    Vector3f toXYZ();
    Vector3f toXYZDegrees();
    bool equals(Quaternion quaternion);
    int hashCode();
    void mul(Quaternion quaternion);
    void mul(float f);
    void conj();
    void set(float f, float f2, float f3, float f4);
    void normalize();
    Quaternion copy();
};
#endif // __QUATERNION_H__