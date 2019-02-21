/*
 * VERTEX ARRAY OBJECT
 * Copyright © 2016+ Ángel Rodríguez Ballesteros
 *
 * Distributed under the Boost Software License, version  1.0
 * See documents/LICENSE.TXT or www.boost.org/LICENSE_1_0.txt
 *
 * angel.rodriguez@esne.edu
 */

#ifndef OPENGL_TOOLKIT_VERTEX_ARRAY_OBJECT_HEADER
#define OPENGL_TOOLKIT_VERTEX_ARRAY_OBJECT_HEADER

    #include <list>
    #include <memory>
    #include <cassert>
    #include <OpenGL.hpp>
    #include <initializer_list>
    #include <Shader_Program.hpp>
    #include <Vertex_Buffer_Object.hpp>

    namespace glt
    {

        class Vertex_Array_Object
        {
        public:

            struct Vertex_Attribute_Information
            {
                std::shared_ptr< Vertex_Buffer_Object > vbo;
                GLuint attribute_location;
                GLint  number_of_components;
                GLenum component_type;
            };

        private:

            typedef std::list< std::shared_ptr< Vertex_Buffer_Object > > Vbo_List;

        private:

            GLuint   vao_id;
            Vbo_List vbo_list;
            GLenum   error;

        public:

            Vertex_Array_Object
            (
                const std::initializer_list< Vertex_Attribute_Information > & vertex_attribute_information_list,
                const std::shared_ptr< Vertex_Buffer_Object > & indices_vbo = std::shared_ptr< Vertex_Buffer_Object >()
            );

           ~Vertex_Array_Object()
            {
                glDeleteVertexArrays (1, &vao_id);
            }

        private:

            Vertex_Array_Object(const Vertex_Array_Object & );

        public:

            bool is_ok () const
            {
                return error == GL_NO_ERROR;
            }

            GLenum get_error () const
            {
                return error;
            }

        public:

            void bind () const
            {
                glBindVertexArray (vao_id);
            }

            void unbind () const
            {
                glBindVertexArray (0);
            }

        };

    }

#endif
