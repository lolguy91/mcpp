#ifndef __TRANSFORMATION_H__
#define __TRANSFORMATION_H__

#include <utility>
#include <tuple>

class Transformation {
    public:
    Matrix4f matrix;
    bool decomposed;
    Vector3f translation;
    Quaternion leftRotation;
    Vector3f scale;

    Quaternion rightRotation;


    Transformation(Matrix4f matrix4f);
    Transformation( Vector3f vector3f,  Quaternion quaternion,  Vector3f vector3f2,  Quaternion quaternion2);
    static Transformation identity();
    Transformation compose(Transformation transformation);
    Transformation inverse();
    void ensureDecomposed();
    Matrix4f compose( Vector3f vector3f,  Quaternion quaternion,  Vector3f vector3f2,  Quaternion quaternion2);
    std::pair<Matrix3f, Vector3f> toAffine(Matrix4f matrix4f);
    Matrix4f getMatrix();
    Vector3f getTranslation();
    Quaternion getLeftRotation();
    Vector3f getScale();
    Quaternion getRightRotation();
    bool equals(Transformation transformation);
    int hashCode();
};



#endif // __TRANSFORMATION_H__