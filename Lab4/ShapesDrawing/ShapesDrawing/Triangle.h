#pragma once
#include "ISolidShape.h"
#include "Point.h"
#include <string>
#include <iostream>
#include <vector>

class CTriangle :
	public ISolidShape
{
public:
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	std::string GetOutlineColor() const override;

	std::string GetFillColor() const;

	void SetProperties(std::istream & stream);

	Point GetVertex1() const;
	Point GetVertex2() const;
	Point GetVertex3() const;

	void Draw(ICanvas & canvas) override;

	~CTriangle() = default;
private:
	double GetSideLength(Point const& vertex1, Point const& vertex2) const;

	Point m_vertex1;
	Point m_vertex2;
	Point m_vertex3;
	std::string m_outlineColor;
	std::string m_fillColor;
};

