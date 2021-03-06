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

class Ground : public Entity
{
	////////////////////////////////////////////////////////////
	// Declaracion de funciones			
	////////////////////////////////////////////////////////////

public:

	////////////////////////////////////////////////////////////
	/// \brief	Constructor de Ground:	Crea los suelos y los a�ade a escena
	///	@param	scene		Referencia a la escena
	////////////////////////////////////////////////////////////
	Ground(Scene * scene);
};