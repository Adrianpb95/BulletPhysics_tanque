/*
 * VERTEX BUFFER OBJECT
 * Copyright © 2016+ Ángel Rodríguez Ballesteros
 *
 * Distributed under the Boost Software License, version  1.0
 * See documents/LICENSE.TXT or www.boost.org/LICENSE_1_0.txt
 *
 * angel.rodriguez@esne.edu
 */

#ifndef OPENGL_TOOLKIT_VERTEX_BUFFER_OBJECT_HEADER
#define OPENGL_TOOLKIT_VERTEX_BUFFER_OBJECT_HEADER

    #include <cassert>
    #include <OpenGL.hpp>

    namespace glt
    {

        class Vertex_Buffer_Object
        {
        public:

            enum Target
            {
                ARRAY_BUFFER         = GL_ARRAY_BUFFER,
                ELEMENT_ARRAY_BUFFER = GL_ELEMENT_ARRAY_BUFFER
            };

        private:

            GLuint vbo_id;
            GLenum target;
            GLenum element_type;
            GLenum error;

        public:

            // EL PARÁMETRO SIZE DE LOS CONSTRUCTORES ESTÁ EN BYTES, PERO POSIBLEMENTE FUESE MÁS CONVENIENTE QUE INDICASE NÚMERO DE ELEMENTOS:

            Vertex_Buffer_Object(const GLbyte   * data, size_t size, Target target = ARRAY_BUFFER) : element_type(GL_BYTE          ), target(GLenum(target)) { create (data, size); }
            Vertex_Buffer_Object(const GLubyte  * data, size_t size, Target target = ARRAY_BUFFER) : element_type(GL_UNSIGNED_BYTE ), target(GLenum(target)) { create (data, size); }
            Vertex_Buffer_Object(const GLshort  * data, size_t size, Target target = ARRAY_BUFFER) : element_type(GL_SHORT         ), target(GLenum(target)) { create (data, size); }
            Vertex_Buffer_Object(const GLushort * data, size_t size, Target target = ARRAY_BUFFER) : element_type(GL_UNSIGNED_SHORT), target(GLenum(target)) { create (data, size); }
            Vertex_Buffer_Object(const GLint    * data, size_t size, Target target = ARRAY_BUFFER) : element_type(GL_INT           ), target(GLenum(target)) { create (data, size); }
            Vertex_Buffer_Object(const GLuint   * data, size_t size, Target target = ARRAY_BUFFER) : element_type(GL_UNSIGNED_INT  ), target(GLenum(target)) { create (data, size); }
            Vertex_Buffer_Object(const GLfloat  * data, size_t size, Target target = ARRAY_BUFFER) : element_type(GL_FLOAT         ), target(GLenum(target)) { create (data, size); }

           ~Vertex_Buffer_Object()
            {
                glDeleteBuffers (1, &vbo_id);
            }

        private:

            Vertex_Buffer_Object(const Vertex_Buffer_Object & );

        public:

            bool is_ok () const
            {
                return error == GL_NO_ERROR;
            }

            GLenum get_error () const
            {
                return error;
            }

            GLenum get_element_type () const
            {
                return element_type;
            }

        public:

            void bind () const
            {
                glBindBuffer (target, vbo_id);
            }

            void unbind () const
            {
                glBindBuffer (target, 0);
            }

        private:

            void create (const void * data, size_t size);

        };

    }

#endif
