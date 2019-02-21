/*
 * LIGHT
 * Copyright © 2016+ Ángel Rodríguez Ballesteros
 *
 * Distributed under the Boost Software License, version  1.0
 * See documents/LICENSE.TXT or www.boost.org/LICENSE_1_0.txt
 *
 * angel.rodriguez@esne.edu
 */

#ifndef OPENGL_TOOLKIT_LIGHT_HEADER
#define OPENGL_TOOLKIT_LIGHT_HEADER

    #include <Node.hpp>

    namespace glt
    {

        class Light : public Node
        {
        private:

            GLuint  index;
            Vector3 color;
            float   intensity;

        public:

            Light()
            {
                index     = -1;
                color     = Vector3(1.f, 1.f, 1.f);
                intensity = 1.f;
            }

        public:

            void set_light_index (GLuint light_index)
            {
                index = light_index;
            }

            void set_color (const Vector3 & new_color)
            {
                color = new_color;
            }

            void set_intensity (float new_intensity)
            {
                intensity = new_intensity;
            }

        public:

            virtual bool changes_shaders () const
            {
                return index >= 0;
            }

            virtual void shader_changed (const Shader_Program & );

        };

    }

#endif
