#pragma once
#include "ISolidShape.h"
#include "Point.h"
#include <string>
#include <iostream>

class CCircle :
	public ISolidShape
{
public:
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	std::string GetOutlineColor() const override;

	std::string GetFillColor() const;

	Point GetCenter() const;
	double GetRadius() const;

	void SetProperties(std::istream & stream);

	void Draw(ICanvas & canvas) override;

	~CCircle() = default;

private:
	Point m_center;
	double m_radius;
	std::string m_outlineColor;
	std::string m_fillColor;
};

