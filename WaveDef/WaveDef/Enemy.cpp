#include "Enemy.h"
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
	topXSpeed = topXAccel = topYAccel = topYSpeed = 0;
}
void Enemy::Update(sf::RenderWindow &window) {
	Move();
	window.draw(shape);
}

void Enemy::Move() {
	shape.setPosition(nextX, nextY);
	float difX = float(focus->xPos - xPos);
	float difY = float(focus->yPos - yPos);
	float distance = sqrt(pow(difX,2) + pow(difY,2));
	if (!(abs(distance) < 0.1f)) {
		topXSpeed = (difX / distance) * topSpeed;
		topYSpeed = (difY / distance) * topSpeed;
		topXAccel = abs(difX / distance) * accel;
		topYAccel = abs(difY / distance) * accel;

		printf("%f %f \n", topXSpeed, topXAccel);
	}
	else {
		topXSpeed = topXAccel = topYAccel = topYSpeed = 0;
	}
	


	if (topXSpeed <= 0) {
		velX -= topXAccel;
	}
	else {
		velX += topXAccel;
	}
	if (topYSpeed <= 0) {
		velY -= topYAccel;
	}
	else
	{
		velY += topYAccel;
	}

	if(velX > topXSpeed) {
		velX -= topXAccel * (velX - topXSpeed)/10;
	}
	else if (velX < -topXSpeed) {
		velX -= topXAccel * (velX + topXSpeed) / 10;
	}
	if (velY > topYSpeed) {
		velY -= topYAccel * (velY - topYSpeed)/10;
	}
	else if (velY < -topYSpeed) {
		velY -= topYAccel * (velY + topYSpeed) / 10;
	}

	prevX = xPos;
	prevY = yPos;
	AlignPos();
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
		printf("%d %d \n", prevY, nextY);
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