/*
 * MATERIAL
 * Copyright © 2016+ Ángel Rodríguez Ballesteros
 *
 * Distributed under the Boost Software License, version  1.0
 * See documents/LICENSE.TXT or www.boost.org/LICENSE_1_0.txt
 *
 * angel.rodriguez@esne.edu
 */

#ifndef OPENGL_TOOLKIT_MATERIAL_HEADER
#define OPENGL_TOOLKIT_MATERIAL_HEADER

    #include <list>
    #include <memory>
    #include <string>
    #include <Math.hpp>
    #include <Shader_Program.hpp>

    namespace glt
    {

        class Material
        {
        public:

            struct Var
            {
                enum class Type
                {
                    BYTE, UBYTE, SHORT, USHORT, INT, UINT, FLOAT, VECTOR2, VECTOR3, VECTOR4
                };

                union Data
                {
                    GLint   gl_int;
                    GLuint  gl_uint;
                    GLfloat gl_float;
                    GLfloat vector2[2];
                    GLfloat vector3[3];
                    GLfloat vector4[4];
                };

                Type type;
                Data data;

            };

            struct Uniform
            {
                GLint location;
                Var   value;
            };

        public:

            static unsigned instance_count;

            static std::shared_ptr< Material > default_material ();

        private:

            std::string                       name;
            unsigned int                      instance_id;
            std::shared_ptr< Shader_Program > shader_program;
            std::list< Uniform >              uniforms;

        public:

            Material(const std::string & name, std::shared_ptr< Shader_Program > & shader_program)
            :
                name(name),
                instance_id(instance_count++),
                shader_program(shader_program)
            {
            }

        public:

            unsigned id () const
            {
                return instance_id;
            }

            const std::string & get_name () const
            {
                return name;
            }

            Shader_Program * get_shader_program () const
            {
                return shader_program.get ();
            }

            bool set (const char * identifier, const GLint     value);
            bool set (const char * identifier, const GLuint    value);
            bool set (const char * identifier, const GLfloat   value);
            bool set (const char * identifier, const Vector2 & value);
            bool set (const char * identifier, const Vector3 & value);
            bool set (const char * identifier, const Vector4 & value);

        private:

            Uniform * allocate_uniform (const char * identifier, Var::Type type);

        public:

            void use ();

        };

    }

#endif
