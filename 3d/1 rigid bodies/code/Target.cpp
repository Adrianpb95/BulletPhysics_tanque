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
#include "Target.hpp"

Target::Target(Scene * scene) : Entity(model_path, physics_model, gscale_x, gscale_y, gscale_z)
{
	shared_ptr< Shape > target_shape(new Box_Shape(2.0f, 8.0f, 2.0f));
	shared_ptr< Rigid_Body > target_body(new  Dynamic_Rigid_Body(target_shape, -40.f, 6.f, -15.f, 1.0f, btVector3(0.f, 0.f, 0.f)));
	shared_ptr <Entity> target(new Entity("../../../../assets/caja2.obj", target_body, 4.f, 16.f, 4.f));

	shared_ptr< Shape > target_shape2(new Box_Shape(2.0f, 8.0f, 2.0f));
	shared_ptr< Rigid_Body > target_body2(new Dynamic_Rigid_Body(target_shape2, -40.f, 6.f, -10.f, 1.0f, btVector3(0.f, 0.f, 0.f)));
	shared_ptr <Entity> target2(new Entity("../../../../assets/caja2.obj", target_body2, 4.f, 16.f, 4.f));

	shared_ptr< Shape > target_shape3(new Box_Shape(2.0f, 8.0f, 2.0f));
	shared_ptr< Rigid_Body > target_body3(new Dynamic_Rigid_Body(target_shape3, -40.f, 6.f, 10.f, 1.0f, btVector3(0.f, 0.f, 0.f)));
	shared_ptr <Entity> target3(new Entity("../../../../assets/caja2.obj", target_body3, 4.f, 16.f, 4.f));

	shared_ptr< Shape > target_shape4(new Box_Shape(2.0f, 8.0f, 2.0f));
	shared_ptr< Rigid_Body > target_body4(new Dynamic_Rigid_Body(target_shape4, -40.f, 6.f, 15.f, 1.0f, btVector3(0.f, 0.f, 0.f)));
	shared_ptr <Entity> target4(new Entity("../../../../assets/caja2.obj", target_body4, 4.f, 16.f, 4.f));

	scene->add("target", target);
	scene->add("target2", target2);
	scene->add("target3", target3);
	scene->add("target4", target4);
}