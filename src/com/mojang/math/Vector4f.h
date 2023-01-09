#include <src/com/mojang/math/Vector3f.h>
#include <src/com/mojang/math/Quaternion.h>
class Vector4f {
    public:
    float x;
    float y;
    float z;
    float w;

    Vector4f();
    Vector4f(float f, float f2, float f3, float f4);
    Vector4f(Vector3f vector3f);
    bool equals(Vector4f vector4f);
    int hashCode() ;
    void mul(float f);
    void mul(Vector3f vector3f);
    void set(float f, float f2, float f3, float f4);
    void add(float f, float f2, float f3, float f4);
    float dot(Vector4f vector4f);
    bool normalize();

    //void transform(Matrix4f matrix4f) {
    //    float f =  x;
    //    float f2 = y;
    //    float f3 = z;
    //    float f4 = w;
    //    x = matrix4f.m00 * f + matrix4f.m01 * f2 + matrix4f.m02 * f3 + matrix4f.m03 * f4;
    //    y = matrix4f.m10 * f + matrix4f.m11 * f2 + matrix4f.m12 * f3 + matrix4f.m13 * f4;
    //    z = matrix4f.m20 * f + matrix4f.m21 * f2 + matrix4f.m22 * f3 + matrix4f.m23 * f4;
    //    w = matrix4f.m30 * f + matrix4f.m31 * f2 + matrix4f.m32 * f3 + matrix4f.m33 * f4;
    //}

    void transform(Quaternion quaternion);
    void perspectiveDivide();
    void lerp(Vector4f vector4f, float f);


};