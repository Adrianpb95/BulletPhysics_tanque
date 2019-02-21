/*
 * MATH
 * Copyright © 2016+ Ángel Rodríguez Ballesteros
 *
 * Distributed under the Boost Software License, version  1.0
 * See documents/LICENSE.TXT or www.boost.org/LICENSE_1_0.txt
 *
 * angel.rodriguez@esne.edu
 */

#ifndef OPENGL_TOOLKIT_MATH_HEADER
#define OPENGL_TOOLKIT_MATH_HEADER

    #include <glm/glm.hpp>
    #include <glm/gtc/type_ptr.hpp>
    #include <glm/gtx/matrix_decompose.hpp>
    #include <glm/gtc/matrix_transform.hpp>

    namespace glt
    {

        typedef glm::vec2 Vector2;
        typedef glm::vec3 Vector3;
        typedef glm::vec4 Vector4;

        typedef glm::quat Quaternion;

        typedef glm::mat2 Matrix22;
        typedef glm::mat3 Matrix33;
        typedef glm::mat4 Matrix44;

        typedef glm::vec2 Point2;
        typedef glm::vec3 Point3;
        typedef glm::vec4 Point4;

        template< class CLASS >
        inline const float * get_values (const CLASS & object)
        {
            return glm::value_ptr(object);
        }

        inline Matrix44 inverse (const Matrix44 & matrix)
        {
            return glm::inverse (matrix);
        }

        inline Matrix44 transpose (const Matrix44 & matrix)
        {
            return glm::transpose (matrix);
        }

        inline Matrix44 translate (const Matrix44 & matrix, const Vector3 & displacement)
        {
            return glm::translate (matrix, displacement);
        }

        inline Matrix44 scale (const Matrix44 & matrix, float scale)
        {
            return glm::scale (matrix, Vector3(scale, scale, scale));
        }

        inline Matrix44 scale (const Matrix44 & matrix, float scale_x, float scale_y, float scale_z)
        {
            return glm::scale (matrix, Vector3(scale_x, scale_y, scale_z));
        }

        inline Matrix44 rotate_around_x (const Matrix44 & matrix, float angle)
        {
            return glm::rotate (matrix, angle, glm::vec3(1.f, 0.f, 0.f));
        }

        inline Matrix44 rotate_around_y (const Matrix44 & matrix, float angle)
        {
            return glm::rotate (matrix, angle, glm::vec3(0.f, 1.f, 0.f));
        }

        inline Matrix44 rotate_around_z (const Matrix44 & matrix, float angle)
        {
            return glm::rotate (matrix, angle, glm::vec3(0.f, 0.f, 1.f));
        }

        inline Matrix44 perspective (float fov, float near, float far, float aspect_ratio)
        {
            return glm::perspective (fov, aspect_ratio, near, far);
        }

        inline Vector2 extract_translation (const Matrix33 & transformation)
        {
            const  Vector3 & translation = transformation[2];
            return Vector2(translation[0], translation[1]);
        }

        inline Vector3 extract_translation (const Matrix44 & transformation)
        {
            const  Vector4 & translation = transformation[3];
            return Vector3(translation[0], translation[1], translation[2]);
        }

        inline Quaternion extract_rotation (const Matrix44 & transformation)
        {
            glm::vec3 scale;
            glm::quat rotation;
            glm::vec3 translation;
            glm::vec3 skew;
            glm::vec4 perspective;

            glm::decompose (transformation, scale, rotation, translation, skew, perspective);

            return rotation;
        }

        inline Matrix44 look_at (const Point3 & from, const Point3 & to)
        {
            return glm::lookAt (from, to, Vector3(0.f, 1.f, 0.f));
        }

    }

#endif
