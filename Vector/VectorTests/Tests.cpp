#include "stdafx.h"
#include "../Lab2/Vector.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(Vector)
	BOOST_AUTO_TEST_CASE(reading_into_vector)
	{
		stringstream stream;
		stream << "2.5 10 6";
		vector<double> numbers = GetVector(stream);
		//BOOST_CHECK(numbers == {2.5, 10., 6.});
		BOOST_CHECK(numbers[0] == 2.5);
		BOOST_CHECK(numbers[1] == 10.);
		BOOST_CHECK(numbers[2] == 6.);
	}

	struct VectorFixture
	{
		vector<double> numbers;
		VectorFixture()
		{
			numbers = { 2.5, 10, 6 };
		}
	};

	BOOST_FIXTURE_TEST_SUITE(initialized_vector, VectorFixture)
		BOOST_AUTO_TEST_CASE(multiplying_by_minimal_element)
		{
			MultiplyByMin(numbers);
			BOOST_CHECK(numbers[0] == 6.25);
			BOOST_CHECK(numbers[1] == 25.);
			BOOST_CHECK(numbers[2] == 15.);
		}
		BOOST_AUTO_TEST_CASE(sorting)
		{
			SortVector(numbers);
			BOOST_CHECK(numbers[0] == 2.5);
			BOOST_CHECK(numbers[1] == 6.);
			BOOST_CHECK(numbers[2] == 10.);
		}
		BOOST_AUTO_TEST_CASE(printing)
		{
			stringstream stream;
			PrintVector(numbers, stream);
			string output;
			getline(stream, output);
			BOOST_CHECK(output == "2.500 10.000 6.000 ");
		}
	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()