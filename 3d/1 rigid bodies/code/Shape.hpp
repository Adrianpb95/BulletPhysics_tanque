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
#include <btBulletDynamicsCommon.h>

class Shape
{
	////////////////////////////////////////////////////////////
	// Declaracion de variables			
	////////////////////////////////////////////////////////////

private:

	std::shared_ptr< btCollisionShape > shape;	 ///<Referencia a la forma de la entity


	////////////////////////////////////////////////////////////
	//	Declaracion de funciones	
	////////////////////////////////////////////////////////////

public:

	////////////////////////////////////////////////////////////
	/// \brief	Destructor de Shape 
	////////////////////////////////////////////////////////////
	virtual ~Shape() = default;

	////////////////////////////////////////////////////////////
	/// \brief	Constructor de Shape:	Constructor default de Shape generica
	///	@param	shape		Tipo de forma de la entity
	////////////////////////////////////////////////////////////
	Shape(std::shared_ptr< btCollisionShape > & shape) : shape(shape) {}

	////////////////////////////////////////////////////////////
	/// \brief	Getter de la forma
	////////////////////////////////////////////////////////////
	btCollisionShape * getShape()
	{
		return shape.get();
	}
};


class Sphere_Shape : public Shape
{
	////////////////////////////////////////////////////////////
	//	Declaracion de funciones	
	////////////////////////////////////////////////////////////

public:

	////////////////////////////////////////////////////////////
	/// \brief	Constructor de Shpere_Shape:	Constructor de una Shape esferica
	///	@param	radius		Radio de la esfera
	////////////////////////////////////////////////////////////
	Sphere_Shape(float radius) : Shape(std::shared_ptr< btCollisionShape >(new btSphereShape(btScalar(radius)))) {}
};


class Box_Shape : public Shape
{
	////////////////////////////////////////////////////////////
	//	Declaracion de funciones	
	////////////////////////////////////////////////////////////

public:

	////////////////////////////////////////////////////////////
	/// \brief	Constructor de Box_Shape:	Constructor de una Shape cubica
	///	@param	width		Ancho del cubo
	///	@param	height		Alto del cubo
	///	@param	depth		Profundidad del cubo
	////////////////////////////////////////////////////////////
	Box_Shape(float width, float height, float depth) : Shape(std::shared_ptr< btCollisionShape >(new btBoxShape(btVector3(width, height, depth)))) {}
};



class Cylinder_Shape : public Shape
{
	////////////////////////////////////////////////////////////
	//	Declaracion de funciones	
	////////////////////////////////////////////////////////////

public:

	////////////////////////////////////////////////////////////
	/// \brief	Constructor de Cylinder_Shape:	Constructor de una Shape cilindrica
	///	@param	width		Ancho del cinlindro
	///	@param	height		Alto del cinlindro
	///	@param	depth		Profundidad del cinlindro
	////////////////////////////////////////////////////////////
	Cylinder_Shape(float width, float height, float depth) : Shape(std::shared_ptr< btCollisionShape >(new btCylinderShape(btVector3(width, height, depth)))) {}
};