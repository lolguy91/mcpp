#ifndef __MATRIX3F_H__
#define __MATRIX3F_H__

#include <src/com/mojang/math/Quaternion.h>
class Matrix3f {
public:
    float m00;
    float m01;
    float m02;
    float m10;
    float m11;
    float m12;
    float m20;
    float m21;
    float m22;

    Matrix3f();

    Matrix3f(Quaternion quaternion);

    Matrix3f createScaleMatrix(float f, float f2, float f3);
    //Matrix3f(Matrix4f matrix4f);

    //Matrix3f(Matrix3f matrix3f);
    //private static Pair<Float, Float> approxGivensQuat(float f, float f2, float f3);
    //private static Pair<Float, Float> qrGivensQuat(float f, float f2);
    //Quaternion stepJacobi(Matrix3f matrix3f);
    void sortSingularValues(Matrix3f matrix3f, Quaternion quaternion);
    void transpose();
    //Triple<Quaternion, Vector3f, Quaternion> svdDecompose();
    bool equals(Matrix3f matrix3f);
    int hashCode();
    int bufferIndex(int n, int n2);
    //void load(FloatBuffer floatBuffer);
    //void loadTransposed(FloatBuffer floatBuffer);
    //void load(FloatBuffer floatBuffer, boolean bl);
    void load(Matrix3f matrix3f);
    //void store(FloatBuffer floatBuffer);
    //void storeTransposed(FloatBuffer floatBuffer);
    //void store(FloatBuffer floatBuffer, bool bl);
    void setIdentity();
    float adjugateAndDet();
    float determinant();
    bool invert();
    void set(int n, int n2, float f);
    void mul(Matrix3f matrix3f);
    void mul(Quaternion quaternion);
    void mul(float f);
    void add(Matrix3f matrix3f);
    void sub(Matrix3f matrix3f);
    float trace();
    Matrix3f copy();
};
#endif // __MATRIX3F_H__