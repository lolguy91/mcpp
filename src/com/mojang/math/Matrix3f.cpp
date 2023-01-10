#include <src/com/mojang/math/Matrix3f.h>
#include <src/com/mojang/math/Constants.h>
#include <src/net/minecraft/util/Math.h>
#include <math.h>

#define ORDER   3
#define G       5.82842712475
#define CS      0.92387956377 
#define SS      0.38268335688
#define SQ2     0.70711356243

Matrix3f::Matrix3f(){

}
Matrix3f::Matrix3f(Quaternion quaternion) {
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

Matrix3f Matrix3f::createScaleMatrix(float f, float f2, float f3) {
    Matrix3f matrix3f = Matrix3f();
    matrix3f.m00 = f;
    matrix3f.m11 = f2;
    matrix3f.m22 = f3;
    return matrix3f;
}

//Matrix3f::Matrix3f(Matrix4f matrix4f) {
//    m00 = matrix4f.m00;
//    m01 = matrix4f.m01;
//    m02 = matrix4f.m02;
//    m10 = matrix4f.m10;
//    m11 = matrix4f.m11;
//    m12 = matrix4f.m12;
//    m20 = matrix4f.m20;
//    m21 = matrix4f.m21;
//    m22 = matrix4f.m22;
//}

//Matrix3f::Matrix3f(Matrix3f matrix3f) {
//    m00 = matrix3f.m00;
//    m01 = matrix3f.m01;
//    m02 = matrix3f.m02;
//    m10 = matrix3f.m10;
//    m11 = matrix3f.m11;
//    m12 = matrix3f.m12;
//    m20 = matrix3f.m20;
//    m21 = matrix3f.m21;
//    m22 = matrix3f.m22;
//}

//private static Pair<Float, Float> Matrix3f::approxGivensQuat(float f, float f2, float f3) {
//    float f4 = f2;
//    float f5 = 2.0f * (f - f3);
//    if (G * f4 * f4 < f5 * f5) {
//        float f6 = Mth.fastInvSqrt(f4 * f4 + f5 * f5);
//        return Pair.of((Object)Float.valueOf(f6 * f4), (Object)Float.valueOf(f6 * f5));
//    }
//    return Pair.of((Object)Float.valueOf(SS), (Object)Float.valueOf(CS));
//}

//private static Pair<Float, Float> Matrix3f::qrGivensQuat(float f, float f2) {
//    float f3;
//    float f4 = (float)Math.hypot(f, f2);
//    float f5 = f4 > 1.0E-6f ? f2 : 0.0f;
//    float f6 = Math.abs(f) + Math.max(f4, 1.0E-6f);
//    if (f < 0.0f) {
//        f3 = f5;
//        f5 = f6;
//        f6 = f3;
//    }
//    f3 = Mth.fastInvSqrt(f6 * f6 + f5 * f5);
//    return Pair.of((Object)Float.valueOf(f5 *= f3), (Object)Float.valueOf(f6 *= f3));
//}

//Quaternion Matrix3f::stepJacobi(Matrix3f matrix3f) {
//    float f;
//    float f2;
//    float f3;
//    Quaternion quaternion;
//    float f4;
//    float f5;
//    Pair<Float, Float> pair;
//    Matrix3f matrix3f2 = new Matrix3f();
//    Quaternion quaternion2 = Quaternion.ONE.copy();
//    if (matrix3f.m01 * matrix3f.m01 + matrix3f.m10 * matrix3f.m10 > 1.0E-6f) {
//        pair = Matrix3f.approxGivensQuat(matrix3f.m00, 0.5f * (matrix3f.m01 + matrix3f.m10), matrix3f.m11);
//        f5 = (Float)pair.getFirst();
//        f4 = (Float)pair.getSecond();
//        quaternion = new Quaternion(0.0f, 0.0f, f5.floatValue(), f4.floatValue());
//        f3 = f4.floatValue() * f4.floatValue() - f5.floatValue() * f5.floatValue();
//        f2 = -2.0f * f5.floatValue() * f4.floatValue();
//        f = f4.floatValue() * f4.floatValue() + f5.floatValue() * f5.floatValue();
//        quaternion2.mul(quaternion);
//        matrix3f2.setIdentity();
//        matrix3f2.m00 = f3;
//        matrix3f2.m11 = f3;
//        matrix3f2.m10 = -f2;
//        matrix3f2.m01 = f2;
//        matrix3f2.m22 = f;
//        matrix3f.mul(matrix3f2);
//        matrix3f2.transpose();
//        matrix3f2.mul(matrix3f);
//        matrix3f.load(matrix3f2);
//    }
//    if (matrix3f.m02 * matrix3f.m02 + matrix3f.m20 * matrix3f.m20 > 1.0E-6f) {
//        pair = Matrix3f.approxGivensQuat(matrix3f.m00, 0.5f * (matrix3f.m02 + matrix3f.m20), matrix3f.m22);
//        float f6 = -((Float)pair.getFirst()).floatValue();
//        f4 = (Float)pair.getSecond();
//        quaternion = new Quaternion(0.0f, f6, 0.0f, f4.floatValue());
//        f3 = f4.floatValue() * f4.floatValue() - f6 * f6;
//        f2 = -2.0f * f6 * f4.floatValue();
//        f = f4.floatValue() * f4.floatValue() + f6 * f6;
//        quaternion2.mul(quaternion);
//        matrix3f2.setIdentity();
//        matrix3f2.m00 = f3;
//        matrix3f2.m22 = f3;
//        matrix3f2.m20 = f2;
//        matrix3f2.m02 = -f2;
//        matrix3f2.m11 = f;
//        matrix3f.mul(matrix3f2);
//        matrix3f2.transpose();
//        matrix3f2.mul(matrix3f);
//        matrix3f.load(matrix3f2);
//    }
//    if (matrix3f.m12 * matrix3f.m12 + matrix3f.m21 * matrix3f.m21 > 1.0E-6f) {
//        pair = Matrix3f.approxGivensQuat(matrix3f.m11, 0.5f * (matrix3f.m12 + matrix3f.m21), matrix3f.m22);
//        f5 = (Float)pair.getFirst();
//        f4 = (Float)pair.getSecond();
//        quaternion = new Quaternion(f5.floatValue(), 0.0f, 0.0f, f4.floatValue());
//        f3 = f4.floatValue() * f4.floatValue() - f5.floatValue() * f5.floatValue();
//        f2 = -2.0f * f5.floatValue() * f4.floatValue();
//        f = f4.floatValue() * f4.floatValue() + f5.floatValue() * f5.floatValue();
//        quaternion2.mul(quaternion);
//        matrix3f2.setIdentity();
//        matrix3f2.m11 = f3;
//        matrix3f2.m22 = f3;
//        matrix3f2.m21 = -f2;
//        matrix3f2.m12 = f2;
//        matrix3f2.m00 = f;
//        matrix3f.mul(matrix3f2);
//        matrix3f2.transpose();
//        matrix3f2.mul(matrix3f);
//        matrix3f.load(matrix3f2);
//    }
//    return quaternion2;
//}

void Matrix3f::sortSingularValues(Matrix3f matrix3f, Quaternion quaternion) {
    Quaternion quaternion2;
    float f;
    float f2 = matrix3f.m00 * matrix3f.m00 + matrix3f.m10 * matrix3f.m10 + matrix3f.m20 * matrix3f.m20;
    float f3 = matrix3f.m01 * matrix3f.m01 + matrix3f.m11 * matrix3f.m11 + matrix3f.m21 * matrix3f.m21;
    float f4 = matrix3f.m02 * matrix3f.m02 + matrix3f.m12 * matrix3f.m12 + matrix3f.m22 * matrix3f.m22;
    if (f2 < f3) {
        f = matrix3f.m10;
        matrix3f.m10 = -matrix3f.m00;
        matrix3f.m00 = f;
        f = matrix3f.m11;
        matrix3f.m11 = -matrix3f.m01;
        matrix3f.m01 = f;
        f = matrix3f.m12;
        matrix3f.m12 = -matrix3f.m02;
        matrix3f.m02 = f;
        quaternion2 = Quaternion(0.0f, 0.0f, SQ2,  (float)(SQ2));
        quaternion.mul(quaternion2);
        f = f2;
        f2 = f3;
        f3 = f;
    }
    if (f2 < f4) {
        f = matrix3f.m20;
        matrix3f.m20 = -matrix3f.m00;
        matrix3f.m00 = f;
        f = matrix3f.m21;
        matrix3f.m21 = -matrix3f.m01;
        matrix3f.m01 = f;
        f = matrix3f.m22;
        matrix3f.m22 = -matrix3f.m02;
        matrix3f.m02 = f;
        quaternion2 = Quaternion(0.0f, SQ2, 0.0f, (float)(SQ2));
        quaternion.mul(quaternion2);
        f4 = f2;
    }
    if (f3 < f4) {
        f = matrix3f.m20;
        matrix3f.m20 = -matrix3f.m10;
        matrix3f.m10 = f;
        f = matrix3f.m21;
        matrix3f.m21 = -matrix3f.m11;
        matrix3f.m11 = f;
        f = matrix3f.m22;
        matrix3f.m22 = -matrix3f.m12;
        matrix3f.m12 = f;
        quaternion2 = Quaternion(SQ2, 0.0f, 0.0f,  (float)(SQ2));
        quaternion.mul(quaternion2);
    }
}

void Matrix3f::transpose() {
    float f = m01;
    m01 = m10;
    m10 = f;
    f = m02;
    m02 = m20;
    m20 = f;
    f = m12;
    m12 = m21;
    m21 = f;
}

//Triple<Quaternion, Vector3f, Quaternion> Matrix3f::svdDecompose() {
//    Quaternion quaternion = Quaternion.ONE.copy();
//    Quaternion quaternion2 = Quaternion.ONE.copy();
//    Matrix3f matrix3f = this.copy();
//    matrix3f.transpose();
//    matrix3f.mul(this);
//    for (int i = 0; i < 5; ++i) {
//        quaternion2.mul(Matrix3f.stepJacobi(matrix3f));
//    }
//    quaternion2.normalize();
//    Matrix3f matrix3f2 = new Matrix3f(this);
//    matrix3f2.mul(new Matrix3f(quaternion2));
//    float f = 1.0f;
//    Pair<Float, Float> pair = Matrix3f.qrGivensQuat(matrix3f2.m00, matrix3f2.m10);
//    Float f2 = (Float)pair.getFirst();
//    Float f3 = (Float)pair.getSecond();
//    float f4 = f3.floatValue() * f3.floatValue() - f2.floatValue() * f2.floatValue();
//    float f5 = -2.0f * f2.floatValue() * f3.floatValue();
//    float f6 = f3.floatValue() * f3.floatValue() + f2.floatValue() * f2.floatValue();
//    Quaternion quaternion3 = new Quaternion(0.0f, 0.0f, f2.floatValue(), f3.floatValue());
//    quaternion.mul(quaternion3);
//    Matrix3f matrix3f3 = new Matrix3f();
//    matrix3f3.setIdentity();
//    matrix3f3.m00 = f4;
//    matrix3f3.m11 = f4;
//    matrix3f3.m10 = f5;
//    matrix3f3.m01 = -f5;
//    matrix3f3.m22 = f6;
//    f *= f6;
//    matrix3f3.mul(matrix3f2);
//    pair = Matrix3f.qrGivensQuat(matrix3f3.m00, matrix3f3.m20);
//    float f7 = -((Float)pair.getFirst()).floatValue();
//    Float f8 = (Float)pair.getSecond();
//    float f9 = f8.floatValue() * f8.floatValue() - f7 * f7;
//    float f10 = -2.0f * f7 * f8.floatValue();
//    float f11 = f8.floatValue() * f8.floatValue() + f7 * f7;
//    Quaternion quaternion4 = new Quaternion(0.0f, f7, 0.0f, f8.floatValue());
//    quaternion.mul(quaternion4);
//    Matrix3f matrix3f4 = new Matrix3f();
//    matrix3f4.setIdentity();
//    matrix3f4.m00 = f9;
//    matrix3f4.m22 = f9;
//    matrix3f4.m20 = -f10;
//    matrix3f4.m02 = f10;
//    matrix3f4.m11 = f11;
//    f *= f11;
//    matrix3f4.mul(matrix3f3);
//    pair = Matrix3f.qrGivensQuat(matrix3f4.m11, matrix3f4.m21);
//    Float f12 = (Float)pair.getFirst();
//    Float f13 = (Float)pair.getSecond();
//    float f14 = f13.floatValue() * f13.floatValue() - f12.floatValue() * f12.floatValue();
//    float f15 = -2.0f * f12.floatValue() * f13.floatValue();
//    float f16 = f13.floatValue() * f13.floatValue() + f12.floatValue() * f12.floatValue();
//    Quaternion quaternion5 = new Quaternion(f12.floatValue(), 0.0f, 0.0f, f13.floatValue());
//    quaternion.mul(quaternion5);
//    Matrix3f matrix3f5 = new Matrix3f();
//    matrix3f5.setIdentity();
//    matrix3f5.m11 = f14;
//    matrix3f5.m22 = f14;
//    matrix3f5.m21 = f15;
//    matrix3f5.m12 = -f15;
//    matrix3f5.m00 = f16;
//    f *= f16;
//    matrix3f5.mul(matrix3f4);
//    f = 1.0f / f;
//    quaternion.mul((float)Math.sqrt(f));
//    Vector3f vector3f = new Vector3f(matrix3f5.m00 * f, matrix3f5.m11 * f, matrix3f5.m22 * f);
//    return Triple.of((Object)quaternion, (Object)vector3f, (Object)quaternion2);
//}

bool Matrix3f::equals(Matrix3f matrix3f) {
    return  matrix3f.m00 == m00 &&
            matrix3f.m01 == m01 &&
            matrix3f.m02 == m02 &&
            matrix3f.m10 == m10 &&
            matrix3f.m11 == m11 &&
            matrix3f.m12 == m12 &&
            matrix3f.m20 == m20 &&
            matrix3f.m21 == m21 &&
            matrix3f.m22 == m22;
}

int Matrix3f::hashCode() {
    int n = m00 != 0.0f ? *((int*)&m00) : 0;
    n = 31 * n + (m01 != 0.0f ? *((int*)&m01) : 0);
    n = 31 * n + (m02 != 0.0f ? *((int*)&m02) : 0);
    n = 31 * n + (m10 != 0.0f ? *((int*)&m10) : 0);
    n = 31 * n + (m11 != 0.0f ? *((int*)&m11) : 0);
    n = 31 * n + (m12 != 0.0f ? *((int*)&m12) : 0);
    n = 31 * n + (m20 != 0.0f ? *((int*)&m20) : 0);
    n = 31 * n + (m21 != 0.0f ? *((int*)&m21) : 0);
    n = 31 * n + (m22 != 0.0f ? *((int*)&m22) : 0);
    return n;
}

int bufferIndex(int n, int n2) {
    return n2 * 3 + n;
}

//void Matrix3f::load(FloatBuffer floatBuffer) {
//    m00 = floatBuffer.get(Matrix3f.bufferIndex(0, 0));
//    m01 = floatBuffer.get(Matrix3f.bufferIndex(0, 1));
//    m02 = floatBuffer.get(Matrix3f.bufferIndex(0, 2));
//    m10 = floatBuffer.get(Matrix3f.bufferIndex(1, 0));
//    m11 = floatBuffer.get(Matrix3f.bufferIndex(1, 1));
//    m12 = floatBuffer.get(Matrix3f.bufferIndex(1, 2));
//    m20 = floatBuffer.get(Matrix3f.bufferIndex(2, 0));
//    m21 = floatBuffer.get(Matrix3f.bufferIndex(2, 1));
//    m22 = floatBuffer.get(Matrix3f.bufferIndex(2, 2));
//}

//void Matrix3f::loadTransposed(FloatBuffer floatBuffer) {
//    m00 = floatBuffer.get(Matrix3f.bufferIndex(0, 0));
//    m01 = floatBuffer.get(Matrix3f.bufferIndex(1, 0));
//    m02 = floatBuffer.get(Matrix3f.bufferIndex(2, 0));
//    m10 = floatBuffer.get(Matrix3f.bufferIndex(0, 1));
//    m11 = floatBuffer.get(Matrix3f.bufferIndex(1, 1));
//    m12 = floatBuffer.get(Matrix3f.bufferIndex(2, 1));
//    m20 = floatBuffer.get(Matrix3f.bufferIndex(0, 2));
//    m21 = floatBuffer.get(Matrix3f.bufferIndex(1, 2));
//    m22 = floatBuffer.get(Matrix3f.bufferIndex(2, 2));
//}

//void Matrix3f::load(FloatBuffer floatBuffer, bool bl) {
//    if (bl) {
//        this.loadTransposed(floatBuffer);
//    } else {
//        this.load(floatBuffer);
//    }
//}

void Matrix3f::load(Matrix3f matrix3f) {
    m00 = matrix3f.m00;
    m01 = matrix3f.m01;
    m02 = matrix3f.m02;
    m10 = matrix3f.m10;
    m11 = matrix3f.m11;
    m12 = matrix3f.m12;
    m20 = matrix3f.m20;
    m21 = matrix3f.m21;
    m22 = matrix3f.m22;
}

//void Matrix3f::store(FloatBuffer floatBuffer) {
//    floatBuffer.put(Matrix3f.bufferIndex(0, 0), m00);
//    floatBuffer.put(Matrix3f.bufferIndex(0, 1), m01);
//    floatBuffer.put(Matrix3f.bufferIndex(0, 2), m02);
//    floatBuffer.put(Matrix3f.bufferIndex(1, 0), m10);
//    floatBuffer.put(Matrix3f.bufferIndex(1, 1), m11);
//    floatBuffer.put(Matrix3f.bufferIndex(1, 2), m12);
//    floatBuffer.put(Matrix3f.bufferIndex(2, 0), m20);
//    floatBuffer.put(Matrix3f.bufferIndex(2, 1), m21);
//    floatBuffer.put(Matrix3f.bufferIndex(2, 2), m22);
//}

//void Matrix3f::storeTransposed(FloatBuffer floatBuffer) {
//    floatBuffer.put(Matrix3f.bufferIndex(0, 0), m00);
//    floatBuffer.put(Matrix3f.bufferIndex(1, 0), m01);
//    floatBuffer.put(Matrix3f.bufferIndex(2, 0), m02);
//    floatBuffer.put(Matrix3f.bufferIndex(0, 1), m10);
//    floatBuffer.put(Matrix3f.bufferIndex(1, 1), m11);
//    floatBuffer.put(Matrix3f.bufferIndex(2, 1), m12);
//    floatBuffer.put(Matrix3f.bufferIndex(0, 2), m20);
//    floatBuffer.put(Matrix3f.bufferIndex(1, 2), m21);
//    floatBuffer.put(Matrix3f.bufferIndex(2, 2), m22);
//}

//void Matrix3f::store(FloatBuffer floatBuffer, bool bl) {
//    if (bl) {
//        this.storeTransposed(floatBuffer);
//    } else {
//        this.store(floatBuffer);
//    }
//}

void Matrix3f::setIdentity() {
    m00 = 1.0f;
    m01 = 0.0f;
    m02 = 0.0f;
    m10 = 0.0f;
    m11 = 1.0f;
    m12 = 0.0f;
    m20 = 0.0f;
    m21 = 0.0f;
    m22 = 1.0f;
}

float Matrix3f::adjugateAndDet() {
    float f = m11 * m22 - m12 * m21;
    float f2 = -(m10 * m22 - m12 * m20);
    float f3 = m10 * m21 - m11 * m20;
    float f4 = -(m01 * m22 - m02 * m21);
    float f5 = m00 * m22 - m02 * m20;
    float f6 = -(m00 * m21 - m01 * m20);
    float f7 = m01 * m12 - m02 * m11;
    float f8 = -(m00 * m12 - m02 * m10);
    float f9 = m00 * m11 - m01 * m10;
    float f10 = m00 * f + m01 * f2 + m02 * f3;
    m00 = f;
    m10 = f2;
    m20 = f3;
    m01 = f4;
    m11 = f5;
    m21 = f6;
    m02 = f7;
    m12 = f8;
    m22 = f9;
    return f10;
}

float Matrix3f::determinant() {
    float f = m11 * m22 - m12 * m21;
    float f2 = -(m10 * m22 - m12 * m20);
    float f3 = m10 * m21 - m11 * m20;
    return m00 * f + m01 * f2 + m02 * f3;
}

bool Matrix3f::invert() {
    float f = adjugateAndDet();
    if (abs(f) > 1.0E-6f) {
        mul(f);
        return true;
    }
    return false;
}

void Matrix3f::set(int n, int n2, float f) {
    if (n == 0) {
        if (n2 == 0) {
            m00 = f;
        } else if (n2 == 1) {
            m01 = f;
        } else {
            m02 = f;
        }
    } else if (n == 1) {
        if (n2 == 0) {
            m10 = f;
        } else if (n2 == 1) {
            m11 = f;
        } else {
            m12 = f;
        }
    } else if (n2 == 0) {
        m20 = f;
    } else if (n2 == 1) {
        m21 = f;
    } else {
        m22 = f;
    }
}

void Matrix3f::mul(Matrix3f matrix3f) {
    float  f = m00 * matrix3f.m00 + m01 * matrix3f.m10 + m02 * matrix3f.m20;
    float f2 = m00 * matrix3f.m01 + m01 * matrix3f.m11 + m02 * matrix3f.m21;
    float f3 = m00 * matrix3f.m02 + m01 * matrix3f.m12 + m02 * matrix3f.m22;
    float f4 = m10 * matrix3f.m00 + m11 * matrix3f.m10 + m12 * matrix3f.m20;
    float f5 = m10 * matrix3f.m01 + m11 * matrix3f.m11 + m12 * matrix3f.m21;
    float f6 = m10 * matrix3f.m02 + m11 * matrix3f.m12 + m12 * matrix3f.m22;
    float f7 = m20 * matrix3f.m00 + m21 * matrix3f.m10 + m22 * matrix3f.m20;
    float f8 = m20 * matrix3f.m01 + m21 * matrix3f.m11 + m22 * matrix3f.m21;
    float f9 = m20 * matrix3f.m02 + m21 * matrix3f.m12 + m22 * matrix3f.m22;
    m00 = f;
    m01 = f2;
    m02 = f3;
    m10 = f4;
    m11 = f5;
    m12 = f6;
    m20 = f7;
    m21 = f8;
    m22 = f9;
}

void Matrix3f::mul(Quaternion quaternion) {
    mul(Matrix3f(quaternion));
}

void Matrix3f::mul(float f) {
    m00 *= f;
    m01 *= f;
    m02 *= f;
    m10 *= f;
    m11 *= f;
    m12 *= f;
    m20 *= f;
    m21 *= f;
    m22 *= f;
}

void Matrix3f::add(Matrix3f matrix3f) {
    m00 += matrix3f.m00;
    m01 += matrix3f.m01;
    m02 += matrix3f.m02;
    m10 += matrix3f.m10;
    m11 += matrix3f.m11;
    m12 += matrix3f.m12;
    m20 += matrix3f.m20;
    m21 += matrix3f.m21;
    m22 += matrix3f.m22;
}

void Matrix3f::sub(Matrix3f matrix3f) {
    m00 -= matrix3f.m00;
    m01 -= matrix3f.m01;
    m02 -= matrix3f.m02;
    m10 -= matrix3f.m10;
    m11 -= matrix3f.m11;
    m12 -= matrix3f.m12;
    m20 -= matrix3f.m20;
    m21 -= matrix3f.m21;
    m22 -= matrix3f.m22;
}

float Matrix3f::trace() {
    return m00 + m11 + m22;
}

Matrix3f Matrix3f::copy() {
    return Matrix3f(*this);
}