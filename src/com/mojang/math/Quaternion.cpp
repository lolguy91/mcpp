#include <src/com/mojang/math/Quaternion.h>
#include <src/com/mojang/math/Constants.h>
#include <src/net/minecraft/util/Math.h>
#include <math.h>
#include <string>
#include <iostream>


Quaternion::Quaternion(float f, float f2, float f3, float f4) {
        i = f;
        j = f2;
        k = f3;
        r = f4;
}

Quaternion::Quaternion(Vector3f vector3f, float f, bool bl) {
    if (bl) {
        f *= (float)PI / 180;
    }
    float f2 = sin(f / 2.0f);
    i = vector3f.x * f2;
    j = vector3f.y * f2;
    k = vector3f.z * f2;
    r = cos(f / 2.0f);
}
Quaternion::Quaternion(float f, float f2, float f3, bool bl) {
    if (bl) {
        f *= (float)PI / 180;
        f2 *= (float)PI / 180;
        f3 *= (float)PI / 180;
    }
    float f4 = sin(0.5f * f);
    float f5 = cos(0.5f * f);
    float f6 = sin(0.5f * f2);
    float f7 = cos(0.5f * f2);
    float f8 = sin(0.5f * f3);
    float f9 = cos(0.5f * f3);
    i = f4 * f7 * f9 + f5 * f6 * f8;
    j = f5 * f6 * f9 - f4 * f7 * f8;
    k = f4 * f6 * f9 + f5 * f7 * f8;
    r = f5 * f7 * f9 - f4 * f6 * f8;
}
//public static Quaternion fromXYZDegrees(Vector3f vector3f) {
//    return Quaternion.fromXYZ((float)Math.toRadians(vector3f.x()), (float)Math.toRadians(vector3f.y()), (float)Math.toRadians(vector3f.z()));
//}

//public static Quaternion fromXYZ(Vector3f vector3f) {
//    return Quaternion.fromXYZ(vector3f.x(), vector3f.y(), vector3f.z());
//}
Quaternion Quaternion::fromXYZ(float f, float f2, float f3) {
    Quaternion quaternion = Quaternion(0.0f, 0.0f, 0.0f, 1.0f);
    quaternion.mul(Quaternion((float)sin(f / 2.0f), 0.0f, 0.0f, (float)cos(f / 2.0f)));
    quaternion.mul(Quaternion(0.0f, (float)sin(f2 / 2.0f), 0.0f, (float)cos(f2 / 2.0f)));
    quaternion.mul(Quaternion(0.0f, 0.0f, (float)sin(f3 / 2.0f), (float)cos(f3 / 2.0f)));
    return quaternion;
}
//public Vector3f toXYZ() {
//    float f = this.r() * this.r();
//    float f2 = this.i() * this.i();
//    float f3 = this.j() * this.j();
//    float f4 = this.k() * this.k();
//    float f5 = f + f2 + f3 + f4;
//    float f6 = 2.0f * this.r() * this.i() - 2.0f * this.j() * this.k();
//    float f7 = (float)Math.asin(f6 / f5);
//    if (Math.abs(f6) > 0.999f * f5) {
//        return new Vector3f(2.0f * (float)Math.atan2(this.i(), this.r()), f7, 0.0f);
//    }
//    return new Vector3f((float)Math.atan2(2.0f * this.j() * this.k() + 2.0f * this.i() * this.r(), f - f2 - f3 + f4), f7, (float)Math.atan2(2.0f * this.i() * this.j() + 2.0f * this.r() * this.k(), f + f2 - f3 - f4));
//}

//public Vector3f toXYZDegrees() {
//    Vector3f vector3f = this.toXYZ();
//    return new Vector3f((float)Math.toDegrees(vector3f.x()), (float)Math.toDegrees(vector3f.y()), (float)Math.toDegrees(vector3f.z()));
//}
//public Vector3f toYXZ() {
//    float f = this.r() * this.r();
//    float f2 = i * i;
//    float f3 = j * j;
//    float f4 = k * k;
//    float f5 = f + f2 + f3 + f4;
//    float f6 = 2.0f * r * i - 2.0f * j * k;
//    float f7 = (float)asin(f6 / f5);
//    if (abs(f6) > 0.999f * f5) {
//        return Vector3f(f7, 2.0f * (float)atan2(j, r), 0.0f);
//    }
//    return new Vector3f(f7, (float)Math.atan2(2.0f * i * .k + 2.0f * j * r, f - f2 - f3 + f4), (float)Math.atan2(2.0f * this.i() * this.j() + 2.0f * this.r() * this.k(), f - f2 + f3 - f4));
//}

//public Vector3f toYXZDegrees() {
//    Vector3f vector3f = toYXZ();
//    return Vector3f((float)toDegrees(vector3f.x()), (float)toDegrees(vector3f.y()), (float)toDegrees(vector3f.z()));
//}
bool Quaternion::equals(Quaternion quaternion) {
    if (quaternion.i != i) {
        return false;
    }
    if (quaternion.j != j) {
        return false;
    }
    if (quaternion.k != k) {
        return false;
    }
    return quaternion.r == r;
}
int Quaternion::hashCode() {
    int n = *((int*)&i);
    n = 31 * n + *((int*)&j);;
    n = 31 * n + *((int*)&k);;
    n = 31 * n + *((int*)&r);;
    return n;
}
void Quaternion::mul(Quaternion quaternion) {
    float f = i;
    float f2 = j;
    float f3 = k;
    float f4 = r;
    float f5 = quaternion.i;
    float f6 = quaternion.j;
    float f7 = quaternion.k;
    float f8 = quaternion.r;
    i = f4 * f5 + f * f8 + f2 * f7 - f3 * f6;
    j = f4 * f6 - f * f7 + f2 * f8 + f3 * f5;
    k = f4 * f7 + f * f6 - f2 * f5 + f3 * f8;
    r = f4 * f8 - f * f5 - f2 * f6 - f3 * f7;
}

void Quaternion::mul(float f) {
    i *= f;
    j *= f;
    k *= f;
    r *= f;
}
void Quaternion::conj() {
    i = -i;
    j = -j;
    k = -k;
}
void Quaternion::set(float f, float f2, float f3, float f4) {
    i = f;
    j = f2;
    k = f3;
    r = f4;
}

void Quaternion::normalize() {
    float f = i * i + j * j + k * k + r * r;
    if (f > 1.0E-6f) {
        float f2 = fastInvSqrt(f);
        i *= f2;
        j *= f2;
        k *= f2;
        r *= f2;
    } else {
        i = 0.0f;
        j = 0.0f;
        k = 0.0f;
        r = 0.0f;
    }
}

Quaternion Quaternion::copy() {
    return Quaternion(i,j,k,r);
}