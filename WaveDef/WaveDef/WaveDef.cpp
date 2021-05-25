#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Player.h"

int main()
{
	int ResX = sf::VideoMode::getDesktopMode().width;
	int ResY = sf::VideoMode::getDesktopMode().height;
	sf::RenderWindow window(sf::VideoMode(ResX, ResY), "SFML works!", sf::Style::None);
	window.setFramerateLimit(60);
	Player player;

	//sf::CircleShape shape(100.f);
	//shape.setFillColor(sf::Color::Green);
	/*
	int moveLeft = 0;
	int moveRight = 0;
	int moveUp = 0;
	int moveDown = 0;
	int moveSpeed = 8;
	*/
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		/*
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			moveLeft = 1;
		}
		else {
			moveLeft = 0;
		}
			
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			moveRight = 1;
		}
		else {
			moveRight = 0;		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			moveDown = 1;
		}
		else {
			moveDown = 0;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			moveUp = 1;
		}
		else {
			moveUp = 0;
		}

		if (moveRight) {
			shape.move(moveSpeed, 0);
		}
		else if (moveLeft) {
			shape.move(-moveSpeed, 0);
		}
		if (moveDown) {
			shape.move(0, moveSpeed);
		}
		else if (moveUp) {
			shape.move(0, -moveSpeed);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
			moveSpeed = 20;
		}
		else {
			moveSpeed = 8;
		}
		*/
		player.Update();
		window.clear();
		window.draw(player.shape);
		window.display();
	}
	return 0;

}