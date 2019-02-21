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
#include "Rigid_Body.hpp"
#include <vector>

class Physics_World
{
	////////////////////////////////////////////////////////////
	// Declaracion de variables			
	////////////////////////////////////////////////////////////

private:

	std::unique_ptr< btDiscreteDynamicsWorld>		  world;		///<Referencia al mundo fisico
	std::vector< std::shared_ptr< Rigid_Body>>		 bodies;		///<Conjunto de cuerpos fisicos a�adidos al mundo fisico
	std::vector< btHingeConstraint >			constraints;		///<Conjunto de constraints a�adidos al mundo fisico

	btDefaultCollisionConfiguration collisionConfiguration;			///< Collision configuration contains default setup for memory, collision setup.
	btCollisionDispatcher collisionDispatcher;						///< Use the default collision dispatcher
	btDbvtBroadphase overlappingPairCache;							///< btDbvtBroadphase is a good general purpose broadphase
	btSequentialImpulseConstraintSolver constraintSolver;			///< The default constraint solver


	////////////////////////////////////////////////////////////
	// Declaracion de funciones			
	////////////////////////////////////////////////////////////

public:

	////////////////////////////////////////////////////////////
	/// \brief	Constructor de Physics_World:	Crea el mundo fisico de la escena
	////////////////////////////////////////////////////////////
	Physics_World() : collisionDispatcher(&collisionConfiguration)
	{
		world.reset(new btDiscreteDynamicsWorld(
				&collisionDispatcher,
				&overlappingPairCache,
				&constraintSolver,
				&collisionConfiguration));
		world->setGravity(btVector3(0, -10, 0));
	}

	////////////////////////////////////////////////////////////
	/// \brief	Destructor de Physics_World
	////////////////////////////////////////////////////////////
	~Physics_World()
	{
		world.reset();
	}

	////////////////////////////////////////////////////////////
	/// \brief	Getter del mundo fisico
	////////////////////////////////////////////////////////////
	btDiscreteDynamicsWorld *getWorld()
	{
		return world.get();
	}

	////////////////////////////////////////////////////////////
	/// \brief	A�ade el cuerpo al array del mundo fisico y lo a�ade al mismo
	///	@param	body	Cuerpo fisico a a�adir
	////////////////////////////////////////////////////////////
	void add(std::shared_ptr< Rigid_Body > & body)
	{
		bodies.push_back(body);
		world->addRigidBody(body->getBody());
	}

	////////////////////////////////////////////////////////////
	/// \brief	A�ade el constraint al array del mundo fisico y lo a�ade al mismo
	///	@param	hinge	Constraint a a�adir
	////////////////////////////////////////////////////////////
	void addConstraints(btHingeConstraint * hinge)
	{
		constraints.push_back(*hinge);
		world->addConstraint(hinge);
	}

	////////////////////////////////////////////////////////////
	/// \brief	Actualiza la simulacion del mundo fisico y sus cuerpos
	///	@param	time	Tiempo de cada step
	////////////////////////////////////////////////////////////
	void step(float time)
	{
		world->stepSimulation(time);
	}

};