#include "stdafx.h"
#include "../PrimeGenerator/PrimesGenerator.h"

#include <vector>
#include <set>
#include <sstream>
#include <iostream>
using namespace std;

BOOST_AUTO_TEST_SUITE(Prime_generator)
	BOOST_AUTO_TEST_CASE(Get_primes_vector)
	{
		int upperBound = 10;
		vector<bool> numbers;
		GetPrimesVector(upperBound, numbers);

		BOOST_CHECK(numbers[2]);
		BOOST_CHECK(numbers[3]);
		BOOST_CHECK(numbers[5]);
		BOOST_CHECK(numbers[7]);
	}

	BOOST_AUTO_TEST_CASE(Get_primes_set)
	{
		int upperBound = 3571;
		vector<bool> numbers;
		GetPrimesVector(upperBound, numbers);

		set<int> primes;
		GetPrimesSet(numbers, primes);

		BOOST_CHECK(primes.size() == 500);
	}

	BOOST_AUTO_TEST_CASE(Print_set)
	{
		int upperBound = 10;
		vector<bool> numbers;
		GetPrimesVector(upperBound, numbers);

		set<int> primes;
		GetPrimesSet(numbers, primes);

		stringstream stream;
		PrintSet(primes, stream);

		BOOST_CHECK(stream.str().compare("2 3 5 7 ") == 0);
	}
BOOST_AUTO_TEST_SUITE_END()