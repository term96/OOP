// PrimeGenerator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
#include <string>

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
		printf("Ќеверное количество параметров.\nprimegenerator.exe <upper bound>\n");
		return 1;
	}
	int upperBound;
	try
	{
		upperBound = stoi(argv[1]);
	}
	catch (...)
	{
		printf("<upper bound> - целое число от 2 до 100 000 000");
		return 1;
	}
	
	set<int> primes = GeneratePrimeNumbersSet(upperBound);
	for_each(primes.begin(), primes.end(), PrintInt);
	printf("%d", primes.size());
    return 0;
}

