#pragma once

#include <set>
#include <vector>
#include <iostream>

void GetPrimesVector(int upperBound, std::vector<bool> &numbers);
void GetPrimesSet(std::vector<bool> &numbers, std::set<int> &primes);
void PrintSet(std::set<int> &set, std::ostream &stream = std::cout);