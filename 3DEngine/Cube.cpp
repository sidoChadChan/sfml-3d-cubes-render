#include "Cube.h"
#include "Project.h"
#include "Screen.h"
#include <math.h>
#include <iostream>

void Cube::Position(sf::Vector3f cords, float volume, float rotation, float speedZ) {
	vertexes.reserve(8);
	cubePoints.reserve(8);
	vertexes.clear();
	cubePoints.clear();
	for (size_t i = 0; i < totalVertexes; i++) {
		sf::CircleShape newVertex;
		newVertex.setRadius(radius);
		newVertex.setOrigin(newVertex.getGeometricCenter());
		vertexes.push_back(newVertex);
	}
	if (firstTime) {
		center = cords;
		firstTime = false;
	}
	center.z += addedZ;
	edge = std::cbrt(volume);
	float half = edge / 2;
	//Screen::fixedCoordinates(Project::Calculate(cords));
	//Pêtla for sprawia, ¿e koordynaty s¹ we wszystkich mo¿liwych 8 mo¿liwoœciach
	for (int i = -1; i <= 1; i+=2) {
		for (int j = -1; j <= 1; j += 2) {
			for (int k = -1; k <= 1; k += 2) {
				if (rotation > 0) {
					float rad = rotation / 180 * 3.141;
					newX = half * i * cos(rad) - half * k * sin(rad) + center.x;
					newZ = half * i * sin(rad) + half * k * cos(rad) + center.z;
				}
				else {
					newX = center.x + half * i;
					newZ = center.z + half * k;
				}
				cubePoints.emplace_back(
					sf::Vector3f({ newX, center.y + half * j, newZ })
				);
			}
		}
	}
}



sf::Vector3f Cube::Rotate(sf::Vector3f point, float speed){
	float newX = point.x * cos(speed) - point.z * sin(speed);
	float newZ = point.x * sin(speed) + point.z * cos(speed);
	return sf::Vector3f({ newX, point.y, newZ });
}

void Cube::Spawn() {
	Cube newCube;
	float randomX = -1.f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) / 2.0f);
	float randomY = -1.f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) / 2.0f);
	newCube.Position({ randomX,randomY,1 }, 0.001f, 0, 0.01f);
	cubes.push_back(newCube);
}

void Cube::TranslateZ() {
	for (size_t i = 0; i < cubePoints.size(); i++) {
		cubePoints[i].z += 0.01f;
	}

}

void Cube::DrawEdges(sf::RenderWindow& window) {
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
	for (size_t i = 0; i < vertexes.size(); i++) {
		vertexes[i].setRadius(radius);
		vertexes[i].setPosition(Screen::fixedCoordinates(Project::Calculate(cubePoints[i])));
		window.draw(vertexes[i]);
	}
}
