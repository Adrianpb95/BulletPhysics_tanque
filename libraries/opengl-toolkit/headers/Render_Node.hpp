/*
 * RENDER NODE
 * Copyright © 2016+ Ángel Rodríguez Ballesteros
 *
 * Distributed under the Boost Software License, version  1.0
 * See documents/LICENSE.TXT or www.boost.org/LICENSE_1_0.txt
 *
 * angel.rodriguez@esne.edu
 */

#ifndef OPENGL_TOOLKIT_RENDER_NODE_HEADER
#define OPENGL_TOOLKIT_RENDER_NODE_HEADER

    #pragma warning(disable: 4503)          // Deshabilita un warning que ocurre en la implementación
                                            // de Microsoft de la librería estándar
    #include <map>
    #include <list>
    #include <memory>
    #include <string>
    #include <Node.hpp>
    #include <Camera.hpp>
    #include <Drawable.hpp>
    #include <Material.hpp>

    namespace glt
    {

        class Render_Node
        {
        private:

            typedef std::list< Drawable *                                 > Drawables;
            typedef std::map < Node * ,           Drawables               > Drawables_By_Object;
            typedef std::map < Material * ,       Drawables_By_Object     > Drawables_By_Material;
            typedef std::map < Shader_Program * , Drawables_By_Material   > Drawables_By_Shader;
            typedef std::map < std::string,       std::shared_ptr< Node > > Node_Map;
            typedef std::list< Node *                                     > Node_List;

        private:

            static const size_t max_number_of_lights = 3;

        private:

            Node_Map            nodes;                              ///< Mapa de todos los objetos de la escena.
            Drawables_By_Shader drawable_list;                      ///< Lista estructurada de drawables que hay que renderizar.
            Node_List           shader_update_list;                 ///< Lista de scene objects que hay que avisar cuando se cambia de shader.

            Camera            * active_camera;                      ///< Puntero a la cámara activa. Debe haber una para poder hacer un render.
            GLuint              number_of_lights;                   ///< Contador de luces presentes en la escena. Se utiliza para asignar un índice a cada una.

        public:

            Render_Node()
            {
                active_camera    = nullptr;
                number_of_lights = 0;
            }

        public:

            bool add (const std::string & name, std::shared_ptr< Node > node);

            Node * get (const std::string & name);

            bool set_active_camera (const std::string & name);

            Camera * get_active_camera ()
            {
                return active_camera;
            }

        public:

            bool render ();

        public:

            Node * operator [] (const std::string & name)
            {
                return get (name);
            }

        };

    }

#endif
