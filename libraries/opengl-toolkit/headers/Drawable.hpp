/*
 * DRAWABLE
 * Copyright © 2016+ Ángel Rodríguez Ballesteros
 *
 * Distributed under the Boost Software License, version  1.0
 * See documents/LICENSE.TXT or www.boost.org/LICENSE_1_0.txt
 *
 * angel.rodriguez@esne.edu
 */

#ifndef OPENGL_TOOLKIT_DRAWABLE_HEADER
#define OPENGL_TOOLKIT_DRAWABLE_HEADER

    namespace glt
    {

        class Drawable
        {
        public:

            virtual ~Drawable () = default;
            virtual void draw () = 0;

        };

    }

#endif
