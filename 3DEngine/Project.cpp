#include "Project.h"

sf::Vector2f Project::Calculate(sf::Vector3f coordinates) {
	coordinates.x /= coordinates.z;
	coordinates.y /= coordinates.z;
	coordinates.x /= 1920.f / 1080.f;
	return sf::Vector2f({ coordinates.x, coordinates.y });
}