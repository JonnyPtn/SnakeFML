#include <iostream>
#include "Snake.hpp"
#include "Mouse.hpp"
#include "Collision.hpp"

int main()
{
	//hardcode size for now...
	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");

	//limit to 60 for now. Coil whine is annoying
	window.setFramerateLimit(60);

	//measure dt
	sf::Clock dtClock;

	//our snake and mouse
	Snake snake(&window);
	Mouse mouse(window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased)
			{
				//snake handles it's input
				snake.handleEvent(event);
			}
		}

		//update snake
		snake.update(dtClock.restart().asSeconds());
		
		//check for collision with mouse
		if(Collision::checkForCollision(snake.getBodyPosition(), mouse.getBodyPosition(), mouse.getBodySize()))
		{
			mouse.respawn();
		}

		window.clear(sf::Color::Green); // green because... grass?
		window.draw(snake);
		window.draw(mouse);
		window.display();
	}

	return 0;
};