#include "Platform.h"

Platform::Platform(int xPos, int yPos, float width, float height, int sol) :Entity(xPos, yPos, width, height, sf::Color::Green) {
	solid = sol;
	AlignPos();
}