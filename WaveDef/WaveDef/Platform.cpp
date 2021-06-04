#include "Platform.h"

Platform::Platform(int xPos, int yPos, float width, float height, int passthrough) :Entity(xPos, yPos, width, height, sf::Color::Green) {
	passthrough = passthrough;
	AlignPos();
}