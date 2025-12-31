#include "Screen.h"

sf::Vector2f Screen::fixedCoordinates(sf::Vector2f p){
	p.x = (p.x+1)/2*1920;
	p.y = (1-(p.y + 1)/2)*1080;
	return sf::Vector2f({ p.x, p.y });
}