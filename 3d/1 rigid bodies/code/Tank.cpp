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
#include "Tank.hpp"


Tank::Tank(Vector3 origen, Scene * scene) : Entity(model_path, physics_model, gscale_x, gscale_y, gscale_z)
{
	//Creacion de los elementos:	Ruedas, cuerpo, torreta y cannon

	shared_ptr< Shape > rueda_shape(new Cylinder_Shape(0.5f, 0.5f, 0.5f));
	shared_ptr< Rigid_Body > rueda_body(new Dynamic_Rigid_Body(rueda_shape, -2.f + (origen.x), -2.f + (origen.y), 0.f + (origen.z), 0.1f, btVector3(90.f, 90.f, 0.f)));
	rueda_body->getBody()->setRestitution(0.f);
	shared_ptr <Entity> rueda(new Entity("../../../../assets/cilindro.obj", rueda_body, 1.f, 1.f, 1.f));
	rueda_body->getBody()->setActivationState(DISABLE_DEACTIVATION);

	shared_ptr< Shape > rueda_shape2(new Cylinder_Shape(0.5f, 0.5f, 0.5f));
	shared_ptr< Rigid_Body > rueda_body2(new Dynamic_Rigid_Body(rueda_shape2, 2.f + (origen.x), -2.f + (origen.y), 0.f + (origen.z), 1.f, btVector3(90.f, 90.f, 0.f)));
	rueda_body2->getBody()->setRestitution(0.f);
	shared_ptr <Entity> rueda2(new Entity("../../../../assets/cilindro.obj", rueda_body2, 1.f, 1.f, 1.f));
	rueda_body2->getBody()->setActivationState(DISABLE_DEACTIVATION);

	shared_ptr< Shape > rueda_shape3(new Cylinder_Shape(0.5f, 0.5f, 0.5f));
	shared_ptr< Rigid_Body > rueda_body3(new Dynamic_Rigid_Body(rueda_shape3, -2.f + (origen.x), 2.f + (origen.y), 0.f + (origen.z), 1.f, btVector3(90.f, 90.f, 0.f)));
	rueda_body3->getBody()->setRestitution(0.f);
	shared_ptr <Entity> rueda3(new Entity("../../../../assets/cilindro.obj", rueda_body3, 1.f, 1.f, 1.f));
	rueda_body3->getBody()->setActivationState(DISABLE_DEACTIVATION);

	shared_ptr< Shape > rueda_shape4(new Cylinder_Shape(0.5f, 0.5f, 0.5f));
	shared_ptr< Rigid_Body > rueda_body4(new Dynamic_Rigid_Body(rueda_shape4, 2.f + (origen.x), -2.f + (origen.y), 0.f + (origen.z), 1.f, btVector3(90.f, 90.f, 0.f)));
	rueda_body4->getBody()->setRestitution(0.f);
	shared_ptr <Entity> rueda4(new Entity("../../../../assets/cilindro.obj", rueda_body4, 1.f, 1.f, 1.f));
	rueda_body4->getBody()->setActivationState(DISABLE_DEACTIVATION);

	shared_ptr< Shape > rueda_shape5(new Cylinder_Shape(0.5f, 0.5f, 0.5f));
	shared_ptr< Rigid_Body > rueda_body5(new Dynamic_Rigid_Body(rueda_shape5, 2.f + (origen.x), -1.f + (origen.y), 0.f + (origen.z), 1.f, btVector3(90.f, 90.f, 0.f)));
	shared_ptr <Entity> rueda5(new Entity("../../../../assets/cilindro.obj", rueda_body5, 1.f, 1.f, 1.f));
	rueda_body5->getBody()->setActivationState(DISABLE_DEACTIVATION);

	shared_ptr< Shape > rueda_shape6(new Cylinder_Shape(0.5f, 0.5f, 0.5f));
	shared_ptr< Rigid_Body > rueda_body6(new Dynamic_Rigid_Body(rueda_shape6, -2.f + (origen.x), -1.f + (origen.y), 0.f + (origen.z), 1.f, btVector3(90.f, 90.f, 0.f)));
	shared_ptr <Entity> rueda6(new Entity("../../../../assets/cilindro.obj", rueda_body6, 1.f, 1.f, 1.f));
	rueda_body6->getBody()->setActivationState(DISABLE_DEACTIVATION);

	shared_ptr< Shape > cuerpo_shape(new Box_Shape(1.0f, 1.0f, 2.0f));
	shared_ptr< Rigid_Body > cuerpo_body(new Dynamic_Rigid_Body(cuerpo_shape, 0.f + (origen.x), 0.f + (origen.y), 0.f + (origen.z), 10.f, btVector3(0.f, 0.f, 0.f)));
	cuerpo_body->getBody()->setActivationState(DISABLE_DEACTIVATION);
	shared_ptr <Entity> cuerpo(new Entity("../../../../assets/caja2.obj", cuerpo_body, 2.f, 2.f, 4.f));

	shared_ptr< Shape > cuerpo_shape2(new Box_Shape(0.5f, 0.5f, 1.0f));
	shared_ptr< Rigid_Body > cuerpo_body2(new Dynamic_Rigid_Body(cuerpo_shape2, 0.f + (origen.x), 2.0f + (origen.y), 0.f + (origen.z), 1.f, btVector3(0.f, 0.f, 0.f)));
	cuerpo_body2->getBody()->setAngularFactor(btVector3(0, 1, 0));
	shared_ptr <Entity> cuerpo2(new Entity("../../../../assets/caja2.obj", cuerpo_body2, 1.f, 1.f, 2.f));

	shared_ptr< Shape > cannon_shape(new Cylinder_Shape(0.2f, 1.f, 0.2f));
	shared_ptr< Rigid_Body > cannon_body(new Dynamic_Rigid_Body(cannon_shape, -0.f + (origen.x), 2.f + (origen.y), 0.f + (origen.z), 0.01f, btVector3(0.f, 90.f, 0.f)));	
	shared_ptr <Entity> cannon(new Entity("../../../../assets/cilindro.obj", cannon_body, 0.4f, 2.f, 0.4f));

	//Creacion de los constraints: Ruedas, torreta y cannon
	add_constraints(scene, left_wheels[0], *rueda_body->getBody(), *cuerpo_body->getBody(), btVector3(0.f, 0.f, 0.f), btVector3(-2.f, -1.f, -2.f), btVector3(0.f, 1.f, 0.f), btVector3(0.f, 0.f, 0.f), true);
	add_constraints(scene, left_wheels[1], *rueda_body3->getBody(), *cuerpo_body->getBody(), btVector3(0.f, 0.f, 0.f), btVector3(-2.f, -1.f, 2.f), btVector3(0.f, 1.f, 0.f), btVector3(0.f, 0.f, 0.f), true);
	add_constraints(scene, left_wheels[2], *rueda_body6->getBody(), *cuerpo_body->getBody(), btVector3(0.f, 0.f, 0.f), btVector3(-2.f, -1.f, 0.f), btVector3(0.f, 1.f, 0.f), btVector3(0.f, 0.f, 0.f), true);

	add_constraints(scene, right_wheels[0], *rueda_body2->getBody(), *cuerpo_body->getBody(), btVector3(0.f, 0.f, 0.f), btVector3(2.f, -1.f, -2.f), btVector3(0.f, 1.f, 0.f), btVector3(0.f, 0.f, 0.f), true);
	add_constraints(scene, right_wheels[1], *rueda_body4->getBody(), *cuerpo_body->getBody(), btVector3(0.f, 0.f, 0.f), btVector3(2.f, -1.f, 2.f), btVector3(0.f, 1.f, 0.f), btVector3(0.f, 0.f, 0.f), true);
	add_constraints(scene, right_wheels[2], *rueda_body5->getBody(), *cuerpo_body->getBody(), btVector3(0.f, 0.f, 0.f), btVector3(2.f, -1.f, 0.f), btVector3(0.f, 1.f, 0.f), btVector3(0.f, 0.f, 0.f), true);

	add_constraints(scene, turret_tank, *cuerpo_body2->getBody(), *cuerpo_body->getBody(), btVector3(0.f, 0.f, 0.f), btVector3(0.f, 2.0f, 0.f), btVector3(0.f, 1.f, 0.f), btVector3(0.f, 0.f, 0.f), true);

	add_constraints(scene, cannon_tank, *cannon_body->getBody(), *cuerpo_body2->getBody(), btVector3(0.f, -1.f, 0.f), btVector3(0.f, 0.f, 1.5f), btVector3(1.f, 0.f, 0.f), btVector3(0.f, 0.f, 0.f), true);

	//Se añaden a la escena los elementos creados
	scene->add("rueda", rueda);
	scene->add("rueda2", rueda2);
	scene->add("rueda3", rueda3);
	scene->add("rueda4", rueda4);
	scene->add("rueda5", rueda5);
	scene->add("rueda6", rueda6);
	scene->add("cuerpo", cuerpo);
	scene->add("cuerpo2", cuerpo2);
	scene->add("cannon", cannon);
}