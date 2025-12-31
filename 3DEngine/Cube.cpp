#include "Cube.h"
#include "Project.h"
#include "Screen.h"
#include <math.h>
#include <iostream>

void Cube::Position(sf::Vector3f cords, float volume, float rotation, float speedZ) {
	vertices.reserve(8);
	cubePoints.reserve(8);
	vertices.clear();
	cubePoints.clear();
	for (size_t i = 0; i < totalVertices; i++) {
		sf::CircleShape newVertex;
		newVertex.setRadius(radius);
		newVertex.setOrigin(newVertex.getGeometricCenter());
		vertices.push_back(newVertex);
	}
	center = cords;
	//3rd degree root of volue to get edge length
	edge = std::cbrt(volume);
	//Divding edge by 2 to get vertex distance from center
	float half = edge / 2;
	//Loop generates 8 possible points of cube
	for (int i = -1; i <= 1; i+=2) {
		for (int j = -1; j <= 1; j += 2) {
			for (int k = -1; k <= 1; k += 2) {
				if (rotation > 0) {
					//Converting rotation from degrees to radians with formula
					float rad = rotation / 180 * 3.141;
					newX = half * i * cos(rad) - half * k * sin(rad) + center.x;
					newZ = half * i * sin(rad) + half * k * cos(rad) + center.z;
				}
				else {
					newX = center.x + half * i;
					newZ = center.z + half * k;
				}
				//Saving calculated point to vector
				cubePoints.push_back(
					sf::Vector3f({ newX, center.y + half * j, newZ })
				);
			}
		}
	}
}

void Cube::TranslateZ() {
	//Moving cube forward Z axis
	for (size_t i = 0; i < cubePoints.size(); i++) {
		cubePoints[i].z += 0.01f;
	}

}

void Cube::DrawEdges(sf::RenderWindow& window) {
	//Connecting edges between corresponding vertices
	const int edges[12][2] = {
		{0,1},{1,3},{3,2},{2.0},
		{4,5},{5,7},{7,6},{6,4},
		{0,4},{1,5},{2,6},{3,7}
	};
	for (size_t i = 0; i < 12; i++) {
		int a = edges[i][0];
		int b = edges[i][1];
		sf::Vertex line[] = {
			sf::Vertex(Screen::fixedCoordinates(Project::Calculate(cubePoints[a]))),
			sf::Vertex(Screen::fixedCoordinates(Project::Calculate(cubePoints[b])))
		};
		window.draw(line, 2, sf::PrimitiveType::Lines);
	}
}

void Cube::Draw(sf::RenderWindow& window) {
	radius = radius * 1.f/(center.z + 0.005f);
	for (size_t i = 0; i < vertices.size(); i++) {
		vertices[i].setRadius(radius);
		vertices[i].setPosition(Screen::fixedCoordinates(Project::Calculate(cubePoints[i])));
		window.draw(vertices[i]);
	}
}

void Cube::Spawn() {
	//Spawning cube at random X and Y position
	Cube newCube;
	//Random position between -1 and 1
	float randomX = -1.f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) / 2.0f);
	float randomY = -1.f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) / 2.0f);
	newCube.Position({ randomX,randomY,1 }, 0.001f, 0, 0.01f);
	cubes.push_back(newCube);
}