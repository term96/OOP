#include "stdafx.h"
#include "CCanvas.h"
#include <string>
#include <iostream>

using namespace sf;
using namespace std;

CCanvas::CCanvas(RenderWindow & window)
	:m_window(window)
{
}

void CCanvas::DrawLine(Point from, Point to, unsigned lineColor)
{
	VertexArray line(Lines, 2);
	line[0].position = Vector2f(static_cast<float>(from.x), static_cast<float>(from.y));
	line[1].position = Vector2f(static_cast<float>(to.x), static_cast<float>(to.y));

	line[0].color = Color(lineColor);
	line[1].color = Color(lineColor);

	m_window.draw(line);
}

void CCanvas::FillPolygon(std::vector<Point> points, unsigned fillColor)
{
	VertexArray array;
	switch (points.size())
	{
	case 3:
		array = VertexArray(Triangles, 3);
		break;
	case 4:
		array = VertexArray(Quads, 4);
		break;
	default:
		return;
	}

	for (unsigned int i = 0; i < points.size(); ++i)
	{
		array[i].position = Vector2f(static_cast<float>(points[i].x), static_cast<float>(points[i].y));
		array[i].color = Color(fillColor);
	}
	m_window.draw(array);
}

void CCanvas::DrawCircle(Point center, double radius, unsigned lineColor)
{
	CircleShape circle;
	circle.setPosition(center.x, center.y);
	circle.setRadius(static_cast<float>(radius));
	circle.setOutlineColor(Color(lineColor));

	m_window.draw(circle);
}

void CCanvas::FillCircle(Point center, double radius, unsigned fillColor)
{
	CircleShape circle;
	circle.setPosition(center.x, center.y);
	circle.setRadius(static_cast<float>(radius));
	circle.setFillColor(Color(fillColor));

	m_window.draw(circle);
}