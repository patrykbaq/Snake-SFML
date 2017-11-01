#include "Snake.h"


Snake::Snake()
{
	head.setPosition(Game::windowWidth / 2, Game::windowHeight / 2);
	head.setSize(sf::Vector2f(sizeSnake, sizeSnake));
	head.setFillColor(sf::Color::Blue);
	snake.push_back(head);
}

void Snake::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	for (unsigned int i = 0; i < snake.size(); i++)
	{
	target.draw(snake[i], states);
	}
}

void Snake::setDirection(int dir)
{
	switch (dir)
	{
	case 1: //up
		if (direction != 2)
		{
			direction = 1;
			directionX = 0.f;
			directionY = -10.f;
		}
		break;
	case 2: //down
		if (direction != 1)
		{
			direction = 2;
			directionX = 0.f;
			directionY = 10.f;
		}
		break;
	case 3: //left
		if (direction != 4)
		{
			direction = 3;
			directionX = -10.f;
			directionY = 0.f;
		}
		break;
	case 4: //right
		if (direction != 3)
		{
			direction = 4;
			directionX = 10.f;
			directionY = 0.f;
		}
		break;
	}
}

void Snake::move()
{	
	sf::Vector2f prevPos = snake[0].getPosition();
	snake[0].setPosition(snake[0].getPosition().x + directionX, snake[0].getPosition().y + directionY);
	for (unsigned int i = 1; i < snake.size(); i++)
	{
	sf::Vector2f tmp = snake[i].getPosition();
	snake[i].setPosition(prevPos);
	prevPos = tmp;
	}
}

void Snake::addBody()
{
	sf::RectangleShape body;
	body.setSize(sf::Vector2f(sizeSnake, sizeSnake));
	body.setFillColor(sf::Color::White);
	snake.push_back(body);
}
float Snake::left()
{
	return snake[0].getPosition().x;
}
float Snake::right()
{
	return snake[0].getPosition().x + snake[0].getSize().x;
}
float Snake::top()
{
	return snake[0].getPosition().y;
}
float Snake::bottom()
{
	return snake[0].getPosition().y + snake[0].getSize().y;
}

void Snake::collisionWall()
{
	if (snake[0].getPosition().x > Game::windowWidth) snake[0].setPosition(sf::Vector2f(0.f, snake[0].getPosition().y));
	else if (snake[0].getPosition().x < 0) snake[0].setPosition(sf::Vector2f(Game::windowWidth, snake[0].getPosition().y));
	else if (snake[0].getPosition().y > Game::windowHeight) snake[0].setPosition(sf::Vector2f(snake[0].getPosition().x, 0.f));
	else if (snake[0].getPosition().y < 0) snake[0].setPosition(sf::Vector2f(snake[0].getPosition().x, Game::windowHeight));
}

bool Snake::collisionBody()
{
	for (unsigned int i = 1; i < snake.size(); i++)
	{
		if (snake[0].getPosition() == snake[i].getPosition()) return true;
	}
	return false;
}

void Snake::again()
{
	snake.clear();
	snake.push_back(head);
}

std::string Snake::pointsSnake()
{
	std::string str = std::to_string(snake.size()-1);
	return str;
}