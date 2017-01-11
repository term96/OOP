// Canvas.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LineSegment.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "CCanvas.h"
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"

#include <vector>
#include <sstream>
#include <Windows.h>

using namespace std;
using namespace sf;

void Redraw(vector<IShape *> & drawables, ICanvas & canvas, RenderWindow & window)
{
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();
	}

	window.clear(Color::White);
	for (auto drawable : drawables)
	{
		drawable->Draw(canvas);
	}
	window.display();
}

void ReadFromStream(std::vector<IShape *> & shapes, ICanvas & canvas, RenderWindow & window, std::istream & stream = cin)
{
	std::string shapeType;
	while (stream >> shapeType)
	{
		if (shapeType.compare("linesegment") == 0)
		{
			CLineSegment * lineSegment = new CLineSegment;
			lineSegment->SetProperties(stream);
			shapes.push_back(lineSegment);
			lineSegment->Draw(canvas);
		}
		if (shapeType.compare("rectangle") == 0)
		{
			CRectangle * rectangle = new CRectangle;
			rectangle->SetProperties(stream);
			shapes.push_back(rectangle);
			rectangle->Draw(canvas);
		}
		if (shapeType.compare("triangle") == 0)
		{
			CTriangle * triangle = new CTriangle;
			triangle->SetProperties(stream);
			shapes.push_back(triangle);
			triangle->Draw(canvas);
		}
		if (shapeType.compare("circle") == 0)
		{
			CCircle * circle = new CCircle;
			circle->SetProperties(stream);
			shapes.push_back(circle);
			circle->Draw(canvas);
		}
		Redraw(shapes, canvas, window);
	}
}

void FindMinPerimeter(std::vector<IShape *> & shapes, std::ostream & stream = cout)
{
	double minPerimeter = DBL_MAX;
	double perimeter;
	IShape * shape = nullptr;
	for (auto iter : shapes)
	{
		perimeter = iter->GetPerimeter();
		if (minPerimeter > perimeter)
		{
			minPerimeter = perimeter;
			shape = iter;
		}
	}

	if (shape != nullptr)
		stream << "Shape with min perimeter:\n" << shape->ToString() << "\n";
}

void FindMaxArea(std::vector<IShape *> & shapes, std::ostream & stream = cout)
{
	double maxArea = 0;
	double area;
	IShape * shape = nullptr;
	for (auto iter : shapes)
	{
		area = iter->GetArea();
		if (maxArea < area)
		{
			maxArea = area;
			shape = iter;
		}
	}

	if (shape != nullptr)
		stream << "Shape with max area:\n" << shape->ToString() << "\n";
}

int main()
{
	SetConsoleOutputCP(1251);

	RenderWindow window(VideoMode(800, 600), "Canvas", Style::Default | Style::Close);
	CCanvas canvas(window);
	vector<IShape *> shapes;

	ReadFromStream(shapes, canvas, window);
	FindMinPerimeter(shapes);
	FindMaxArea(shapes);

	while (window.isOpen())
	{
		Redraw(shapes, canvas, window);
	}
    return 0;
}

