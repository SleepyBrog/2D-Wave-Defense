#include "Player.h"
#include <SFML/Graphics.hpp>

Player::Player() :Entity(20, 20, 64, 64, sf::Color::Blue) {
	moveLeft = 0;
	moveRight = 0;
	moveUp = 0;
	moveDown = 0;
	moveSpeed = 8;
}

void Player::CheckKeys() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		moveLeft = 1;
	}
	else {
		moveLeft = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		moveRight = 1;
	}
	else {
		moveRight = 0;
	}

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


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
		moveSpeed = 20;
	}
	else {
		moveSpeed = 8;
	}
}

void Player::Move() {
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
}
void Player::Update() {
	
	CheckKeys();
	Move();

	
}