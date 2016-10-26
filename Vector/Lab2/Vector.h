#pragma once

#include <vector>

std::vector<double> GetVector(std::istream &stream);
void MultiplyByMin(std::vector<double> &numbers);
void PrintVector(std::vector<double> &numbers, std::ostream &stream);
void SortVector(std::vector<double> &numbers);