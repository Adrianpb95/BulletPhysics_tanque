/*
 * SHADER PROGRAM
 * Copyright © 2014+ Ángel Rodríguez Ballesteros
 *
 * Distributed under the Boost Software License, version  1.0
 * See documents/LICENSE.TXT or www.boost.org/LICENSE_1_0.txt
 *
 * angel.rodriguez@esne.edu
 */

#ifndef OPENGL_TOOLKIT_SHADER_PROGRAM_HEADER
#define OPENGL_TOOLKIT_SHADER_PROGRAM_HEADER

    #include <map>
    #include <string>
    #include <cassert>
    #include <Math.hpp>
    #include <Shader.hpp>

    namespace glt
    {

        class Shader_Program
        {
        private:

            typedef std::map< std::string, GLint > Uniform_Map;

        private:

            static const Shader_Program * active_shader_program;
            static unsigned int           instance_count;

        public:

            static const Shader_Program * get_active_shader_program ()
            {
                return active_shader_program;
            }

            static void disable ()
            {
                glUseProgram (0);
            }

        private:

            unsigned    instance_id;
            GLuint      program_object_id;
            bool        link_completed;
            std::string log_string;

        public:

            Shader_Program()
            {
                instance_id       = instance_count++;
                program_object_id = glCreateProgram ();
                link_completed    = false;

                assert(program_object_id != 0);
            }

           ~Shader_Program()
            {
                glDeleteProgram (program_object_id);

                program_object_id = 0;
            }

        private:

            Shader_Program(const Shader_Program & )
            {
            }

        public:

            unsigned id () const
            {
                return instance_id;
            }

            bool is_usable () const
            {
                return (link_completed);
            }

        public:

            void attach (const Shader & shader)
            {
                glAttachShader (program_object_id, shader);
            }

            void detach (const Shader & shader)
            {
                glDetachShader (program_object_id, shader);
            }

        public:

            bool link ();

            void use () const
            {
                assert(is_usable ());

                if (this != active_shader_program)
                {
                    glUseProgram (program_object_id);

                    active_shader_program = this;
                }
            }

        public:

            GLint get_uniform_id (const char * identifier) const
            {
                assert (is_usable ());

                GLint   uniform_id  = glGetUniformLocation (program_object_id, identifier);

                assert (uniform_id != -1);

                return (uniform_id);
            }

            void set_uniform_value (GLint uniform_id, const GLint    & value     ) const { glUniform1i  (uniform_id, value); }
            void set_uniform_value (GLint uniform_id, const GLuint   & value     ) const { glUniform1ui (uniform_id, value); }
            void set_uniform_value (GLint uniform_id, const float    & value     ) const { glUniform1f  (uniform_id, value); }
            void set_uniform_value (GLint uniform_id, const float   (& vector)[2]) const { glUniform2f  (uniform_id, vector[0], vector[1]); }
            void set_uniform_value (GLint uniform_id, const float   (& vector)[3]) const { glUniform3f  (uniform_id, vector[0], vector[1], vector[2]); }
            void set_uniform_value (GLint uniform_id, const float   (& vector)[4]) const { glUniform4f  (uniform_id, vector[0], vector[1], vector[2], vector[3]); }
            void set_uniform_value (GLint uniform_id, const Vector2  & vector    ) const { glUniform2f  (uniform_id, vector[0], vector[1]); }
            void set_uniform_value (GLint uniform_id, const Vector3  & vector    ) const { glUniform3f  (uniform_id, vector[0], vector[1], vector[2]); }
            void set_uniform_value (GLint uniform_id, const Vector4  & vector    ) const { glUniform4f  (uniform_id, vector[0], vector[1], vector[2], vector[3]); }
            void set_uniform_value (GLint uniform_id, const Matrix22 & matrix    ) const { glUniformMatrix2fv (uniform_id, 1, GL_FALSE, get_values (matrix)); }
            void set_uniform_value (GLint uniform_id, const Matrix33 & matrix    ) const { glUniformMatrix3fv (uniform_id, 1, GL_FALSE, get_values (matrix)); }
            void set_uniform_value (GLint uniform_id, const Matrix44 & matrix    ) const { glUniformMatrix4fv (uniform_id, 1, GL_FALSE, get_values (matrix)); }

        public:

            GLint get_vertex_attribute_id (const char * identifier) const
            {
                assert (is_usable ());

                GLint   attribute_id  = glGetAttribLocation (program_object_id, identifier);

                assert (attribute_id != -1);

                return (attribute_id);
            }

            void set_vertex_attribute (GLint attribute_id, const float   & value ) { glVertexAttrib1f  (attribute_id,             value  ); }
            void set_vertex_attribute (GLint attribute_id, const Vector2 & vector) { glVertexAttrib2fv (attribute_id, get_values (vector)); }
            void set_vertex_attribute (GLint attribute_id, const Vector3 & vector) { glVertexAttrib3fv (attribute_id, get_values (vector)); }
            void set_vertex_attribute (GLint attribute_id, const Vector4 & vector) { glVertexAttrib4fv (attribute_id, get_values (vector)); }

        public:

            const std::string & log () const
            {
                return (log_string);
            }

        };

    }

#endif
