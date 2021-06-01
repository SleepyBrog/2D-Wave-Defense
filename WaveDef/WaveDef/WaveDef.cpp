#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Player.h"
#include "Platform.h"

using namespace std;

int main()
{
	int ResX = sf::VideoMode::getDesktopMode().width;
	int ResY = sf::VideoMode::getDesktopMode().height;
	sf::RenderWindow window(sf::VideoMode(ResX, ResY), "SFML works!", sf::Style::None);
	window.setFramerateLimit(60);
	Player player;
	vector <Platform> walls;
	Platform wall(400, 400, 64, 64, 1);
	walls.push_back(wall);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		player.Update(window);
		window.draw(wall.shape);
		player.PlatformCollisionCheck(wall);
		window.display();
	}
	return 0;

}