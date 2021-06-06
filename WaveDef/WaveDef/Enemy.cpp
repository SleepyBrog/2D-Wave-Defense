#include "Enemy.h"
#include "Player.h"
#include <cmath>


Enemy::Enemy(int xPos, int yPos, float width, float height, float speed, float acceleration, Player *target) :Entity(xPos, yPos, width, height, sf::Color::Red) {
	accel = acceleration;
	topSpeed = speed;
	velX = 0;
	velY = 0;
	prevX = nextX = xPos;
	prevY = nextY = yPos;
	speedMultiplier = 1.0f;
	focus = target;
	topXSpeed = topYSpeed = 0;
	attackDamage = 10;
}
void Enemy::Update(sf::RenderWindow &window) {
	Move();
	window.draw(shape);
}

void Enemy::Move() {
	shape.setPosition(nextX, nextY);
	AlignPos();
	float difX = float(focus->xPos - xPos);

	float difY = float(focus->yPos - yPos);
	float distance = sqrt(pow(difX,2) + pow(difY,2));

	if (!(abs(distance) < 0.1f)) {
		topXSpeed = (difX / distance) * topSpeed;
		topYSpeed = (difY / distance) * topSpeed;
			//This weird directional acceleration thing was a bad idea
			//topXAccel = abs(difX / distance) * accel;
			//topYAccel = abs(difY / distance) * accel;
	}
	else {
		topXSpeed = topYSpeed = 0;
	}

	if (difX < 0) {
		velX -= accel;
	}
	else {
		velX += accel;
	}
	if (difY < 0) {
		velY -= accel;
	}
	else
	{
		velY += accel;
	}
	
	if (abs(velX) > abs(topXSpeed) && velX/topXSpeed > 0) {
		velX -= (abs(velX) / velX) *  accel;
	}
	if (abs(velY) > abs(topYSpeed) && velY/topYSpeed > 0) {
		velY -= (abs(velY)/velY) * accel;
	}

	prevX = xPos;
	prevY = yPos;
	nextX = xPos + velX;
	nextY = yPos + velY;
}

void Enemy::PlatformCollisionCheck(Platform plat) {

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