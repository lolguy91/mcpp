
#ifndef __VECTOR4F_H__
#define __VECTOR4F_H__

//forward declarations
class Vector3f;
class Quaternion;

class Vector4f {
    public:
    float x;
    float y;
    float z;
    float w;

    Vector4f();
    Vector4f(float f, float f2, float f3, float f4);
    Vector4f(Vector3f const& vector3f);
    bool equals(Vector4f vector4f);
    int hashCode() ;
    void mul(float f);
    void mul(Vector3f vector3f);
    void set(float f, float f2, float f3, float f4);
    void add(float f, float f2, float f3, float f4);
    float dot(Vector4f vector4f);
    bool normalize();

    //void transform(Matrix4f matrix4f);

    void transform(Quaternion quaternion);
    void perspectiveDivide();
    void lerp(Vector4f vector4f, float f);


};
#endif // __VECTOR4F_H__