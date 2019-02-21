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
#include "Tank.hpp"
#include "Key.hpp"
#include "Target.hpp"
#include "Platform.hpp"
#include "Door.hpp"
#include "Ground.hpp"
#include "Bullet.hpp"
#include <math.h>
#include <iostream>

//Inicializacion de los elementos de escena
Scene::Scene()
{
	physics_world = make_shared< Physics_World >();

	shared_ptr< Camera > camera(new Camera(20.f, 1.f, 200.f, 1.f));
	shared_ptr< Light  > light(new Light);

	camera->translate(Vector3(15.f, 20.f, 60.f));
	camera->rotate_around_y(0.20f);
	camera->rotate_around_x(-0.15f);
	light->translate(Vector3(5.f, 5.f, 5.f));

	graphics_scene.add("camera", camera);
	graphics_scene.add("light", light);

	tank.reset(new Tank(Vector3(50.f, -2.f, 0.f), this));
	key.reset(new Key(this));
	target.reset(new Target(this));
	platform.reset(new Platform(this));
	door.reset(new Door(this));
	ground.reset(new Ground(this));	
}

void Scene::update()
{
	//Actualiza el mundo fisico
	physics_world->step(1.f / 60.f);

	//Actualizar todas las entidades	
	for (auto obj : entities) {
		obj.second->update();
	}

	//Movimiento de las plataformas
	if (plat_move == true)
	{
		platform->move_platform();
	}
	
	//Detector de colisiones
	int   manifold_count = physics_world->getWorld()->getDispatcher()->getNumManifolds();
	for (int i = 0; i < manifold_count; i++) {
		btPersistentManifold   *   manifold = physics_world->getWorld()->getDispatcher()->getManifoldByIndexInternal(i);
		btCollisionObject   *   object_a = (btCollisionObject   *)(manifold->getBody0());
		btCollisionObject   *   object_b = (btCollisionObject   *)(manifold->getBody1());
		int   numContacts = manifold->getNumContacts();
		for (int j = 0; j < numContacts; j++)
		{
			btManifoldPoint   &   point = manifold->getContactPoint(j);
			if (point.getDistance() < 0.f)
			{
				//Entre tanque y llave
				if (key_picked == false) {

					btRigidBody * key = entities["llave"]->get_physics_model()->getBody();
					btRigidBody * body = entities["cuerpo"]->get_physics_model()->getBody();

					if ((object_a == key && object_b == body) || (object_a == body && object_b == key))
					{
						door->open_door();
						entities["llave"]->get_graphics_model()->set_visible(false);
						entities["platform"]->get_graphics_model()->set_visible(true);
						entities["platform2"]->get_graphics_model()->set_visible(true);

						key_picked = true;
					}
				}
				//Entre tanque y plataforma derecha
				if (plat_move == false)
				{
					btRigidBody * wheel = entities["rueda6"]->get_physics_model()->getBody();
					btRigidBody * platform = entities["platform"]->get_physics_model()->getBody();

					if ((object_a == wheel && object_b == platform) || (object_a == platform && object_b == wheel))
					{
						entities["platform"]->get_physics_model()->getBody()->setLinearVelocity(btVector3(-2.f, 0.f, 0.f));
						entities["platform2"]->get_physics_model()->getBody()->setLinearVelocity(btVector3(0.f, 0.f, 5.f));

						plat_move = true;
					}
				}
			}
		}
	}
}


void Scene::add(const string & name, shared_ptr<Entity> entity)
{
	entities[name] = entity;
	graphics_scene.add(name, entity->get_graphics_model());
	physics_world->add(entity->get_physics_model());
}


void Scene::on_click()
{
	//Direccion de salida de la bala
	btVector3 directionTurret = entities["cannon"]->get_physics_model()->getBody()->getWorldTransform().getOrigin();
	btVector3 directionTank = entities["cuerpo2"]->get_physics_model()->getBody()->getWorldTransform().getOrigin();
	btVector3 directionFinal = (directionTurret - directionTank);

	//Spawn de la bala
	shared_ptr <Entity> bullet(new Bullet(this,
		entities["cannon"]->get_physics_model()->getBody()->getWorldTransform().getOrigin().getX(),
		entities["cannon"]->get_physics_model()->getBody()->getWorldTransform().getOrigin().getY(),
		entities["cannon"]->get_physics_model()->getBody()->getWorldTransform().getOrigin().getZ(),
		num_aux, directionFinal, entities["cannon"]->get_physics_model()->getBody()->getWorldTransform().getRotation()));

	//Contador auxiliar para nombrarlas
	num_aux++;
}

void Scene::on_key(sf::Keyboard::Key key, bool down)
{
	//Solo recibe informacion de una tecla a la vez, es decir, si una tecla es pulsada
	//hasta que no se levanta, no se recibe informacion de otra
	if (!down && last_key == key)
		last_key = sf::Keyboard::Escape;

	else if (down && last_key == sf::Keyboard::Escape)
		last_key = key;

	if (last_key == key || last_key == sf::Keyboard::Escape)
	{
		float vel = 0;
		switch (key)
		{
		case sf::Keyboard::W:
		{
			if (down)
				vel = -10.f;
			else
				vel = 0.f;

			tank->go_forward_reverse(vel);

			break;
		}
		case sf::Keyboard::S:
		{
			if (down)
				vel = 10.f;
			else
				vel = 0.f;

			tank->go_forward_reverse(vel);

			break;
		}

		case sf::Keyboard::D:
		{
			if (down)
				vel = 5.f;
			else
				vel = 0.f;

			tank->turn_right(vel);

			break;
		}

		case sf::Keyboard::A:
		{
			if (down)
				vel = 5.f;
			else
				vel = 0.f;

			tank->turn_left(vel);

			break;
		}

		case sf::Keyboard::Left:
		{
			if (down)
				vel = 0.5f;
			else
				vel = 0.f;

			tank->turret_turn(vel);
			break;
		}

		case sf::Keyboard::Right:
		{
			if (down)
				vel = -0.5f;
			else
				vel = 0.f;

			tank->turret_turn(vel);
			break;
		}

		case sf::Keyboard::Up:
		{
			if (down)
				vel = 0.5f;
			else
				vel = 0.f;

			float limit = (entities["cannon"]->get_physics_model()->getBody()->getWorldTransform().getOrigin().getY() + 0.05f);
			
			if(limit < -0.f && limit > -0.7f)
				tank->cannon_up_down(vel);
			else
				tank->cannon_up_down(0.f);
			break;
		}

		case sf::Keyboard::Down:
		{
			if (down)
				vel = -0.5f;
			else
				vel = 0.f;

			float limit = (entities["cannon"]->get_physics_model()->getBody()->getWorldTransform().getOrigin().getY()-0.05f);

			if (limit < -0.f && limit > -0.7f)
				tank->cannon_up_down(vel);
			else
				tank->cannon_up_down(0.f);
			break;
		}
		}
	}
}




