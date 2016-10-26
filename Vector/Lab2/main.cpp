// Lab2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Vector.h"

#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	vector<double> numbers;

	numbers = GetVector(cin);
	MultiplyByMin(numbers);
	SortVector(numbers);
	PrintVector(numbers, cout);

	return 0;
}