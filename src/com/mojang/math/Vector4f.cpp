    
    #include <src/com/mojang/math/Vector3f.h>
    #include <src/com/mojang/math/Quaternion.h>
    #include <src/com/mojang/math/Vector4f.h>
    #include <src/com/mojang/math/Matrix4f.h>
    #include <src/com/mojang/math/Constants.h>
    #include <src/net/minecraft/util/Math.h>

    Vector4f::Vector4f(float f, float f2, float f3, float f4) {
        x = f;
        y = f2;
        z = f3;
        w = f4;
    }

    Vector4f::Vector4f(Vector3f const& vector3f) {
        x = vector3f.x;
        y = vector3f.y;
        z = vector3f.z;
        w = 1.0f;
    }

    bool Vector4f::equals(Vector4f vector4f) {
        if (vector4f.x != x) {
            return false;
        }
        if (vector4f.y != y) {
            return false;
        }
        if (vector4f.z != z) {
            return false;
        }
        return vector4f.w == w;
    }

    int Vector4f::hashCode() {
        int n = *((int*)&x);
        n = 31 * n + *((int*)&y);
        n = 31 * n + *((int*)&z);
        n = 31 * n + *((int*)&w);
        return n;
    }

    void Vector4f::mul(float f) {
        x *= f;
        y *= f;
        z *= f;
        w *= f;
    }

    void Vector4f::mul(Vector3f vector3f) {
        x *= vector3f.x;
        y *= vector3f.y;
        z *= vector3f.z;
    }

    void Vector4f::set(float f, float f2, float f3, float f4) {
        x = f;
        y = f2;
        z = f3;
        w = f4;
    }

    void Vector4f::add(float f, float f2, float f3, float f4) {
        x += f;
        y += f2;
        z += f3;
        w += f4;
    }

    float Vector4f::dot(Vector4f vector4f) {
        return x * vector4f.x + y * vector4f.y + z * vector4f.z + w * vector4f.w;
    }

    bool Vector4f::normalize() {
        float f = x * x + y * y + z * z + w * w;
        if ((double)f < 1.0E-5) {
            return false;
        }
        float f2 = fastInvSqrt(f);
        x *= f2;
        y *= f2;
        z *= f2;
        w *= f2;
        return true;
    }

    void Vector4f::transform(Matrix4f matrix4f) {
        float f =  x;
        float f2 = y;
        float f3 = z;
        float f4 = w;
        x = matrix4f.m00 * f + matrix4f.m01 * f2 + matrix4f.m02 * f3 + matrix4f.m03 * f4;
        y = matrix4f.m10 * f + matrix4f.m11 * f2 + matrix4f.m12 * f3 + matrix4f.m13 * f4;
        z = matrix4f.m20 * f + matrix4f.m21 * f2 + matrix4f.m22 * f3 + matrix4f.m23 * f4;
        w = matrix4f.m30 * f + matrix4f.m31 * f2 + matrix4f.m32 * f3 + matrix4f.m33 * f4;
    }

    void Vector4f::transform(Quaternion quaternion) {
        Quaternion quaternion2 = Quaternion(quaternion);
        quaternion2.mul(Quaternion(x, y, z, 0.0f));
        Quaternion quaternion3 = Quaternion(quaternion);
        quaternion3.conj();
        quaternion2.mul(quaternion3);
        set(quaternion2.i, quaternion2.j, quaternion2.k, w);
    }

    void Vector4f::perspectiveDivide() {
        x /= w;
        y /= w;
        z /= w;
        w = 1.0f;
    }

    void Vector4f::lerp(Vector4f vector4f, float f) {
        float f2 = 1.0f - f;
        x = x * f2 + vector4f.x * f;
        y = y * f2 + vector4f.y * f;
        z = z * f2 + vector4f.z * f;
        w = w * f2 + vector4f.w * f;
    }
    Vector4f::Vector4f()
    {
        
    }
    