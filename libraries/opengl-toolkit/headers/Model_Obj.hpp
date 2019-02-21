/*
 * MODEL OBJ
 * Copyright © 2018+ Ángel Rodríguez Ballesteros
 *
 * Distributed under the Boost Software License, version  1.0
 * See documents/LICENSE.TXT or www.boost.org/LICENSE_1_0.txt
 *
 * angel.rodriguez@esne.edu
 */

#ifndef OPENGL_TOOLKIT_MODEL_OBJ_HEADER
#define OPENGL_TOOLKIT_MODEL_OBJ_HEADER

    #include <vector>
    #include <string>
    #include <Model.hpp>

    namespace glt
    {

        class Model_Obj : public Model
        {

            std::string error;

        public:

            Model_Obj(const std::string & obj_file_path);

            bool is_ok ()
            {
                return error.empty ();
            }

            const std::string get_error () const
            {
                return error;
            }

        };

    }

#endif
