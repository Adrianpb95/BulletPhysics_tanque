/*
 * MESH SET
 * Copyright © 2016+ Ángel Rodríguez Ballesteros
 *
 * Distributed under the Boost Software License, version  1.0
 * See documents/LICENSE.TXT or www.boost.org/LICENSE_1_0.txt
 *
 * angel.rodriguez@esne.edu
 */

#ifndef OPENGL_TOOLKIT_MESH_SET_HEADER
#define OPENGL_TOOLKIT_MESH_SET_HEADER

    #include <list>
    #include <memory>
    #include <Mesh.hpp>

    namespace glt
    {

        class Mesh_Set : public Drawable
        {
        private:

            typedef std::list< std::shared_ptr< Mesh > > Mesh_List;

        private:

            Mesh_List mesh_list;

        public:

            void add_mesh (const std::shared_ptr< Mesh > & mesh)
            {
                mesh_list.push_back (mesh);
            }

        public:

            virtual void draw ()
            {
                for (auto & mesh : mesh_list)
                {
                    mesh->draw ();
                }
            }

        };

    }

#endif
