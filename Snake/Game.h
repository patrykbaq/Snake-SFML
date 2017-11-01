#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include <SFML\Audio.hpp>
#include "Point.h"
#include "Snake.h"
#include <iostream>

class Game
{
public:
	Game();
	~Game();

	static const int windowWidth = 400;
	static const int windowHeight = 400;

	void runGame();
private:
	sf::RenderWindow window;
};

