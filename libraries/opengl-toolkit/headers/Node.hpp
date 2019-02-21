/*
 * NODE
 * Copyright © 2016+ Ángel Rodríguez Ballesteros
 *
 * Distributed under the Boost Software License, version  1.0
 * See documents/LICENSE.TXT or www.boost.org/LICENSE_1_0.txt
 *
 * angel.rodriguez@esne.edu
 */

#ifndef OPENGL_TOOLKIT_NODE_HEADER
#define OPENGL_TOOLKIT_NODE_HEADER

    #include <cassert>
    #include <Math.hpp>
    #include <Material.hpp>

    namespace glt
    {

        class Render_Node;

        class Node
        {
        private:

            typedef Matrix44 Transformation;

        protected:

            Node         * parent;
            Render_Node  * render_node;

            Transformation local_scale;
            Transformation local_anchor;
            Transformation transformation;

            bool           visible;

        protected:

            Node()
            {
                parent      = nullptr;
                render_node = nullptr;
                visible     = true;
            }

            virtual ~Node() = default;

        public:

            void set_parent (Node * new_parent)
            {
                parent = new_parent;
            }

            void set_renderer (Render_Node * renderer)
            {
                assert(render_node == nullptr);                    // Sólo puede tener un parent...

                render_node = renderer;
            }

            Render_Node * get_render_node ()
            {
                return render_node;
            }

            void set_visible (bool state)
            {
                visible = state;
            }

            bool is_visible () const
            {
                return visible;
            }

            bool is_not_visible () const
            {
                return visible == false;
            }

        public:

            void set_transformation (const Transformation & new_transformation)
            {
                transformation = new_transformation;
            }

            const Transformation & get_transformation () const
            {
                return transformation;
            }

            Transformation get_total_transformation () const
            {
                if (parent)
                {
                    return parent->get_total_transformation () * transformation;
                }
                else
                    return transformation;
            }

            Transformation get_inverse_transformation () const
            {
                return glt::inverse (transformation);
            }

            Transformation get_inverse_total_transformation () const
            {
                return glt::inverse (get_total_transformation ());
            }

            void reset_transformation ()
            {
                transformation = local_scale * local_anchor;
            }

            void reset_transformation (float new_scale)
            {
                local_scale    = glt::scale (Matrix44(), new_scale);
                transformation = local_scale * local_anchor;
            }

            void reset_transformation (float new_scale, const Vector3 & new_anchor)
            {
                local_scale    = glt::scale     (Matrix44(), new_scale );
                local_anchor   = glt::translate (Matrix44(), new_anchor);
                transformation = local_scale * local_anchor;
            }

            void translate (const Vector3 & displacement)
            {
                transformation = glt::translate (transformation, displacement);
            }

            void scale (float scale)
            {
                transformation = glt::scale (transformation, scale);
            }

            void scale (float scale_x, float scale_y, float scale_z)
            {
                transformation = glt::scale (transformation, scale_x, scale_y, scale_z);
            }

            void rotate_around_x (float angle)
            {
                transformation = glt::rotate_around_x (transformation, angle);
            }

            void rotate_around_y (float angle)
            {
                transformation = glt::rotate_around_y (transformation, angle);
            }

            void rotate_around_z (float angle)
            {
                transformation = glt::rotate_around_z (transformation, angle);
            }

        public:

            virtual bool changes_shaders () const
            {
                return false;
            }

            virtual void shader_changed (const Shader_Program & )
            {
            }

        };

    }

#endif
