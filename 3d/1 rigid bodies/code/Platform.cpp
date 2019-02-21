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
#include "Platform.hpp"

Platform::Platform(Scene * scene) : Entity(model_path, physics_model, gscale_x, gscale_y, gscale_z)
{
	shared_ptr< Shape > platform_shape(new Box_Shape(5.0f, 1.0f, 5.0f));
	shared_ptr< Rigid_Body > platform_body(new Dynamic_Rigid_Body(platform_shape, 30.f, -5.f, 0.f, 10000.f, btVector3(0.f, 0.f, 0.f)));
	shared_ptr <Entity> platform(new Entity("../../../../assets/caja2.obj", platform_body, 10.f, 2.f, 10.f));
	platform_body->getBody()->setLinearFactor(btVector3(1, 0, 0));
	platform_body->getBody()->setAngularFactor(btVector3(0, 0, 0));
	platform->get_graphics_model()->set_visible(false);
	platform_body->getBody()->setActivationState(DISABLE_DEACTIVATION);

	shared_ptr< Shape > platform_shape2(new Box_Shape(5.0f, 1.0f, 5.0f));
	shared_ptr< Rigid_Body > platform_body2(new Dynamic_Rigid_Body(platform_shape2, -20.f, -5.f, 0.f, 10000.f, btVector3(0.f, 0.f, 0.f)));
	shared_ptr <Entity> platform2(new Entity("../../../../assets/caja2.obj", platform_body2, 10.f, 2.f, 10.f));
	platform2->get_graphics_model()->set_visible(false);
	platform_body2->getBody()->setLinearFactor(btVector3(0, 0, 1));
	platform_body2->getBody()->setAngularFactor(btVector3(0, 0, 0));
	platform_body2->getBody()->setActivationState(DISABLE_DEACTIVATION);

	scene->add("platform", platform);
	scene->add("platform2", platform2);

	platform_right = platform;
	platform_left = platform2;
}

void Platform::move_platform()
{
	//Limitacion de movimiento de la plataforma derecha
	if (platform_right->get_physics_model()->getBody()->getWorldTransform().getOrigin().getX() <= 20.5f)
		platform_right->get_physics_model()->getBody()->setLinearVelocity(btVector3(0.f, 0.f, 0.f));

	//Limitacion de movimiento de la plataforma izquierda
	if (platform_left->get_physics_model()->getBody()->getWorldTransform().getOrigin().getZ() >= 15)
		platform_left->get_physics_model()->getBody()->setLinearVelocity(btVector3(0.f, 0.f, -1.f));
	else if (platform_left->get_physics_model()->getBody()->getWorldTransform().getOrigin().getZ() <= -15)
		platform_left->get_physics_model()->getBody()->setLinearVelocity(btVector3(0.f, 0.f, 1.f));
}