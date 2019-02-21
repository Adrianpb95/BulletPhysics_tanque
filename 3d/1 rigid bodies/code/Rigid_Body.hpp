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
#include "Shape.hpp"
#include <memory>
#include <iostream>


class Rigid_Body
{
	////////////////////////////////////////////////////////////
	// Declaracion de variables			
	////////////////////////////////////////////////////////////

protected:

	std::unique_ptr< btRigidBody 		   > body;		///<Cuerpo fisico
	std::unique_ptr< btDefaultMotionState  > state;		///<Motion state del cuerpo
	std::shared_ptr< Shape   			   > shape;		///<Forma del cuerpo



	////////////////////////////////////////////////////////////
	// Declaracion de funciones			
	////////////////////////////////////////////////////////////

public:

	////////////////////////////////////////////////////////////
	/// \brief	Constructor de Rigid_Body:	Crea un cuerpo fisico generico con un transform introducido por el usuario
	///	@param	shape		Forma del modelo fisico
	///	@param	x			Posicion en x del modelo fisico
	///	@param	y			Posicion en y del modelo fisico
	///	@param	z			Posicion en z del modelo fisico
	///	@param	rotation	Rotacion del modelo fisico
	////////////////////////////////////////////////////////////
	Rigid_Body(std::shared_ptr< Shape > & shape, float x, float y, float z, btVector3 rotation) : shape(shape)
	{
		btTransform transform;
		transform.setIdentity();
		transform.setOrigin(btVector3(x, y, z));
		btQuaternion auxRotation;
		auxRotation.setEuler(btRadians(rotation.getX()),
			btRadians(rotation.getY()),
			btRadians(rotation.getZ()));
		transform.setRotation(auxRotation);
		state.reset(new btDefaultMotionState(transform));
	}


	////////////////////////////////////////////////////////////
	/// \brief	Destructor de Rigid_Body
	////////////////////////////////////////////////////////////	
	virtual ~Rigid_Body(){}


	////////////////////////////////////////////////////////////
	/// \brief	Getter del cuerpo fisico
	////////////////////////////////////////////////////////////
	btRigidBody * getBody()
	{
		return body.get();
	}
};



class Static_Rigid_Body : public Rigid_Body
{
	////////////////////////////////////////////////////////////
	// Declaracion de funciones			
	////////////////////////////////////////////////////////////

public:

	////////////////////////////////////////////////////////////
	/// \brief	Constructor de Static_Rigid_Body:	Crea un cuerpo fisico estático con un transform introducido por el usuario
	///	@param	shape		Forma del modelo fisico
	///	@param	x			Posicion en x del modelo fisico
	///	@param	y			Posicion en y del modelo fisico
	///	@param	z			Posicion en z del modelo fisico
	///	@param	rotation	Rotacion del modelo fisico
	////////////////////////////////////////////////////////////
	Static_Rigid_Body(std::shared_ptr< Shape > & shape, float x, float y, float z, btVector3 rotation) : Rigid_Body(shape, x, y, z, rotation)
	{
		btRigidBody::btRigidBodyConstructionInfo info
		(
			0, state.get(), shape.get()->getShape()
		);

		body.reset(new btRigidBody(info));
	}

};


class Dynamic_Rigid_Body : public Rigid_Body
{
	////////////////////////////////////////////////////////////
	// Declaracion de variables			
	////////////////////////////////////////////////////////////

private:

	btScalar mass;		///<Masa del cuerpo fisico


	////////////////////////////////////////////////////////////
	// Declaracion de funciones			
	////////////////////////////////////////////////////////////

public:

	////////////////////////////////////////////////////////////
	/// \brief	Constructor de Dynamic_Rigid_Body:	Crea un cuerpo fisico dinamico con un transform introducido por el usuario y una masa determinada
	///	@param	shape		Forma del modelo fisico
	///	@param	x			Posicion en x del modelo fisico
	///	@param	y			Posicion en y del modelo fisico
	///	@param	z			Posicion en z del modelo fisico
	///	@param	rotation	Rotacion del modelo fisico
	////////////////////////////////////////////////////////////
	Dynamic_Rigid_Body(std::shared_ptr< Shape > & shape, float x, float y, float z, float mass, btVector3 rotation) : Rigid_Body(shape, x, y, z, rotation), mass(btScalar(mass))
	{
		btVector3 localInertia(0, 0, 0);

		shape->getShape()->calculateLocalInertia(mass, localInertia);

		btRigidBody::btRigidBodyConstructionInfo info
		(
			mass, state.get(), shape.get()->getShape(), localInertia
		);

		body.reset(new btRigidBody(info));
	}
};