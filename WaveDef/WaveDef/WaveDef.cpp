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
vector<Platform> walls;
vector<Enemy> enemies;
Platform wall(400, 400, 64, 64, 1);
Enemy enemy(900, 500, 50, 50, 5, 0.2, &player);


//	Added function to centre the viewport
void centerViewport(sf::View view, sf::RenderWindow &window, Entity target);

int main()
{

	walls.push_back(wall);
	enemies.push_back(enemy);

	int ResX = sf::VideoMode::getDesktopMode().width;
	int ResY = sf::VideoMode::getDesktopMode().height;
	sf::RenderWindow window(sf::VideoMode(ResX, ResY), "2D Wave Defense", sf::Style::None);
	sf::View view = window.getView();
	window.setFramerateLimit(60);
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
		for (Enemy& enemy : enemies) {
			enemy.Update(window);
			enemy.PlatformCollisionCheck(walls);
		}
		window.draw(wall.shape);
		player.PlatformCollisionCheck(walls);
		player.EnemyCollisionCheck(enemies);
		centerViewport(view, window, player);
		window.display();

		if (!player.isAlive) {
			player.shape.setFillColor(sf::Color::Transparent);
		}
	}
	return 0;

}

void centerViewport(sf::View view, sf::RenderWindow &window, Entity target) {
	view.setCenter(target.xPos, target.yPos);
	window.setView(view);
}
