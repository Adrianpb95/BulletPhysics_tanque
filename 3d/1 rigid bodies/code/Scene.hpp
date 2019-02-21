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
#include <Light.hpp>
#include <Model_Obj.hpp>
#include <Render_Node.hpp>
#include "btBulletDynamicsCommon.h"
#include "Physics_World.hpp"
#include <SFML/Window.hpp>

////////////////////////////////////////////////////////////
// NameSpaces
////////////////////////////////////////////////////////////
using namespace std;
using namespace glt;

class Tank;
class Door;
class Platform;
class Entity;
class Scene
{
	////////////////////////////////////////////////////////////
	// Declaracion de variables			
	////////////////////////////////////////////////////////////

private:

	map<string, shared_ptr<Entity>> entities;				///<Conjunto de entitys de la escena
	glt::Render_Node graphics_scene;						///<Escena grafica
	shared_ptr< Physics_World > physics_world;				///<Escena fisica

	shared_ptr<Tank> tank;									///<Modelo del tanque en la escena
	shared_ptr<Entity> key;									///<Modelo de la llave en la escena
	shared_ptr<Entity> target;								///<Modelo de los targets en la escena
	shared_ptr<Platform> platform;							///<Modelo de las plataformas moviles en la escena
	shared_ptr<Door> door;									///<Modelo de la puerta en la escena
	shared_ptr<Entity> ground;								///<Modelo de los suelos en la escena

	sf::Keyboard::Key last_key = sf::Keyboard::Escape;		///<Referencia de la ultima tecla pulsada por el jugador

	bool key_picked = false;								///<Auxiliar: se ha recogido la llave?
	bool plat_move = false;									///<Auxiliar: se ha activado la plataforma?
	int num_aux = 0;										///<Auxiliar: contador de balas



	////////////////////////////////////////////////////////////
	// Declaracion de funciones			
	////////////////////////////////////////////////////////////

public:

	////////////////////////////////////////////////////////////
	/// \brief	Constructor de Scene:	Crea el mundo visual y fisico, e inicializa todos los entitys de la escena
	////////////////////////////////////////////////////////////
	Scene();

	////////////////////////////////////////////////////////////
	/// \brief	Destructor de la escena
	////////////////////////////////////////////////////////////
	~Scene()
	{
		physics_world.reset();
	}

	////////////////////////////////////////////////////////////
	/// \brief	Getter del mundo grafico
	////////////////////////////////////////////////////////////
	Render_Node *getScene()
	{
		return &graphics_scene;
	}

	////////////////////////////////////////////////////////////
	/// \brief	Getter del mundo fisico
	////////////////////////////////////////////////////////////
	Physics_World *getPhysWorld()
	{
		return physics_world.get();
	}

	////////////////////////////////////////////////////////////
	/// \brief	Añade los elementos de la escena a un array, al mundo grafico y al mundo fisico
	////////////////////////////////////////////////////////////
	void add(const string & name, shared_ptr< Entity > entity);

	////////////////////////////////////////////////////////////
	/// \brief	Input por teclado: Gestiona el movimiento del tanque
	////////////////////////////////////////////////////////////
	void on_key(sf::Keyboard::Key key, bool down);

	////////////////////////////////////////////////////////////
	/// \brief	Input por raton: Disparo del cannon del tanque
	////////////////////////////////////////////////////////////
	void on_click();

	////////////////////////////////////////////////////////////
	/// \brief	Actualizacion de la escena: Updatea el mundo fisico, todas las entities y gestiona las colisiones
	////////////////////////////////////////////////////////////
	void update();
};

