/*
 * VERTEX SHADER
 * Copyright © 2014+ Ángel Rodríguez Ballesteros
 *
 * Distributed under the Boost Software License, version  1.0
 * See documents/LICENSE.TXT or www.boost.org/LICENSE_1_0.txt
 *
 * angel.rodriguez@esne.edu
 */

#ifndef OPENGL_TOOLKIT_VERTEX_SHADER_HEADER
#define OPENGL_TOOLKIT_VERTEX_SHADER_HEADER

    #include <Shader.hpp>

    namespace glt
    {

        class Vertex_Shader : public Shader
        {
        public:

            Vertex_Shader(const Source_Code & source_code)
            :
                Shader(source_code, GL_VERTEX_SHADER)
            {
            }

        };

    }

#endif
