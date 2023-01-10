#ifndef __MATRIX4F_H__
#define __MATRIX4F_H__

#include <src/com/mojang/math/Quaternion.h>
#include <src/com/mojang/math/Vector3f.h>

class Matrix4f {
    public:
    float m00;
    float m01;
    float m02;
    float m03;
    float m10;
    float m11;
    float m12;
    float m13;
    float m20;
    float m21;
    float m22;
    float m23;
    float m30;
    float m31;
    float m32;
    float m33;

    Matrix4f();
    Matrix4f(Quaternion quaternion);
    bool isInteger();
    bool isInteger(float f);
    bool equals(Matrix4f matrix4f);
    int hashCode();
    int bufferIndex(int n, int n2);
    //void load(FloatBuffer floatBuffer);
    //void loadTransposed(FloatBuffer floatBuffer);
    //void load(FloatBuffer floatBuffer, bool bl);
    void load(Matrix4f matrix4f);
    //void store(FloatBuffer floatBuffer);
    //void storeTransposed(FloatBuffer floatBuffer);
    //void store(FloatBuffer floatBuffer, bool bl);
    void setIdentity();
    float adjugateAndDet();
    float determinant();
    void transpose();
    bool invert();
    void multiply(Matrix4f matrix4f);
    void multiply(Quaternion quaternion);
    void multiply(float f);
    void add(Matrix4f matrix4f);
    void subtract(Matrix4f matrix4f);
    float trace();
    Matrix4f perspective(double d, float f, float f2, float f3);
    Matrix4f orthographic(float f, float f2, float f3, float f4);
    Matrix4f orthographic(float f, float f2, float f3, float f4, float f5, float f6);
    void translate(Vector3f vector3f);
    Matrix4f copy();
    void multiplyWithTranslation(float f, float f2, float f3);
    Matrix4f createScaleMatrix(float f, float f2, float f3);
    Matrix4f createTranslateMatrix(float f, float f2, float f3);
};


#endif // __MATRIX4F_H__