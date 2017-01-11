#pragma once
#include "ISolidShape.h"
#include "Point.h"
#include <iostream>
#include <string>
#include <vector>

class CRectangle :
	public ISolidShape
{
public:
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	std::string GetOutlineColor() const override;

	std::string GetFillColor() const;

	Point GetLeftTop() const;
	Point GetRightBottom() const;
	double GetWidth() const;
	double GetHeight() const;

	void SetProperties(std::istream & stream);

	void Draw(ICanvas & canvas) override;

	~CRectangle() = default;

private:
	Point m_leftTop;
	Point m_rightBottom;
	std::string m_outlineColor;
	std::string m_fillColor;
	double m_width;
	double m_height;
};

