#include "Project.h"

sf::Vector2f Project::Calculate(sf::Vector3f coordinates) {
	//Perspective divide formula
	//x' = x/z
	//y' = y/z
	coordinates.x /= coordinates.z;
	coordinates.y /= coordinates.z;
	coordinates.x /= 1920.f / 1080.f;
	return sf::Vector2f({ coordinates.x, coordinates.y });
}