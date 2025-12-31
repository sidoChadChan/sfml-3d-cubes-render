#include "Screen.h"

sf::Vector2f Screen::fixedCoordinates(sf::Vector2f p){
	//Transforming coordinates from range -1 to 1 to screen coordinates 0 to 1920 and 0 to 1080
	p.x = (p.x+1)/2*1920;
	p.y = (1-(p.y + 1)/2)*1080;
	return sf::Vector2f({ p.x, p.y });
}