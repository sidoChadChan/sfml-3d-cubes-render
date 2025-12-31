#pragma once
#include "SFML/Graphics.hpp"
#include <vector>

class Cube{
public:
	sf::CircleShape cube;
	std::vector<sf::CircleShape> vertices;
	std::vector<sf::Vector3f> cubePoints;
	std::vector<Cube> cubes;
private:
	sf::Vector3f center;
	int totalVertices = 8;
	float radius = 2.f;
	float edge = 0.f;
	float newX = 0.f;
	float newZ = 0.f;

public:
	void Position(sf::Vector3f cords, float volume, float rotation = 0.f, float speedZ = 0.f);
	void Draw(sf::RenderWindow& window);
	void DrawEdges(sf::RenderWindow& window);
	void Spawn();
	void TranslateZ();
};

