#pragma once
#include "Game.h"

class Point : public sf::Drawable
{
public:
	Point();
	~Point()=default;
	
	void setPosition();
	float left();
	float right();
	float top();
	float bottom();
private:
	int xPoint;
	int yPoint;

	float pointSize = 10.f;

	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	sf::RectangleShape point;
};

