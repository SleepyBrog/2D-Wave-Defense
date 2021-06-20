#include "Player.h"
#include "Platform.h"
#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <time.h>

#define INVUL_TIME 1

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
	maxHealth = currentHealth = 100;
	hitInvulnerable = 0;
	invulStartTime = clock();
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


	// Speed up acceleration - change this into a sort of dash, maybe higher topspeed as well?
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
		velX /= 1.04;
		//Just slowdown generally if nothing is pressed
	}
	if (moveDown) {
		velY += accel*speedMultiplier;
	}
	else if (moveUp) {
		velY -= accel*speedMultiplier;
	}
	else {
		velY /= 1.04;
		//Just slowdown generally if nothing is pressed
	}

	// Stop moving if velecity is close enough to zero - can't think of a way to have a player be precise enough to go to zero velocity otherwise
	if (abs(velX) <= accel / 2) {
		velX = 0;
	}
	if (abs(velY) <= accel / 2) {
		velY = 0;
	}

	// Cap movement speed
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

	// Next/Prev Pos systems are to make world collision more accurate - otherwise it'd be easy to phase into / pass through walls
	prevX = xPos;
	prevY = yPos;
	AlignPos();
	nextX = xPos+velX;
	nextY = yPos+velY;
}
void Player::PlatformCollisionCheck(Platform plat) {

			// Check if player is going to collide with wall, and then make his next postion outside of wall instead of inside, incase they are.
			// Didn't use built in function for this bc it didn't return where the collision was taking place, as well as the fact that I couldn't find a way to implement preemptive collisions with it

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

void Player::EnemyCollisionCheck(Enemy enemy) {

	if (shape.getGlobalBounds().intersects(enemy.shape.getGlobalBounds()) && !hitInvulnerable) {
		currentHealth -= enemy.attackDamage;
		invulStartTime = clock();
		printf("ye");

		// Trying out knockback - this is probably going to get revised
		float tempVelX = velX;
		float tempVelY = velY;
		velX += 4 * enemy.velX;
		velY += 4 * enemy.velY;
		enemy.velX += 4 * tempVelX;
		enemy.velY += 4 * tempVelY;
	}
}

void Player::NeedsToDie(void) {
	// Will be useful for more common things like enemies - just run a vector of them thorugh a for loop and if any of them are dead remove them
	if (currentHealth <= 0) {
		isAlive = 0;
	}
}

void Player::CheckInvul(void) {
	if ((clock() - invulStartTime) / CLOCKS_PER_SEC <= INVUL_TIME) {
		hitInvulnerable = 1;
	}
	else {
		hitInvulnerable = 0;
	}
}

void Player::Update(sf::RenderWindow &window) {

	CheckKeys();
	Move();
	CheckInvul();
	NeedsToDie();
	window.draw(shape);
}
