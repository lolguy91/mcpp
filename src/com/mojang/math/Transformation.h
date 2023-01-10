#ifndef __TRANSFORMATION_H__
#define __TRANSFORMATION_H__

#include <src/com/mojang/math/Quaternion.h>
#include <src/com/mojang/math/Matrix4f.h>
#include <src/com/mojang/math/Matrix3f.h>
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


    Transformation(Matrix4f matrix4f) {
        matrix = matrix4f;
    }

    Transformation( Vector3f vector3f,  Quaternion quaternion,  Vector3f vector3f2,  Quaternion quaternion2) {
        matrix = compose(vector3f, quaternion, vector3f2, quaternion2);
        translation = vector3f;
        leftRotation = quaternion;
        scale = vector3f2;
        rightRotation = quaternion2;
        decomposed = true;
    }

    static Transformation identity() {
        Matrix4f matrix4f = Matrix4f();
        matrix4f.setIdentity();
        Transformation transformation = Transformation(matrix4f);
        transformation.getLeftRotation();
        return transformation;
    }

    Transformation compose(Transformation transformation) {
        Matrix4f matrix4f = getMatrix();
        matrix4f.multiply(transformation.getMatrix());
        return Transformation(matrix4f);
    }

    
    Transformation inverse() {
        if (equals(identity())) {
            return *this;
        }
        Matrix4f matrix4f = getMatrix();
        if (matrix4f.invert()) {
            return Transformation(matrix4f);
        }
    }

    void ensureDecomposed() {
        if (!decomposed) {
            std::pair<Matrix3f, Vector3f> pair = toAffine(matrix);
            std::tuple<Quaternion, Vector3f, Quaternion> triple = ((Matrix3f)pair.first).svdDecompose();
            translation = pair.second;
            leftRotation = std::get<0>(triple);
            scale = std::get<1>(triple);
            rightRotation = std::get<2>(triple);
            decomposed = true;
        }
    }

    Matrix4f compose( Vector3f vector3f,  Quaternion quaternion,  Vector3f vector3f2,  Quaternion quaternion2) {
        Matrix4f matrix4f = Matrix4f();
        matrix4f.setIdentity();
        matrix4f.multiply(Matrix4f(quaternion));
        matrix4f.multiply(Matrix4f::createScaleMatrix(vector3f2.x, vector3f2.y, vector3f2.z));
        matrix4f.multiply(Matrix4f(quaternion2));
        matrix4f.m03 = vector3f.x;
        matrix4f.m13 = vector3f.y;
        matrix4f.m23 = vector3f.z;
        return matrix4f;
    }

    std::pair<Matrix3f, Vector3f> toAffine(Matrix4f matrix4f) {
        matrix4f.multiply(1.0f / matrix4f.m33);
        Vector3f vector3f = Vector3f(matrix4f.m03, matrix4f.m13, matrix4f.m23);
        Matrix3f matrix3f = Matrix3f(matrix4f);
        return std::pair<Matrix3f, Vector3f>(matrix3f, vector3f);
    }

    Matrix4f getMatrix() {
        return matrix.copy();
    }

    Vector3f getTranslation() {
        ensureDecomposed();
        return translation.copy();
    }

    Quaternion getLeftRotation() {
        ensureDecomposed();
        return leftRotation.copy();
    }

    Vector3f getScale() {
        ensureDecomposed();
        return scale.copy();
    }

    Quaternion getRightRotation() {
        ensureDecomposed();
        return rightRotation.copy();
    }

    bool equals(Transformation transformation) {
        return matrix.equals(transformation.matrix);
    }

    int hashCode() {
        return matrix.hashCode();
    }
};



#endif // __TRANSFORMATION_H__