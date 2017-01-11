#include "stdafx.h"
#include "Triangle.h"
#include <math.h>

using namespace std;

void CTriangle::SetProperties(std::istream & stream)
{
	stream >> m_vertex1.x >> m_vertex1.y;
	stream >> m_vertex2.x >> m_vertex2.y;
	stream >> m_vertex3.x >> m_vertex3.y;
	stream >> m_outlineColor >> m_fillColor;
}

double CTriangle::GetArea() const
{
	double a = GetSideLength(m_vertex1, m_vertex2);
	double b = GetSideLength(m_vertex2, m_vertex3);
	double c = GetSideLength(m_vertex3, m_vertex1);
	double p = GetPerimeter() / 2;

	return sqrt(p * (p - a) * (p - b) * (p - c));
}

double CTriangle::GetPerimeter() const
{
	double side1 = GetSideLength(m_vertex1, m_vertex2);
	double side2 = GetSideLength(m_vertex2, m_vertex3);
	double side3 = GetSideLength(m_vertex3, m_vertex1);
	return side1 + side2 + side3;
}

std::string CTriangle::ToString() const
{
	string information;
	information = "Triangle A:" + to_string(GetArea())
		+ " P:" + to_string(GetPerimeter())
		+ " OC:" + m_outlineColor + " FC:" + m_fillColor
		+ " V1(" + to_string(m_vertex1.x) + " " + to_string(m_vertex1.y)
		+ ") V2(" + to_string(m_vertex2.x) + " " + to_string(m_vertex2.y)
		+ ") V3(" + to_string(m_vertex3.x) + " " + to_string(m_vertex3.y) + ")";
	return move(information);
}

std::string CTriangle::GetOutlineColor() const
{
	return m_outlineColor;
}

std::string CTriangle::GetFillColor() const
{
	return m_fillColor;
}

Point CTriangle::GetVertex1() const
{
	return m_vertex1;
}

Point CTriangle::GetVertex2() const
{
	return m_vertex2;
}

Point CTriangle::GetVertex3() const
{
	return m_vertex3;
}

void CTriangle::Draw(ICanvas & canvas)
{
	vector<Point> points = { m_vertex1, m_vertex2, m_vertex3 };
	int color = stoi(m_fillColor, nullptr, 16);
	canvas.FillPolygon(points, color);
}

double CTriangle::GetSideLength(Point const & vertex1, Point const & vertex2) const
{
	return sqrt(pow(vertex1.x - vertex2.x, 2) + pow(vertex1.y - vertex2.y, 2));
}
