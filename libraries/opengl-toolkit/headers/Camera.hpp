/*
 * CAMERA
 * Copyright © 2016+ Ángel Rodríguez Ballesteros
 *
 * Distributed under the Boost Software License, version  1.0
 * See documents/LICENSE.TXT or www.boost.org/LICENSE_1_0.txt
 *
 * angel.rodriguez@esne.edu
 */

#ifndef OPENGL_TOOLKIT_CAMERA_HEADER
#define OPENGL_TOOLKIT_CAMERA_HEADER

    #include <Node.hpp>

    namespace glt
    {

        class Camera : public Node
        {
        private:

            float    fov;
            float    near;
            float    far;
            float    aspect_ratio;
            Matrix44 projection_matrix;

        public:

            Camera()
            {
            }

            Camera(float fov, float near, float far, float aspect_ratio)
            {
                set (fov, near, far, aspect_ratio);
            }

        public:

            float get_fov () const
            {
                return fov;
            }

            float get_near () const
            {
                return near;
            }

            float get_far () const
            {
                return far;
            }

            float get_aspect_ratio () const
            {
                return aspect_ratio;
            }

            const Matrix44 & get_projection_matrix () const
            {
                return projection_matrix;
            }

        public:

            void set (float new_fov, float new_near, float new_far, float new_aspect_ratio)
            {
                projection_matrix = perspective (fov = new_fov, near = new_near, far = new_far, aspect_ratio = new_aspect_ratio);
            }

            void set_fov (float new_fov)
            {
                projection_matrix = perspective (fov = new_fov, near, far, aspect_ratio);
            }

            void set_near (float new_near)
            {
                projection_matrix = perspective (fov, near = new_near, far, aspect_ratio);
            }

            void set_far (float new_far)
            {
                projection_matrix = perspective (fov, near, far = new_far, aspect_ratio);
            }

            void set_aspect_ratio (float new_aspect_ratio)
            {
                projection_matrix = perspective (fov, near, far, aspect_ratio = new_aspect_ratio);
            }

            void look_at (const Vector3 & where)
            {
                transformation = glt::look_at (extract_translation (transformation), where);
            }

        };

    }

#endif
