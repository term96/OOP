// PrimeGenerator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>

using namespace std;

set<int> GeneratePrimeNumbersSet(int upperBound)
{
	vector<bool> numbers;
	set<int> primes;

	for (int i = 0; i <= upperBound; ++i)
	{
		if (i % 2 != 0)
			numbers.push_back(true);
		else
			numbers.push_back(false);
	}
	numbers[2] = true;
	primes.emplace(2);

	for (long long i = 3; i <= upperBound; ++i)
	{
		if (numbers[static_cast<unsigned int>(i)])
		{
			for (long long j = i * i; j <= upperBound; j += 2 * i)
			{
				numbers[static_cast<unsigned int>(j)] = false;
			}
			primes.emplace(i);
		}
	}

	return move(primes);
}

void PrintInt(int num)
{
	printf("%d", num);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		cout << "Неверное количество параметров.\n"
			<< "primegenerator.exe <upper bound>\n";
		return 1;
	}
	// TO DO: stoi
	int upperBound;
	cin >> upperBound;
	set<int> primes = GeneratePrimeNumbersSet(upperBound);
	for_each(primes.begin(), primes.end(), PrintInt);
    return 0;
}

