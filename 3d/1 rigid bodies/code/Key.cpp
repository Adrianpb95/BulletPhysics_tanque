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
#include "Key.hpp"

Key::Key(Scene * scene) : Entity(model_path, physics_model, gscale_x, gscale_y, gscale_z)
{
	shared_ptr< Shape > llave_shape(new Sphere_Shape(6.f));
	shared_ptr< Rigid_Body > llave_body(new Static_Rigid_Body(llave_shape, 40.f, 1.f, -15.f, btVector3(0.f, 0.f, 0.f)));
	shared_ptr <Entity> llave(new Entity("../../../../assets/Key_B_02.obj", llave_body, 1.f, 1.f, 1.f));

	//Se le desactiva la colision para que funcione como un trigger
	llave_body->getBody()->setCollisionFlags(btCollisionObject::CF_NO_CONTACT_RESPONSE);
	llave_body->getBody()->setActivationState(DISABLE_DEACTIVATION);
	scene->add("llave", llave);
}