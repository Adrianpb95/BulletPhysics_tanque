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
#include <Model_Obj.hpp>

////////////////////////////////////////////////////////////
// NameSpaces
////////////////////////////////////////////////////////////
using namespace std;
using namespace glt;

class Scene;
class Entity
{
	////////////////////////////////////////////////////////////
	// Declaracion de variables			
	////////////////////////////////////////////////////////////

protected:

	float						 gscale_x, gscale_y, gscale_z;	///<Escala de la entidad
	shared_ptr< glt::Model_Obj > graphics_model;				///<Modelo visual
	shared_ptr< Rigid_Body >      physics_model;				///<Modelo físico
	const string model_path;									///<Ruta del modelo a cargar



	////////////////////////////////////////////////////////////
	// Declaracion de funciones	
	////////////////////////////////////////////////////////////

public:

	////////////////////////////////////////////////////////////
	/// \brief	Constructor de Entity:	Guarda el modelo visual y fisico de cada elemento
	///	@param	model_path		Ruta del modelo visual
	///	@param	physics_model	Modelo físico
	///	@param	gscale_x		Escala en x
	///	@param	gscale_y		Escala en y
	///	@param	gscale_z		Escala en z
	////////////////////////////////////////////////////////////
	Entity(const string & model_path, shared_ptr< Rigid_Body > & physics_model, float gscale_x, float gscale_y, float gscale_z)
		:
		model_path(model_path),
		physics_model(physics_model),
		gscale_x(gscale_x), gscale_y(gscale_y), gscale_z(gscale_z)

	{
		graphics_model.reset(new Model_Obj(model_path));
	}

	////////////////////////////////////////////////////////////
	/// \brief	Destructor de Entity
	////////////////////////////////////////////////////////////
	virtual ~Entity(){}

	////////////////////////////////////////////////////////////
	/// \brief	Getter del modelo grafico
	////////////////////////////////////////////////////////////
	shared_ptr< glt::Model_Obj > &get_graphics_model()
	{
		return graphics_model;
	}

	////////////////////////////////////////////////////////////
	/// \brief Getter del modelo físico
	////////////////////////////////////////////////////////////
	shared_ptr< Rigid_Body > & get_physics_model()
	{
		return physics_model;
	}

	////////////////////////////////////////////////////////////
	/// \brief	Aplica las transformaciones fisicas al modelo grafico
	////////////////////////////////////////////////////////////
	void update();


protected:
	////////////////////////////////////////////////////////////
	/// \brief	Crea constraints y los añade al mundo fisico
	///	@param	scene			Referencia a la escena
	///	@param	constraint		Tipo de constraint al que se añade
	///	@param	body1			Primer cuerpo de la union
	///	@param	body2			Segundo cuerpo de la union
	///	@param	pos_body1		Posicion del primer cuerpo
	///	@param	pos_body2		Posicion del segundo cuerpo
	///	@param	rot_body1		Rotacion del primer cuerpo
	///	@param	rot_body2		Rotacion del segudno cuerpo
	///	@param	ref_frame_A		Usar como referencia el frame A
	////////////////////////////////////////////////////////////
	void add_constraints(Scene * scene, shared_ptr< btHingeConstraint > & constraint, btRigidBody &body1, btRigidBody &body2, btVector3 pos_body1, btVector3 pos_body2, btVector3 rot_body1, btVector3 rot_body2, bool ref_frame_A)
	{
		constraint.reset(new btHingeConstraint(body1, body2, pos_body1, pos_body2, rot_body1, rot_body2, ref_frame_A));
		constraint->enableAngularMotor(true, 0.f, 10.f);
		scene->getPhysWorld()->addConstraints(constraint.get());
	}
};