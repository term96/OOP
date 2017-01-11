#include "stdafx.h"
#include "Rectangle.h"

using namespace std;

double CRectangle::GetArea() const
{
	return m_width * m_height;
}

double CRectangle::GetPerimeter() const
{
	return 2 * (m_width + m_height);
}

std::string CRectangle::ToString() const
{
	string information;
	information = "Rectangle A:" + to_string(GetArea())
		+ " P:" + to_string(GetPerimeter())
		+ " OC:" + m_outlineColor + " FC:" + m_fillColor
		+ " LT(" + to_string(m_leftTop.x) + " " + to_string(m_leftTop.y)
		+ ") RB(" + to_string(m_rightBottom.x) + " " + to_string(m_rightBottom.y)
		+") W:" + to_string(m_width) + " H:" + to_string(m_height);
	return move(information);
}

std::string CRectangle::GetOutlineColor() const
{
	return m_outlineColor;
}

std::string CRectangle::GetFillColor() const
{
	return m_fillColor;
}

Point CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

Point CRectangle::GetRightBottom() const
{
	return m_rightBottom;
}

double CRectangle::GetWidth() const
{
	return m_width;
}

double CRectangle::GetHeight() const
{
	return m_height;
}

void CRectangle::SetProperties(std::istream & stream)
{
	stream >> m_leftTop.x >> m_leftTop.y;
	stream >> m_width >> m_height;
	stream >> m_outlineColor >> m_fillColor;
	m_rightBottom.x = m_leftTop.x + m_width;
	m_rightBottom.y = m_leftTop.y + m_height;
}

void CRectangle::Draw(ICanvas & canvas)
{
	Point rightTop;
	Point leftBottom;
	rightTop.x = m_rightBottom.x;
	rightTop.y = m_leftTop.y;
	leftBottom.x = m_leftTop.x;
	leftBottom.y = m_rightBottom.y;
	vector<Point> points = { m_leftTop, rightTop, m_rightBottom, leftBottom };
	int color = stoi(m_fillColor, nullptr, 16);
	canvas.FillPolygon(points, color);
}
