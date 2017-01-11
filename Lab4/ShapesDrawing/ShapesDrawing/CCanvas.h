#pragma once
#include "Canvas.h"
#include "SFML\Graphics.hpp"
#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include <vector>

class CCanvas :
	public ICanvas
{
public:
	CCanvas(sf::RenderWindow & window);

	void DrawLine(Point from, Point to, unsigned lineColor);
	void FillPolygon(std::vector<Point> points, unsigned fillColor);
	void DrawCircle(Point center, double radius, unsigned lineColor);
	void FillCircle(Point center, double radius, unsigned fillColor);

private:
	sf::RenderWindow & m_window;
};

