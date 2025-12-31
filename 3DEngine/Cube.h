#pragma once
#include "SFML/Graphics.hpp"
#include <vector>

class Cube{
//Vectors
public:
	std::vector<sf::CircleShape> vertexes;
	std::vector<sf::Vector3f> cubePoints;
	std::vector<Cube> cubes;
public:
	sf::CircleShape cube;
public:
	sf::Vector3f center;
	int totalVertexes = 8;
	float radius = 2.f;
	float edge = 0.f;
	float newX = 0;
	float newZ = 0;
	bool keyDown = false;
	bool firstTime = true;
	float addedZ = 0.f;


public:
	void Position(sf::Vector3f cords, float volume, float rotation = 0.f, float speedZ = 0.f);
	static sf::Vector3f Rotate(sf::Vector3f point, float speed);
	void Draw(sf::RenderWindow& window);
	void DrawEdges(sf::RenderWindow& window);
	void Spawn();
	void TranslateZ();
};

