#include <src/com/mojang/math/Vector3f.h>
#include <src/com/mojang/math/Quaternion.h>
#include <src/com/mojang/math/Constants.h>
#include <src/net/minecraft/util/Math.h>

    Vector3f::Vector3f(float f, float f2, float f3) {
        x = f;
        y = f2;
        z = f3;
    }

    Vector3f::Vector3f(Vector4f vector4f) {
        x = vector4f.x;
        y = vector4f.y;
        z = vector4f.z;
    }

    //Vector3f(Vec3 vec3) {
    //    this((float)vec3.x, (float)vec3.y, (float)vec3.z);
    //}

    bool Vector3f::equals(Vector3f vector3f) {
        if (vector3f.x != x) {
            return false;
        }
        if (vector3f.y != y) {
            return false;
        }
        return vector3f.z == z;
    }

    int Vector3f::hashCode() {
        int n = *((int*)&x);
        n = 31 * n + *((int*)&y);
        n = 31 * n + *((int*)&z);
        return n;
    }

    void Vector3f::mul(float f) {
        x *= f;
        y *= f;
        z *= f;
    }

    void Vector3f::mul(float f, float f2, float f3) {
        x *= f;
        y *= f2;
        z *= f3;
    }

    void Vector3f::clamp(Vector3f vector3f, Vector3f vector3f2) {
        x = Clamp(x, vector3f.x, vector3f2.x);
        y = Clamp(y, vector3f.x, vector3f2.y);
        z = Clamp(z, vector3f.z, vector3f2.z);
    }

    void Vector3f::Vector3f::clamp(float f, float f2) {
        x = Clamp(x, f, f2);
        y = Clamp(y, f, f2);
        z = Clamp(z, f, f2);
    }

    void Vector3f::set(float f, float f2, float f3) {
        x = f;
        y = f2;
        z = f3;
    }

    void Vector3f::load(Vector3f vector3f) {
        x = vector3f.x;
        y = vector3f.y;
        z = vector3f.z;
    }

    void Vector3f::add(float f, float f2, float f3) {
        x += f;
        y += f2;
        z += f3;
    }

    void Vector3f::add(Vector3f vector3f) {
        x += vector3f.x;
        y += vector3f.y;
        z += vector3f.z;
    }

    void Vector3f::sub(Vector3f vector3f) {
        x -= vector3f.x;
        y -= vector3f.y;
        z -= vector3f.z;
    }

    float Vector3f::dot(Vector3f vector3f) {
        return x * vector3f.x + y * vector3f.y + z * vector3f.z;
    }

    bool Vector3f::normalize() {
        float f = x * x + y * y + z * z;
        if ((double)f < 1.0E-5) {
            return false;
        }
        float f2 = fastInvSqrt(f);
        x *= f2;
        y *= f2;
        z *= f2;
        return true;
    }

    void Vector3f::cross(Vector3f vector3f) {
        float f =  x;
        float f2 = y;
        float f3 = z;
        float f4 = vector3f.x;
        float f5 = vector3f.y;
        float f6 = vector3f.z;
        x = f2 * f6 - f3 * f5;
        y = f3 * f4 - f * f6;
        z = f * f5 - f2 * f4;
    }

    //void transform(Matrix3f matrix3f) {
    //    float f = x;
    //    float f2 = y;
    //    float f3 = z;
    //    x = matrix3f.m00 * f + matrix3f.m01 * f2 + matrix3f.m02 * f3;
    //    y = matrix3f.m10 * f + matrix3f.m11 * f2 + matrix3f.m12 * f3;
    //    z = matrix3f.m20 * f + matrix3f.m21 * f2 + matrix3f.m22 * f3;
    //}

    void Vector3f::transform(Quaternion quaternion) {
        Quaternion quaternion2 = Quaternion(quaternion);
        quaternion2.mul(Quaternion(x, y, z, 0.0f));
        Quaternion quaternion3 = Quaternion(quaternion);
        quaternion3.conj();
        quaternion2.mul(quaternion3);
        set(quaternion2.i, quaternion2.j, quaternion2.k);
    }

    void Vector3f::lerp(Vector3f vector3f, float f) {
        float f2 = 1.0f - f;
        x = x * f2 + vector3f.x * f;
        y = y * f2 + vector3f.y * f;
        z = z * f2 + vector3f.z * f;
    }

    Quaternion Vector3f::rotation(float f) {
        return Quaternion(*this, f, false);
    }

    Quaternion Vector3f::rotationDegrees(float f) {
        return Quaternion(*this, f, true);
    }

    Vector3f Vector3f::copy() {
        return Vector3f(x, y, z);
    }