#include <stdio.h>
#include <time.h>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Player.h"
#include "Platform.h"
#include "Enemy.h"

using namespace std;


// A lot of this file is just set up for testing
// Planning on setting up better solutions like entity vectors and general functions

Player player;
vector <Platform> walls;
Platform wall(400, 400, 64, 64, 1);
Enemy enemy(900, 500, 50, 50, 5, 0.2, &player);

int main()
{
	int ResX = sf::VideoMode::getDesktopMode().width;
	int ResY = sf::VideoMode::getDesktopMode().height;
	sf::RenderWindow window(sf::VideoMode(ResX, ResY), "SFML works!", sf::Style::None);
	window.setFramerateLimit(60);
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
		enemy.Update(window);
		window.draw(wall.shape);
		player.PlatformCollisionCheck(wall);
		player.EnemyCollisionCheck(enemy);
		enemy.PlatformCollisionCheck(wall);
		window.display();

		if (!player.isAlive) {
			player.shape.setFillColor(sf::Color::Transparent);
		}
	}
	return 0;

}