#include "Player.h"
#include <SFML/Graphics.hpp>
#define GRID_SIZE 32

Player::Player() :Entity(20, 20, GRID_SIZE, GRID_SIZE, sf::Color::Blue) {
	moveLeft = 0;
	moveRight = 0;
	moveUp = 0;
	moveDown = 0;
	topSpeed = 20;
	accel = 0.5f;
	velX = 0;
	velY = 0;
	nextX = 20;
	nextY = 20;
	prevX = 20;
	prevY = 20;
	speedMultiplier = 1;
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
		speedMultiplier = 2;
	}
	else {
		speedMultiplier = 1;
	}
}

void Player::Move() {
	shape.setPosition(nextX, nextY);
	if (moveRight) {
		velX += accel*speedMultiplier;
	}
	else if (moveLeft) {
		velX -= accel*speedMultiplier;
	}
	else {
		velX /= 1.1;
	}
	if (moveDown) {
		velY += accel*speedMultiplier;
	}
	else if (moveUp) {
		velY -= accel*speedMultiplier;
	}
	else {
		velY /= 1.5;
	}
	if (abs(velX) <= accel / 2) {
		velX = 0;
	}
	if (abs(velY) <= accel / 2) {
		velY = 0;
	}
	if (velX > topSpeed) {
		velX = topSpeed;
	}
	else if (velX < -topSpeed) {
		velX = -topSpeed;
	}
	if (velY > topSpeed) {
		velY = topSpeed;
	}
	else if (velY < -topSpeed) {
		velY = -topSpeed;
	}
	prevX = xPos;
	prevY = yPos;
	AlignPos();
	nextX = xPos+velX;
	nextY = yPos+velY;
}
void Player::Update(sf::RenderWindow &window) {
	
	CheckKeys();
	Move();
	window.draw(shape);
	
}

void Player::PlatformCollisionCheck(Platform plat) {

		AlignPos();
		

		
		if (prevY + height <= plat.yPos && nextY + height > plat.yPos && nextX < plat.xPos + plat.width && nextX + width > plat.xPos) {
			velY = 0;
			nextY = plat.yPos - height;
		}
		else if (prevY >= plat.yPos + height && nextY < plat.yPos + plat.height && nextX < plat.xPos + plat.width && nextX + width > plat.xPos) {
			velY = 0;
			nextY = plat.yPos + plat.height;
		}

		if (prevX + width <= plat.xPos && nextX + width > plat.xPos && nextY < plat.yPos + plat.height && nextY + height > plat.yPos) {
			velX = 0;
			nextX = plat.xPos - width;
		}
		else if (prevX >= plat.xPos + plat.width && nextX < plat.xPos + plat.width && nextY < plat.yPos + plat.height && nextY + height > plat.yPos) {
			velX = 0;
			nextX = plat.xPos + plat.width;
		}
	
}