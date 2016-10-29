#include "stdafx.h"
#include "PrimesGenerator.h"

#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
#include <string>
#include <iterator>
#include <iostream>

using namespace std;

void GetPrimesVector(int upperBound, vector<bool> &primes)
{
	for (int i = 0; i <= upperBound; ++i)
	{
		if (i % 2 != 0)
			primes.push_back(true);
		else
			primes.push_back(false);
	}

	for (long long i = 3; i <= upperBound; ++i)
	{
		if (primes[static_cast<unsigned int>(i)])
		{
			for (long long j = i * i; j <= upperBound; j += 2 * i)
			{
				primes[static_cast<unsigned int>(j)] = false;
			}
		}
	}
}

void GetPrimesSet(vector<bool> &numbers, set<int> &primes)
{
	primes.emplace(2);

	for (unsigned int i = 3; i < numbers.size(); ++i)
	{
		if (numbers[i])
			primes.emplace(i);
	}
}

void PrintSet(set<int> &set, ostream &stream)
{
	copy(set.begin(), set.end(), ostream_iterator<int>(stream, " "));
}