#include <iostream>
#include <SFML/Graphics.hpp>
#include "Cube.h"
#include "Project.h"
#include <cstdlib>

int main()
{
	//Time for spawning cubes
    sf::Clock clock;
	//DeltaTime clock for FPS calculation
    sf::Clock dtClock;
    const sf::Time interval = sf::seconds(0.1f);
    srand(time(0));
	//Intializing cube manager
    Cube cube; 
    sf::RenderWindow window(sf::VideoMode({ 1920,1080 }), "");
    window.setFramerateLimit(60);
    while (window.isOpen()) {
        float deltaTime = dtClock.restart().asSeconds();
        window.setTitle("FPS, DeltaTime: "+std::to_string(1.f / deltaTime)+","+std::to_string(deltaTime));
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        if (clock.getElapsedTime() >= interval) {
            clock.restart();
            cube.Spawn();
        }
        window.clear(sf::Color::Black);
		//Drawing and translating all cubes
        for (size_t i = 0; i < cube.cubes.size(); i++) { 
            cube.cubes[i].TranslateZ();
            cube.cubes[i].Draw(window);
            cube.cubes[i].DrawEdges(window); 
        }
        window.display();
    }
}