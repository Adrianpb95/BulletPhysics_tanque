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
#include "Door.hpp"

Door::Door(Scene * scene) : Entity(model_path, physics_model, gscale_x, gscale_y, gscale_z)
{
	shared_ptr< Shape > muro_shape(new Box_Shape(2.0f, 15.0f, 10.0f));
	shared_ptr< Rigid_Body > muro_body(new Dynamic_Rigid_Body(muro_shape, 0.f, 10.f, -8.f, 1000000.f, btVector3(0.f, 0.f, 0.f)));
	shared_ptr <Entity> muro(new Entity("../../../../assets/caja2.obj", muro_body, 4.f, 30.f, 20.f));
	muro_body->getBody()->setActivationState(DISABLE_DEACTIVATION);

	shared_ptr< Shape > puerta_shape(new Box_Shape(2.0f, 15.0f, 8.0f));
	shared_ptr< Rigid_Body > puerta_body(new Dynamic_Rigid_Body(puerta_shape, 0.f, 10.f, 15.f, 25.f, btVector3(0.f, 0.f, 0.f)));
	shared_ptr <Entity> puerta(new Entity("../../../../assets/caja2.obj", puerta_body, 4.f, 30.f, 16.f));
	puerta_body->getBody()->setActivationState(DISABLE_DEACTIVATION);

	add_constraints(scene, puerta_muro, *puerta_body->getBody(), *muro_body->getBody(), btVector3(0.f, 0.f, -8.f), btVector3(0.f, 0.f, 12.f), btVector3(0.f, 1.f, 0.f), btVector3(0.f, 0.f, 0.f), true);
	
	scene->add("muro", muro);
	scene->add("puerta", puerta);
}