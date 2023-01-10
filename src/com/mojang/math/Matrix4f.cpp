#include <src/com/mojang/math/Matrix4f.h>
#include <src/com/mojang/math/Constants.h>
#include <src/net/minecraft/util/Math.h>
#include <math.h>

    Matrix4f::Matrix4f() {
    }

    Matrix4f::Matrix4f(Quaternion quaternion) {
        float f = quaternion.i;
        float f2 = quaternion.j;
        float f3 = quaternion.k;
        float f4 = quaternion.r;
        float f5 = 2.0f * f * f;
        float f6 = 2.0f * f2 * f2;
        float f7 = 2.0f * f3 * f3;
        m00 = 1.0f - f6 - f7;
        m11 = 1.0f - f7 - f5;
        m22 = 1.0f - f5 - f6;
        m33 = 1.0f;
        float f8 = f * f2;
        float f9 = f2 * f3;
        float f10 = f3 * f;
        float f11 = f * f4;
        float f12 = f2 * f4;
        float f13 = f3 * f4;
        m10 = 2.0f * (f8 + f13);
        m01 = 2.0f * (f8 - f13);
        m20 = 2.0f * (f10 - f12);
        m02 = 2.0f * (f10 + f12);
        m21 = 2.0f * (f9 + f11);
        m12 = 2.0f * (f9 - f11);
    }

    bool Matrix4f::isInteger() {
        Matrix4f matrix4f = Matrix4f();
        matrix4f.m30 = 1.0f;
        matrix4f.m31 = 1.0f;
        matrix4f.m32 = 1.0f;
        matrix4f.m33 = 0.0f;
        Matrix4f matrix4f2 = copy();
        matrix4f2.multiply(matrix4f);
        return  isInteger(matrix4f2.m00 / matrix4f2.m03) && 
                isInteger(matrix4f2.m10 / matrix4f2.m13) &&
                isInteger(matrix4f2.m20 / matrix4f2.m23) && 
                isInteger(matrix4f2.m01 / matrix4f2.m03) && 
                isInteger(matrix4f2.m11 / matrix4f2.m13) && 
                isInteger(matrix4f2.m21 / matrix4f2.m23) && 
                isInteger(matrix4f2.m02 / matrix4f2.m03) && 
                isInteger(matrix4f2.m12 / matrix4f2.m13) && 
                isInteger(matrix4f2.m22 / matrix4f2.m23);
    }

    bool Matrix4f::isInteger(float f) {
        return (double)abs(f - (float)round(f)) <= 1.0E-5;
    }

    bool Matrix4f::equals(Matrix4f matrix4f) {
        return  matrix4f.m00 == m00 &&
                matrix4f.m01 == m01 &&
                matrix4f.m02 == m02 &&
                matrix4f.m03 == m03 &&
                matrix4f.m10 == m10 &&
                matrix4f.m11 == m11 &&
                matrix4f.m12 == m12 &&
                matrix4f.m13 == m13 &&
                matrix4f.m20 == m20 &&
                matrix4f.m21 == m21 &&
                matrix4f.m22 == m22 &&
                matrix4f.m23 == m23 &&
                matrix4f.m30 == m30 &&
                matrix4f.m31 == m31 &&
                matrix4f.m32 == m32 &&
                matrix4f.m33 == m33;
    }

    int Matrix4f::hashCode() {
        int n = m00 != 0.0f ? *((int*)&m00) : 0;
        n = 31 * n + (m01 != 0.0f ? *((int*)&m01) : 0);
        n = 31 * n + (m02 != 0.0f ? *((int*)&m02) : 0);
        n = 31 * n + (m03 != 0.0f ? *((int*)&m03) : 0);
        n = 31 * n + (m10 != 0.0f ? *((int*)&m10) : 0);
        n = 31 * n + (m11 != 0.0f ? *((int*)&m11) : 0);
        n = 31 * n + (m12 != 0.0f ? *((int*)&m12) : 0);
        n = 31 * n + (m13 != 0.0f ? *((int*)&m13) : 0);
        n = 31 * n + (m20 != 0.0f ? *((int*)&m20) : 0);
        n = 31 * n + (m21 != 0.0f ? *((int*)&m21) : 0);
        n = 31 * n + (m22 != 0.0f ? *((int*)&m22) : 0);
        n = 31 * n + (m23 != 0.0f ? *((int*)&m23) : 0);
        n = 31 * n + (m30 != 0.0f ? *((int*)&m30) : 0);
        n = 31 * n + (m31 != 0.0f ? *((int*)&m31) : 0);
        n = 31 * n + (m32 != 0.0f ? *((int*)&m32) : 0);
        n = 31 * n + (m33 != 0.0f ? *((int*)&m33) : 0);
        return n;
    }

    int Matrix4f::bufferIndex(int n, int n2) {
        return n2 * 4 + n;
    }

    //void Matrix4f::load(FloatBuffer floatBuffer) {
    //    m00 = floatBuffer.get(Matrix4f.bufferIndex(0, 0));
    //    m01 = floatBuffer.get(Matrix4f.bufferIndex(0, 1));
    //    m02 = floatBuffer.get(Matrix4f.bufferIndex(0, 2));
    //    m03 = floatBuffer.get(Matrix4f.bufferIndex(0, 3));
    //    m10 = floatBuffer.get(Matrix4f.bufferIndex(1, 0));
    //    m11 = floatBuffer.get(Matrix4f.bufferIndex(1, 1));
    //    m12 = floatBuffer.get(Matrix4f.bufferIndex(1, 2));
    //    m13 = floatBuffer.get(Matrix4f.bufferIndex(1, 3));
    //    m20 = floatBuffer.get(Matrix4f.bufferIndex(2, 0));
    //    m21 = floatBuffer.get(Matrix4f.bufferIndex(2, 1));
    //    m22 = floatBuffer.get(Matrix4f.bufferIndex(2, 2));
    //    m23 = floatBuffer.get(Matrix4f.bufferIndex(2, 3));
    //    m30 = floatBuffer.get(Matrix4f.bufferIndex(3, 0));
    //    m31 = floatBuffer.get(Matrix4f.bufferIndex(3, 1));
    //    m32 = floatBuffer.get(Matrix4f.bufferIndex(3, 2));
    //    m33 = floatBuffer.get(Matrix4f.bufferIndex(3, 3));
    //}

    //void Matrix4f::loadTransposed(FloatBuffer floatBuffer) {
    //    m00 = floatBuffer.get(Matrix4f.bufferIndex(0, 0));
    //    m01 = floatBuffer.get(Matrix4f.bufferIndex(1, 0));
    //    m02 = floatBuffer.get(Matrix4f.bufferIndex(2, 0));
    //    m03 = floatBuffer.get(Matrix4f.bufferIndex(3, 0));
    //    m10 = floatBuffer.get(Matrix4f.bufferIndex(0, 1));
    //    m11 = floatBuffer.get(Matrix4f.bufferIndex(1, 1));
    //    m12 = floatBuffer.get(Matrix4f.bufferIndex(2, 1));
    //    m13 = floatBuffer.get(Matrix4f.bufferIndex(3, 1));
    //    m20 = floatBuffer.get(Matrix4f.bufferIndex(0, 2));
    //    m21 = floatBuffer.get(Matrix4f.bufferIndex(1, 2));
    //    m22 = floatBuffer.get(Matrix4f.bufferIndex(2, 2));
    //    m23 = floatBuffer.get(Matrix4f.bufferIndex(3, 2));
    //    m30 = floatBuffer.get(Matrix4f.bufferIndex(0, 3));
    //    m31 = floatBuffer.get(Matrix4f.bufferIndex(1, 3));
    //    m32 = floatBuffer.get(Matrix4f.bufferIndex(2, 3));
    //    m33 = floatBuffer.get(Matrix4f.bufferIndex(3, 3));
    //}

    //void Matrix4f::load(FloatBuffer floatBuffer, bool bl) {
    //    if (bl) {
    //        loadTransposed(floatBuffer);
    //    } else {
    //        load(floatBuffer);
    //    }
    //}

    void Matrix4f::load(Matrix4f matrix4f) {
        m00 = matrix4f.m00;
        m01 = matrix4f.m01;
        m02 = matrix4f.m02;
        m03 = matrix4f.m03;
        m10 = matrix4f.m10;
        m11 = matrix4f.m11;
        m12 = matrix4f.m12;
        m13 = matrix4f.m13;
        m20 = matrix4f.m20;
        m21 = matrix4f.m21;
        m22 = matrix4f.m22;
        m23 = matrix4f.m23;
        m30 = matrix4f.m30;
        m31 = matrix4f.m31;
        m32 = matrix4f.m32;
        m33 = matrix4f.m33;
    }

    //void Matrix4f::store(FloatBuffer floatBuffer) {
    //    floatBuffer.put(Matrix4f.bufferIndex(0, 0), m00);
    //    floatBuffer.put(Matrix4f.bufferIndex(0, 1), m01);
    //    floatBuffer.put(Matrix4f.bufferIndex(0, 2), m02);
    //    floatBuffer.put(Matrix4f.bufferIndex(0, 3), m03);
    //    floatBuffer.put(Matrix4f.bufferIndex(1, 0), m10);
    //    floatBuffer.put(Matrix4f.bufferIndex(1, 1), m11);
    //    floatBuffer.put(Matrix4f.bufferIndex(1, 2), m12);
    //    floatBuffer.put(Matrix4f.bufferIndex(1, 3), m13);
    //    floatBuffer.put(Matrix4f.bufferIndex(2, 0), m20);
    //    floatBuffer.put(Matrix4f.bufferIndex(2, 1), m21);
    //    floatBuffer.put(Matrix4f.bufferIndex(2, 2), m22);
    //    floatBuffer.put(Matrix4f.bufferIndex(2, 3), m23);
    //    floatBuffer.put(Matrix4f.bufferIndex(3, 0), m30);
    //    floatBuffer.put(Matrix4f.bufferIndex(3, 1), m31);
    //    floatBuffer.put(Matrix4f.bufferIndex(3, 2), m32);
    //    floatBuffer.put(Matrix4f.bufferIndex(3, 3), m33);
    //}

    //void Matrix4f::storeTransposed(FloatBuffer floatBuffer) {
    //    floatBuffer.put(Matrix4f.bufferIndex(0, 0), m00);
    //    floatBuffer.put(Matrix4f.bufferIndex(1, 0), m01);
    //    floatBuffer.put(Matrix4f.bufferIndex(2, 0), m02);
    //    floatBuffer.put(Matrix4f.bufferIndex(3, 0), m03);
    //    floatBuffer.put(Matrix4f.bufferIndex(0, 1), m10);
    //    floatBuffer.put(Matrix4f.bufferIndex(1, 1), m11);
    //    floatBuffer.put(Matrix4f.bufferIndex(2, 1), m12);
    //    floatBuffer.put(Matrix4f.bufferIndex(3, 1), m13);
    //    floatBuffer.put(Matrix4f.bufferIndex(0, 2), m20);
    //    floatBuffer.put(Matrix4f.bufferIndex(1, 2), m21);
    //    floatBuffer.put(Matrix4f.bufferIndex(2, 2), m22);
    //    floatBuffer.put(Matrix4f.bufferIndex(3, 2), m23);
    //    floatBuffer.put(Matrix4f.bufferIndex(0, 3), m30);
    //    floatBuffer.put(Matrix4f.bufferIndex(1, 3), m31);
    //    floatBuffer.put(Matrix4f.bufferIndex(2, 3), m32);
    //    floatBuffer.put(Matrix4f.bufferIndex(3, 3), m33);
    //}

    //void Matrix4f::store(FloatBuffer floatBuffer, bool bl) {
    //    if (bl) {
    //        storeTransposed(floatBuffer);
    //    } else {
    //        store(floatBuffer);
    //    }
    //}

    void Matrix4f::setIdentity() {
        m00 = 1.0f;
        m01 = 0.0f;
        m02 = 0.0f;
        m03 = 0.0f;
        m10 = 0.0f;
        m11 = 1.0f;
        m12 = 0.0f;
        m13 = 0.0f;
        m20 = 0.0f;
        m21 = 0.0f;
        m22 = 1.0f;
        m23 = 0.0f;
        m30 = 0.0f;
        m31 = 0.0f;
        m32 = 0.0f;
        m33 = 1.0f;
    }

    float Matrix4f::adjugateAndDet() {
        float f = m00 * m11 - m01 * m10;
        float f2 = m00 * m12 - m02 * m10;
        float f3 = m00 * m13 - m03 * m10;
        float f4 = m01 * m12 - m02 * m11;
        float f5 = m01 * m13 - m03 * m11;
        float f6 = m02 * m13 - m03 * m12;
        float f7 = m20 * m31 - m21 * m30;
        float f8 = m20 * m32 - m22 * m30;
        float f9 = m20 * m33 - m23 * m30;
        float f10 = m21 * m32 - m22 * m31;
        float f11 = m21 * m33 - m23 * m31;
        float f12 = m22 * m33 - m23 * m32;
        float f13 = m11 * f12 - m12 * f11 + m13 * f10;
        float f14 = -m10 * f12 + m12 * f9 - m13 * f8;
        float f15 = m10 * f11 - m11 * f9 + m13 * f7;
        float f16 = -m10 * f10 + m11 * f8 - m12 * f7;
        float f17 = -m01 * f12 + m02 * f11 - m03 * f10;
        float f18 = m00 * f12 - m02 * f9 + m03 * f8;
        float f19 = -m00 * f11 + m01 * f9 - m03 * f7;
        float f20 = m00 * f10 - m01 * f8 + m02 * f7;
        float f21 = m31 * f6 - m32 * f5 + m33 * f4;
        float f22 = -m30 * f6 + m32 * f3 - m33 * f2;
        float f23 = m30 * f5 - m31 * f3 + m33 * f;
        float f24 = -m30 * f4 + m31 * f2 - m32 * f;
        float f25 = -m21 * f6 + m22 * f5 - m23 * f4;
        float f26 = m20 * f6 - m22 * f3 + m23 * f2;
        float f27 = -m20 * f5 + m21 * f3 - m23 * f;
        float f28 = m20 * f4 - m21 * f2 + m22 * f;
        m00 = f13;
        m10 = f14;
        m20 = f15;
        m30 = f16;
        m01 = f17;
        m11 = f18;
        m21 = f19;
        m31 = f20;
        m02 = f21;
        m12 = f22;
        m22 = f23;
        m32 = f24;
        m03 = f25;
        m13 = f26;
        m23 = f27;
        m33 = f28;
        return f * f12 - f2 * f11 + f3 * f10 + f4 * f9 - f5 * f8 + f6 * f7;
    }

    float Matrix4f::determinant() {
        float f = m00 * m11 - m01 * m10;
        float f2 = m00 * m12 - m02 * m10;
        float f3 = m00 * m13 - m03 * m10;
        float f4 = m01 * m12 - m02 * m11;
        float f5 = m01 * m13 - m03 * m11;
        float f6 = m02 * m13 - m03 * m12;
        float f7 = m20 * m31 - m21 * m30;
        float f8 = m20 * m32 - m22 * m30;
        float f9 = m20 * m33 - m23 * m30;
        float f10 = m21 * m32 - m22 * m31;
        float f11 = m21 * m33 - m23 * m31;
        float f12 = m22 * m33 - m23 * m32;
        return f * f12 - f2 * f11 + f3 * f10 + f4 * f9 - f5 * f8 + f6 * f7;
    }

    void Matrix4f::transpose() {
        float f = m10;
        m10 = m01;
        m01 = f;
        f = m20;
        m20 = m02;
        m02 = f;
        f = m21;
        m21 = m12;
        m12 = f;
        f = m30;
        m30 = m03;
        m03 = f;
        f = m31;
        m31 = m13;
        m13 = f;
        f = m32;
        m32 = m23;
        m23 = f;
    }

    bool Matrix4f::invert() {
        float f = adjugateAndDet();
        if (abs(f) > 1.0E-6f) {
            multiply(f);
            return true;
        }
        return false;
    }

    void Matrix4f::multiply(Matrix4f matrix4f) {
        float f = m00 * matrix4f.m00 + m01 * matrix4f.m10 + m02 * matrix4f.m20 + m03 * matrix4f.m30;
        float f2 = m00 * matrix4f.m01 + m01 * matrix4f.m11 + m02 * matrix4f.m21 + m03 * matrix4f.m31;
        float f3 = m00 * matrix4f.m02 + m01 * matrix4f.m12 + m02 * matrix4f.m22 + m03 * matrix4f.m32;
        float f4 = m00 * matrix4f.m03 + m01 * matrix4f.m13 + m02 * matrix4f.m23 + m03 * matrix4f.m33;
        float f5 = m10 * matrix4f.m00 + m11 * matrix4f.m10 + m12 * matrix4f.m20 + m13 * matrix4f.m30;
        float f6 = m10 * matrix4f.m01 + m11 * matrix4f.m11 + m12 * matrix4f.m21 + m13 * matrix4f.m31;
        float f7 = m10 * matrix4f.m02 + m11 * matrix4f.m12 + m12 * matrix4f.m22 + m13 * matrix4f.m32;
        float f8 = m10 * matrix4f.m03 + m11 * matrix4f.m13 + m12 * matrix4f.m23 + m13 * matrix4f.m33;
        float f9 = m20 * matrix4f.m00 + m21 * matrix4f.m10 + m22 * matrix4f.m20 + m23 * matrix4f.m30;
        float f10 = m20 * matrix4f.m01 + m21 * matrix4f.m11 + m22 * matrix4f.m21 + m23 * matrix4f.m31;
        float f11 = m20 * matrix4f.m02 + m21 * matrix4f.m12 + m22 * matrix4f.m22 + m23 * matrix4f.m32;
        float f12 = m20 * matrix4f.m03 + m21 * matrix4f.m13 + m22 * matrix4f.m23 + m23 * matrix4f.m33;
        float f13 = m30 * matrix4f.m00 + m31 * matrix4f.m10 + m32 * matrix4f.m20 + m33 * matrix4f.m30;
        float f14 = m30 * matrix4f.m01 + m31 * matrix4f.m11 + m32 * matrix4f.m21 + m33 * matrix4f.m31;
        float f15 = m30 * matrix4f.m02 + m31 * matrix4f.m12 + m32 * matrix4f.m22 + m33 * matrix4f.m32;
        float f16 = m30 * matrix4f.m03 + m31 * matrix4f.m13 + m32 * matrix4f.m23 + m33 * matrix4f.m33;
        m00 = f;
        m01 = f2;
        m02 = f3;
        m03 = f4;
        m10 = f5;
        m11 = f6;
        m12 = f7;
        m13 = f8;
        m20 = f9;
        m21 = f10;
        m22 = f11;
        m23 = f12;
        m30 = f13;
        m31 = f14;
        m32 = f15;
        m33 = f16;
    }

    void Matrix4f::multiply(Quaternion quaternion) {
        multiply(Matrix4f(quaternion));
    }

    void Matrix4f::multiply(float f) {
        m00 *= f;
        m01 *= f;
        m02 *= f;
        m03 *= f;
        m10 *= f;
        m11 *= f;
        m12 *= f;
        m13 *= f;
        m20 *= f;
        m21 *= f;
        m22 *= f;
        m23 *= f;
        m30 *= f;
        m31 *= f;
        m32 *= f;
        m33 *= f;
    }

    void Matrix4f::add(Matrix4f matrix4f) {
        m00 += matrix4f.m00;
        m01 += matrix4f.m01;
        m02 += matrix4f.m02;
        m03 += matrix4f.m03;
        m10 += matrix4f.m10;
        m11 += matrix4f.m11;
        m12 += matrix4f.m12;
        m13 += matrix4f.m13;
        m20 += matrix4f.m20;
        m21 += matrix4f.m21;
        m22 += matrix4f.m22;
        m23 += matrix4f.m23;
        m30 += matrix4f.m30;
        m31 += matrix4f.m31;
        m32 += matrix4f.m32;
        m33 += matrix4f.m33;
    }

    void Matrix4f::subtract(Matrix4f matrix4f) {
        m00 -= matrix4f.m00;
        m01 -= matrix4f.m01;
        m02 -= matrix4f.m02;
        m03 -= matrix4f.m03;
        m10 -= matrix4f.m10;
        m11 -= matrix4f.m11;
        m12 -= matrix4f.m12;
        m13 -= matrix4f.m13;
        m20 -= matrix4f.m20;
        m21 -= matrix4f.m21;
        m22 -= matrix4f.m22;
        m23 -= matrix4f.m23;
        m30 -= matrix4f.m30;
        m31 -= matrix4f.m31;
        m32 -= matrix4f.m32;
        m33 -= matrix4f.m33;
    }

    float Matrix4f::trace() {
        return m00 + m11 + m22 + m33;
    }

    Matrix4f Matrix4f::perspective(double d, float f, float f2, float f3) {
        float f4 = (float)(1.0 / tan(d * 0.01745329238474369 / 2.0));
        Matrix4f matrix4f = Matrix4f();
        matrix4f.m00 = f4 / f;
        matrix4f.m11 = f4;
        matrix4f.m22 = (f3 + f2) / (f2 - f3);
        matrix4f.m32 = -1.0f;
        matrix4f.m23 = 2.0f * f3 * f2 / (f2 - f3);
        return matrix4f;
    }

    Matrix4f Matrix4f::orthographic(float f, float f2, float f3, float f4) {
        Matrix4f matrix4f = Matrix4f();
        matrix4f.m00 = 2.0f / f;
        matrix4f.m11 = 2.0f / f2;
        float f5 = f4 - f3;
        matrix4f.m22 = -2.0f / f5;
        matrix4f.m33 = 1.0f;
        matrix4f.m03 = -1.0f;
        matrix4f.m13 = 1.0f;
        matrix4f.m23 = -(f4 + f3) / f5;
        return matrix4f;
    }

    Matrix4f Matrix4f::orthographic(float f, float f2, float f3, float f4, float f5, float f6) {
        Matrix4f matrix4f = Matrix4f();
        float f7 = f2 - f;
        float f8 = f3 - f4;
        float f9 = f6 - f5;
        matrix4f.m00 = 2.0f / f7;
        matrix4f.m11 = 2.0f / f8;
        matrix4f.m22 = -2.0f / f9;
        matrix4f.m03 = -(f2 + f) / f7;
        matrix4f.m13 = -(f3 + f4) / f8;
        matrix4f.m23 = -(f6 + f5) / f9;
        matrix4f.m33 = 1.0f;
        return matrix4f;
    }

    void Matrix4f::translate(Vector3f vector3f) {
        m03 += vector3f.x;
        m13 += vector3f.y;
        m23 += vector3f.z;
    }

    Matrix4f Matrix4f::copy() {
        return Matrix4f(*this);
    }

    void Matrix4f::multiplyWithTranslation(float f, float f2, float f3) {
        m03 = m00 * f + m01 * f2 + m02 * f3 + m03;
        m13 = m10 * f + m11 * f2 + m12 * f3 + m13;
        m23 = m20 * f + m21 * f2 + m22 * f3 + m23;
        m33 = m30 * f + m31 * f2 + m32 * f3 + m33;
    }

    Matrix4f Matrix4f::createScaleMatrix(float f, float f2, float f3) {
        Matrix4f matrix4f = Matrix4f();
        matrix4f.m00 = f;
        matrix4f.m11 = f2;
        matrix4f.m22 = f3;
        matrix4f.m33 = 1.0f;
        return matrix4f;
    }

    Matrix4f Matrix4f::createTranslateMatrix(float f, float f2, float f3) {
        Matrix4f matrix4f = Matrix4f();
        matrix4f.m00 = 1.0f;
        matrix4f.m11 = 1.0f;
        matrix4f.m22 = 1.0f;
        matrix4f.m33 = 1.0f;
        matrix4f.m03 = f;
        matrix4f.m13 = f2;
        matrix4f.m23 = f3;
        return matrix4f;
    }