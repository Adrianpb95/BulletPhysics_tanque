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
#include "Bullet.hpp"

Bullet::Bullet(Scene * scene, float x, float y, float z, int num, btVector3 direction, btQuaternion rotation) : Entity(model_path, physics_model, gscale_x, gscale_y, gscale_z)
{
	shared_ptr< Shape > bullet_shape(new Sphere_Shape(0.5f));
	shared_ptr< Rigid_Body > bullet_body(new Dynamic_Rigid_Body(bullet_shape, x, y, z, 0.08f, btVector3(0.f, 0.f, 0.f)));
	shared_ptr <Entity> bullet(new Entity("../../../../assets/sphere.obj", bullet_body, 1.f, 1.f, 1.f));

	scene->add(std::to_string(num), bullet);

	//Se usa la rotacion del cannon para girar la bala con esa misma rotacion, y poder moverla. De esta forma, hacemos que la bala no salga de mitad del cannon, sino de la punta
	btQuaternion auxRotation;
	auxRotation.setEuler(btRadians(rotation.getX()),
		btRadians(rotation.getY()),
		btRadians(rotation.getZ()));
	bullet_body->getBody()->getWorldTransform().setRotation(auxRotation);
	bullet_body->getBody()->getWorldTransform().setOrigin(btVector3(x, y+1.0, z));
	bullet->get_physics_model()->getBody()->applyImpulse(5.f*direction, bullet->get_physics_model()->getBody()->getCenterOfMassPosition());
}