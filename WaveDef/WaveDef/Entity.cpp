#include "Entity.h"
#include <SFML/Graphics.hpp>
Entity::Entity(int xPos, int yPos, int width, int height, sf::Color color) {
	shape.setSize(sf::Vector2f(width, height));
	shape.setPosition(xPos, yPos);
	shape.setFillColor(color);
}