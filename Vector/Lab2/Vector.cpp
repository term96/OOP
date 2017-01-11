#include "stdafx.h"
#include "Vector.h"

#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

// read numbers
std::vector<double> GetVector(std::istream & stream)
{
	return move(std::vector<double>(std::istream_iterator<double>(stream), std::istream_iterator<double>()));
}

void MultiplyByMin(std::vector<double> &numbers)
{
	double min = *(min_element(numbers.begin(), numbers.end()));
	for_each(numbers.begin(), numbers.end(), [min](double &num) { num *= min; });
}

void PrintVector(std::vector<double> &numbers, std::ostream &stream)
{
	stream << std::fixed << std::setprecision(3);
	copy(numbers.begin(), numbers.end(), std::ostream_iterator<double>(stream, " "));
}

void SortVector(std::vector<double> &numbers)
{
	sort(numbers.begin(), numbers.end());
}