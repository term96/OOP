#pragma once

// Named "Point" because "CPoint" is reserved

class Point
{
public:
	Point(double pointX, double pointY);
	Point(const Point & point);
	Point() = default;

	double x;
	double y;
};

