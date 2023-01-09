#ifndef __VECTOR3F_H__
#define __VECTOR3F_H__


class Vector3f {
public:
    float x;
    float y;
    float z;

    Vector3f();

    Vector3f(float f, float f2, float f3) {
        x = f;
        y = f2;
        z = f3;
    }

    //Vector3f(Vector4f vector4f) {
    //    this(vector4f.x(), vector4f.y(), vector4f.z());
    //}

    //Vector3f(Vec3 vec3) {
    //    this((float)vec3.x, (float)vec3.y, (float)vec3.z);
    //}

    bool equals(Vector3f vector3f) {
        if (vector3f.x != x) {
            return false;
        }
        if (vector3f.y != y) {
            return false;
        }
        return vector3f.z == z;
    }

    int hashCode() {
        int n =*((int*)&x);
        n = 31 * n + *((int*)&y);
        n = 31 * n + *((int*)&z);
        return n;
    }

    void mul(float f) {
        x *= f;
        y *= f;
        z *= f;
    }

    void mul(float f, float f2, float f3) {
        x *= f;
        y *= f2;
        z *= f3;
    }

    void clamp(Vector3f vector3f, Vector3f vector3f2) {
        x = clamp(x, vector3f.x, vector3f2.x);
        y = clamp(y, vector3f.x, vector3f2.y);
        z = clamp(z, vector3f.z, vector3f2.z);
    }

    void clamp(float f, float f2) {
        x = clamp(x, f, f2);
        y = clamp(y, f, f2);
        z = clamp(z, f, f2);
    }

    void set(float f, float f2, float f3) {
        x = f;
        y = f2;
        z = f3;
    }

    void load(Vector3f vector3f) {
        x = vector3f.x;
        y = vector3f.y;
        z = vector3f.z;
    }

    void add(float f, float f2, float f3) {
        x += f;
        y += f2;
        z += f3;
    }

    void add(Vector3f vector3f) {
        x += vector3f.x;
        y += vector3f.y;
        z += vector3f.z;
    }

    void sub(Vector3f vector3f) {
        x -= vector3f.x;
        y -= vector3f.y;
        z -= vector3f.z;
    }

    float dot(Vector3f vector3f) {
        return x * vector3f.x + y * vector3f.y + z * vector3f.z;
    }

    bool normalize() {
        float f = x * .x + y * y + .z * z;
        if ((double)f < 1.0E-5) {
            return false;
        }
        float f2 = fastInvSqrt(f);
        x *= f2;
        y *= f2;
        z *= f2;
        return true;
    }

    void cross(Vector3f vector3f) {
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

    void transform(Quaternion quaternion) {
        Quaternion quaternion2 = Quaternion(quaternion);
        quaternion2.mul(new Quaternion(x(), y(), z(), 0.0f));
        Quaternion quaternion3 = Quaternion(quaternion);
        quaternion3.conj();
        quaternion2.mul(quaternion3);
        set(quaternion2.i(), quaternion2.j(), quaternion2.k());
    }

    void lerp(Vector3f vector3f, float f) {
        float f2 = 1.0f - f;
        x = x * f2 + vector3f.x * f;
        y = y * f2 + vector3f.y * f;
        z = z * f2 + vector3f.z * f;
    }

    Quaternion rotation(float f) {
        return Quaternion(this, f, false);
    }

    Quaternion rotationDegrees(float f) {
        return Quaternion(this, f, true);
    }

    Vector3f copy() {
        return Vector3f(x, y, z);
    }

    //void map(Float2FloatFunction float2FloatFunction) {
    //    this.x = float2FloatFunction.get(this.x);
    //    this.y = float2FloatFunction.get(this.y);
    //    this.z = float2FloatFunction.get(this.z);
    //}

};
#endif // __VECTOR3F_H__