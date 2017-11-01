#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "Game.h"
#include <string>

class Snake : public sf::Drawable
{
public:
	Snake();
	~Snake()=default;

	void setDirection(int dir);
	void move();
	void addBody();
	float left();
	float right();
	float top();
	float bottom();
	void collisionWall();
	bool collisionBody();
	void again();
	std::string pointsSnake();
private:
	int direction=0;
	float directionX=0.f;
	float directionY=0.f;
	float sizeSnake = 10.f;

	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	std::vector<sf::RectangleShape> snake;
	sf::RectangleShape head;
};

