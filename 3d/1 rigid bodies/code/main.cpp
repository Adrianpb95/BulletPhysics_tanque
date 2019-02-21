/*
ADRIAN PONCE BALSEIRO
ESNE G4.3 DDVJ
adrianpb95@gmail.com
10 / 06 / 2018
*/

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Window.hpp>
#include <btBulletDynamicsCommon.h>
#include "Scene.hpp"

using namespace std;
using namespace glt;


void reset_viewport(const sf::Window & window, Render_Node & scene)
{
	GLsizei width = GLsizei(window.getSize().x);
	GLsizei height = GLsizei(window.getSize().y);

	scene.get_active_camera()->set_aspect_ratio(float(width) / height);

	glViewport(0, 0, width, height);
}

int main()
{	/* -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- +\
	SIMULATION
	\+ -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- */

	// Se crea la ventana y el contexto de OpenGL asociado a ella:

	sf::Window window
	(
		sf::VideoMode(1024, 720),
		"Bullet Rigid Bodies",
		sf::Style::Default,
		sf::ContextSettings(24, 0, 0, 3, 2, sf::ContextSettings::Core)      // Se usa OpenGL 3.2 core profile
	);

	// Se determinan las características de OpenGL disponibles en la máquina:

	if (!glt::initialize_opengl_extensions())
	{
		exit(-1);
	}

	// Se activa la sincronización vertical:

	window.setVerticalSyncEnabled(true);

	// Se crea la escena
	Scene sceneS;


	// Se inicializan algunos elementos de OpenGL:
	reset_viewport(window, *sceneS.getScene());

	glClearColor(0.2f, 0.2f, 0.2f, 1.f);

	bool running = true;
	int  frame = 0;

	do
	{
		// Read the user input:

		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
			{
				running = false;
				break;
			}

			case sf::Event::Resized:
			{
				reset_viewport(window, *sceneS.getScene());
				break;
			}

			case sf::Event::KeyPressed:
			{
				sceneS.on_key(event.key.code, true);
				break;
			}

			case sf::Event::KeyReleased:
			{
				sceneS.on_key(event.key.code, false);
				break;
			}

			case sf::Event::MouseButtonReleased:
			{
				sceneS.on_click();
				break;
			}
			}
		}

		// Perform the simulation:		
		sceneS.update();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		sceneS.getScene()->render();

		window.display();
	} while (running);

	return EXIT_SUCCESS;
}