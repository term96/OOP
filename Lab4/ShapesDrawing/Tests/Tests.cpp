#include "stdafx.h"
#include "../ShapesDrawing/LineSegment.h"
#include "../ShapesDrawing/Rectangle.h"
#include "../ShapesDrawing/Triangle.h"
#include "../ShapesDrawing/Circle.h"

#include <sstream>
#include <vector>

using namespace std;

BOOST_AUTO_TEST_SUITE(Canvas)
BOOST_AUTO_TEST_CASE(LineSegment)
{
	stringstream isstream("linesegment 400 120 450 120 ff00ff");
	CLineSegment line;
	line.SetProperties(isstream);
	BOOST_CHECK_EQUAL(line.GetPerimeter(), 50., DBL_EPSILON);
	BOOST_CHECK_EQUAL(line.GetOutlineColor, "ff00ff");
}
BOOST_AUTO_TEST_CASE(Circle)
{
	stringstream isstream("circle 100 50 50 331234 471356");
	CCircle circle;
	circle.SetProperties(isstream);
	BOOST_CHECK_EQUAL(circle.GetPerimeter(), M_PI, DBL_EPSILON);
	BOOST_CHECK_EQUAL(circle.GetOutlineColor, "ff00ff");
}
BOOST_AUTO_TEST_SUITE_END()