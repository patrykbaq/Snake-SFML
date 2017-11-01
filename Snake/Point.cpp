#include "Point.h"

Point::Point()
{
	do
	{
		xPoint = rand() % (Game::windowWidth - (int)pointSize);
		yPoint = rand() % (Game::windowHeight - (int)pointSize);
	} while (!(xPoint % 10 == 0 && yPoint % 10 == 0));
	point.setPosition(xPoint, yPoint);
	point.setSize(sf::Vector2f(pointSize, pointSize));
	point.setFillColor(sf::Color::Green);

}
void Point::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(point, states);
}

void Point::setPosition()
{
	do
	{
		xPoint = rand() % (Game::windowWidth - (int)pointSize);
		yPoint = rand() % (Game::windowHeight - (int)pointSize);
	} while (!(xPoint % 10 == 0 && yPoint % 10 == 0));
	point.setPosition(xPoint, yPoint);
}
float Point::left()
{
	return point.getPosition().x;
}
float Point::right()
{
	return point.getPosition().x + point.getSize().x;
}
float Point::top()
{
	return point.getPosition().y;
}
float Point::bottom()
{
	return point.getPosition().y + point.getSize().y;
}
