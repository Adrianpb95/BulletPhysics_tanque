/*
ADRIAN PONCE BALSEIRO
ESNE G4.3 DDVJ
adrianpb95@gmail.com
10 / 06 / 2018
*/

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#pragma once
#include "Scene.hpp"
#include "Ground.hpp"

Ground::Ground(Scene * scene) : Entity(model_path, physics_model, gscale_x, gscale_y, gscale_z)
{
	shared_ptr< Shape > suelo_shape(new Box_Shape(15.0f, 1.0f, 20.0f));
	shared_ptr< Rigid_Body > suelo_body(new Static_Rigid_Body(suelo_shape, 50.f, -5.f, 0.f, btVector3(0.f, 0.f, 0.f)));
	shared_ptr <Entity> suelo(new Entity("../../../../assets/caja2.obj", suelo_body, 30.f, 2.f, 40.f));

	shared_ptr< Shape > suelo_shape2(new Box_Shape(15.0f, 1.0f, 20.0f));
	shared_ptr< Rigid_Body > suelo_body2(new Static_Rigid_Body(suelo_shape2, 0.f, -5.f, 0.f, btVector3(0.f, 0.f, 0.f)));
	shared_ptr <Entity> suelo2(new Entity("../../../../assets/caja2.obj", suelo_body2, 30.f, 2.f, 40.f));

	shared_ptr< Shape > suelo_shape3(new Box_Shape(15.0f, 1.0f, 20.0f));
	shared_ptr< Rigid_Body > suelo_body3(new Static_Rigid_Body(suelo_shape3, -50.f, -5.f, 0.f, btVector3(0.f, 0.f, 0.f)));
	shared_ptr <Entity> suelo3(new Entity("../../../../assets/caja2.obj", suelo_body3, 30.f, 2.f, 40.f));

	scene->add("suelo", suelo);
	scene->add("suelo2", suelo2);
	scene->add("suelo3", suelo3);
}