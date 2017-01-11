#pragma once

#include "Shape.h"
#include "Point.h"

class CLineSegment :
	public IShape
{
public:
	CLineSegment() = default;

	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	std::string GetOutlineColor() const override;

	Point GetStartPoint() const;
	Point GetEndPoint() const;

	void SetProperties(std::istream & stream);

	void Draw(ICanvas & canvas) override;

	~CLineSegment() = default;
private:
	Point m_startPoint;
	Point m_endPoint;
	std::string m_outlineColor;
};

