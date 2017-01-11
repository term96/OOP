#pragma once

#include "Point.h"
#include <string>
#include <vector>

class ICanvas
{
public:
	virtual void DrawLine(Point from, Point to, unsigned lineColor) = 0;
	virtual void FillPolygon(std::vector<Point>, unsigned fillColor) = 0;
	virtual void DrawCircle(Point center, double radius, unsigned lineColor) = 0;
	virtual void FillCircle(Point center, double radius, unsigned fillColor) = 0;
};