/*
 * OPENGL
 * Copyright © 2018+ Ángel Rodríguez Ballesteros
 *
 * Distributed under the Boost Software License, version  1.0
 * See documents/LICENSE.TXT or www.boost.org/LICENSE_1_0.txt
 *
 * angel.rodriguez@esne.edu
 */

#ifndef OPENGL_TOOLKIT_OPENGL_HEADER
#define OPENGL_TOOLKIT_OPENGL_HEADER

    #include <glad/glad.h>

	#undef near
	#undef far

    namespace glt
    {

        bool initialize_opengl_extensions ();

    }

#endif
