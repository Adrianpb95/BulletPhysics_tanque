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
#include "Entity.hpp"

class Tank : public Entity
{
	////////////////////////////////////////////////////////////
	// Declaracion de variables			
	////////////////////////////////////////////////////////////

private:

	shared_ptr< btHingeConstraint >  left_wheels[3];		///<Constraints de ruedas izquierdas
	shared_ptr< btHingeConstraint > right_wheels[3];		///<Constraints de ruedas derechas

	shared_ptr< btHingeConstraint > turret_tank;			///<Constraints de la torreta del tanque
	shared_ptr< btHingeConstraint > cannon_tank;			///<Constraints del cannon del tanque


	////////////////////////////////////////////////////////////
	// Declaracion de funciones			
	////////////////////////////////////////////////////////////

public:

	////////////////////////////////////////////////////////////
	/// \brief	Constructor de Tank:	Crea el tanque con todos sus elementos y los añade a la escena
	///	@param	origen		Posicion donde colocar el tanque
	///	@param	scene		Referencia a la escena
	////////////////////////////////////////////////////////////
	Tank(Vector3 origen, Scene * scene);

	////////////////////////////////////////////////////////////
	/// \brief	Giro a izquierdas del tanque
	///	@param	vel		Velocidad de giro de las ruedas
	////////////////////////////////////////////////////////////
	void turn_left(float vel)
	{
		for (auto & wheel : left_wheels) { wheel->setMotorTargetVelocity(-vel); }
		for (auto & wheel : right_wheels) { wheel->setMotorTargetVelocity(vel); }
	}

	////////////////////////////////////////////////////////////
	/// \brief	Giro a derechas del tanque
	///	@param	vel		Velocidad de giro de las ruedas
	////////////////////////////////////////////////////////////
	void turn_right(float vel)
	{
		for (auto & wheel : left_wheels) { wheel->setMotorTargetVelocity(vel); }
		for (auto & wheel : right_wheels) { wheel->setMotorTargetVelocity(-vel); }
	}

	////////////////////////////////////////////////////////////
	/// \brief	Movimiento del tanque: Avance y retroceso
	///	@param	vel		Velocidad de giro de las ruedas
	////////////////////////////////////////////////////////////
	void go_forward_reverse(float vel)
	{
		for (auto & wheel : left_wheels) { wheel->setMotorTargetVelocity(vel); }
		for (auto & wheel : right_wheels) { wheel->setMotorTargetVelocity(vel); }
	}

	////////////////////////////////////////////////////////////
	/// \brief	Giro de la torreta
	///	@param	vel		Velocidad de giro de la torreta
	////////////////////////////////////////////////////////////
	void turret_turn(float vel)
	{
		turret_tank->setMotorTargetVelocity(vel);
	}

	////////////////////////////////////////////////////////////
	/// \brief	Movimiento del cannon: Arriba y abajo
	///	@param	vel		Velocidad de movimiento del cannon
	////////////////////////////////////////////////////////////
	void cannon_up_down(float vel)
	{		
		cannon_tank->setMotorTargetVelocity(vel);
	}
};