// Lab2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

void ReadIntoVector(vector<double> &numbers)
{
	double number;
	while (cin >> number)
	{
		numbers.push_back(number);
	}
}

void HandleVector(vector<double> &numbers)
{
	double min = *min_element(numbers.begin(), numbers.end());
	vector<double>::iterator it;

	for (it = numbers.begin(); it != numbers.end(); ++it)
	{
		*it = *it * min;
	}
}

void PrintVector(vector<double> &numbers)
{
	vector<double>::iterator it;
	for (it = numbers.begin(); it != numbers.end(); ++it)
	{
		cout << fixed << setprecision(3) << *it << " ";
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<double> numbers;

	ReadIntoVector(numbers);
	HandleVector(numbers);
	sort(numbers.begin(), numbers.end());
	PrintVector(numbers);

	return 0;
}