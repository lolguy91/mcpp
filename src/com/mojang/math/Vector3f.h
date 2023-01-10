
#ifndef __VECTOR3F_H__
#define __VECTOR3F_H__

#include <src/com/mojang/math/Vector4f.h>

class Vector3f {
public:
    float x;
    float y;
    float z;

    Vector3f();

    Vector3f(float f, float f2, float f3);

    Vector3f(Vector4f vector4f);

    //Vector3f(Vec3 vec3);

    bool equals(Vector3f vector3f);

    int hashCode();

    void mul(float f);

    void mul(float f, float f2, float f3);

    void clamp(Vector3f vector3f, Vector3f vector3f2);

    void clamp(float f, float f2);

    void set(float f, float f2, float f3);

    void load(Vector3f vector3f);

    void add(float f, float f2, float f3);

    void add(Vector3f vector3f);

    void sub(Vector3f vector3f);

    float dot(Vector3f vector3f);

    bool normalize();

    void cross(Vector3f vector3f);

    //void transform(Matrix3f matrix3f);

    void transform(Quaternion quaternion);

    void lerp(Vector3f vector3f, float f);

    Quaternion rotation(float f);

    Quaternion rotationDegrees(float f);

    Vector3f copy();

    //void map(Float2FloatFunction float2FloatFunction) {
    //    this.x = float2FloatFunction.get(this.x);
    //    this.y = float2FloatFunction.get(this.y);
    //    this.z = float2FloatFunction.get(this.z);
    //}

};
#endif // __VECTOR3F_H__