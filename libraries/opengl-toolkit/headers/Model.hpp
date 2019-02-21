/*
 * MODEL
 * Copyright © 2016+ Ángel Rodríguez Ballesteros
 *
 * Distributed under the Boost Software License, version  1.0
 * See documents/LICENSE.TXT or www.boost.org/LICENSE_1_0.txt
 *
 * angel.rodriguez@esne.edu
 */

#ifndef OPENGL_TOOLKIT_MODEL_HEADER
#define OPENGL_TOOLKIT_MODEL_HEADER

    #include <list>
    #include <memory>
    #include <Node.hpp>
    #include <Drawable.hpp>
    #include <Material.hpp>

    namespace glt
    {

        class Model : public Node
        {
        public:

            struct Piece
            {
                std::shared_ptr< Drawable > drawable;
                std::shared_ptr< Material > material;
            };

            typedef std::list< Piece > Piece_List;

        private:

            Piece_List pieces;

        public:

            void add (const std::shared_ptr< Drawable > & drawable, const std::shared_ptr< Material > & material)
            {
                pieces.push_back ({ drawable, material });
            }

            const Piece_List & get_pieces () const
            {
                return pieces;
            }

        };

    }

#endif
