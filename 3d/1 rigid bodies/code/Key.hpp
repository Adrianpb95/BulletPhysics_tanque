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

class Key : public Entity
{
	////////////////////////////////////////////////////////////
	// Declaracion de funciones			
	////////////////////////////////////////////////////////////

public:

	////////////////////////////////////////////////////////////
	/// \brief	Constructor de Key:	Crea la llave y la a�ade a la escena
	///	@param	scene		Referencia a la escena
	////////////////////////////////////////////////////////////
	Key(Scene * scene);
};
