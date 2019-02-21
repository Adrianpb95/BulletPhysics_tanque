/*
ADRIAN PONCE BALSEIRO
ESNE G4.3 DDVJ
adrianpb95@gmail.com
10 / 06 / 2018
*/

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "Scene.hpp"
#include "Entity.hpp"


void Entity::update()
{
	// Aplica las transformaciones fisicas al modelo grafico
	btTransform physics_transform;

	physics_model->getBody()->getMotionState()->getWorldTransform(physics_transform);

	glm::mat4 graphics_transform;

	physics_transform.getOpenGLMatrix(glm::value_ptr(graphics_transform));

	graphics_model->set_transformation(graphics_transform);
	graphics_model->scale(gscale_x, gscale_y, gscale_z);
}