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

class Bullet : public Entity
{
	////////////////////////////////////////////////////////////
	// Declaracion de funciones			
	////////////////////////////////////////////////////////////

public:

	////////////////////////////////////////////////////////////
	/// \brief	Constructor de Bullet:	Crea las balas, las añade a escena y las impulsa
	///	@param	scene		Referencia a la escena
	///	@param	x			Posicion en x de la bala
	///	@param	y			Posicion en y de la bala 
	///	@param	z			Posicion en z de la bala 
	///	@param	num			Contador auxiliar para nombrar las balas
	///	@param	direction	Direccion de salida de la bala
	///	@param	rotation	Rotacion del cannon 
	////////////////////////////////////////////////////////////
	Bullet(Scene * scene, float x, float y, float z, int num, btVector3 direction, btQuaternion rotation);
};