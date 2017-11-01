#include "Game.h"
#include <cstdlib>
#include <time.h>

template <class T1, class T2> bool isCollisionPoint(T1& A, T2& B)
{
	if (A.right() > B.left() && A.left() < B.right()
		&& A.bottom() > B.top() && A.top() < B.bottom())
	{
		A.addBody();
		B.setPosition();
		return true;
	}
	return false;
}

Game::Game()
{
	window.create(sf::VideoMode(windowWidth, windowHeight), "Snake by baq. Version 1.00");
	window.setFramerateLimit(60);
}

void Game::runGame()
{
	srand(time(NULL));

	Snake snake;
	Point point;

	sf::Font font;
	font.loadFromFile("data/DolceVita.ttf");
	sf::Text points;
	points.setFont(font);
	points.setString("POINTS: " + snake.pointsSnake());
	points.setPosition(sf::Vector2f(10.f, 365.f));
	points.setCharacterSize(25);
	points.setFillColor(sf::Color::White);

	sf::SoundBuffer buffer;
	buffer.loadFromFile("data/pointSound.ogg");
	sf::Sound sound;
	sound.setBuffer(buffer);

	sf::Clock clock;
	sf::Time time;
	clock.restart();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
				
			else if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					snake.setDirection(1);
					break;
				case sf::Keyboard::Down:
					snake.setDirection(2);
					break;
				case sf::Keyboard::Left:
					snake.setDirection(3);
					break;
				case sf::Keyboard::Right:
					snake.setDirection(4);
					break;
				}
			}

		}

		if (time.asMilliseconds() >= 100)
		{
			if (snake.collisionBody()) snake.again();
			snake.collisionWall();
			snake.move();
			clock.restart();
		}
		time = clock.getElapsedTime();
		
		if (isCollisionPoint(snake, point)) sound.play();
		points.setString("POINTS: " + snake.pointsSnake());
		window.draw(point);
		window.draw(snake);
		window.draw(points);
		window.display();
		window.clear();
	}
}

Game::~Game()
{
}
