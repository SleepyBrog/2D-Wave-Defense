#include "Entity.h"
#include <SFML/Graphics.hpp>
Entity::Entity(int xPos, int yPos, float w, float h, sf::Color color) {
	shape.setSize(sf::Vector2f(w, h));
	shape.setPosition(xPos, yPos);
	shape.setFillColor(color);
	width = w;
	height = h;
}

void Entity::AlignPos(void) {
	float x = shape.getPosition().x;
	float y = shape.getPosition().y;

	xPos = x;
	yPos = y;

	needsToDie = 0;
}