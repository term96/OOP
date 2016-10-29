// PrimeGenerator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "PrimesGenerator.h"
#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

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
	
	vector<bool> numbers;
	GetPrimesVector(upperBound, numbers);

	set<int> primes;
	GetPrimesSet(numbers, primes);

	printf("%d", primes.size());
	//PrintSet(primes);
    return 0;
}

