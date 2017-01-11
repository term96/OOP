#include "stdafx.h"
#include "Point.h"


Point::Point(double pointX, double pointY)
{
	x = pointX;
	y = pointY;
}

Point::Point(const Point & point)
{
	x = point.x;
	y = point.y;
}
