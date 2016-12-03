#include "stdafx.h"
#include "../Rationals/Rational.h"

#include <sstream>

using namespace std;

BOOST_AUTO_TEST_SUITE(Rationals)
	BOOST_AUTO_TEST_CASE(Initialization_and_Getters)
	{
		CRational zero;
		BOOST_CHECK(zero.GetNumerator() == 0 && zero.GetDenominator() == 1);

		CRational ten(10);
		BOOST_CHECK(ten.GetNumerator() == 10 && ten.GetDenominator() == 1);

		CRational tenToThree(10, 3);
		BOOST_CHECK(tenToThree.GetNumerator() == 10 && tenToThree.GetDenominator() == 3);

		CRational zeroDenominator(2, 0);
		BOOST_CHECK(zeroDenominator.GetNumerator() == 0 && zeroDenominator.GetDenominator() == 1);
	}
	BOOST_AUTO_TEST_CASE(To_double)
	{
		CRational fiveToThree(5, 3);
		BOOST_REQUIRE_CLOSE_FRACTION(fiveToThree.ToDouble(), 5 / 3, DBL_EPSILON);
	}
	BOOST_AUTO_TEST_CASE(Normalization)
	{
		CRational tenToFive(10, 5);
		BOOST_CHECK(tenToFive.GetNumerator() == 2 && tenToFive.GetDenominator() == 1);
	}
	BOOST_AUTO_TEST_CASE(Negative)
	{
		CRational neg(5, -3);
		BOOST_CHECK(neg.GetNumerator() == -5 && neg.GetDenominator() == 3);
	}
	BOOST_AUTO_TEST_SUITE(Operators)
		BOOST_AUTO_TEST_CASE(Unary_plus)
		{
			CRational rational(3, 5);
			rational = +rational;
			BOOST_CHECK(rational.GetNumerator() == 3 && rational.GetDenominator() == 5);
		}
		BOOST_AUTO_TEST_CASE(Unary_minus)
		{
			CRational rational(3, 5);
			rational = -rational;
			BOOST_CHECK(rational.GetNumerator() == -3 && rational.GetDenominator() == 5);
		}
		BOOST_AUTO_TEST_CASE(Binary_plus)
		{
			CRational first(1, 2);
			CRational second(1, 6);

			CRational result = first + second;
			BOOST_CHECK(result.GetNumerator() == 2 && result.GetDenominator() == 3);

			result = first + 1;
			BOOST_CHECK(result.GetNumerator() == 3 && result.GetDenominator() == 2);

			result = 1 + first;
			BOOST_CHECK(result.GetNumerator() == 3 && result.GetDenominator() == 2);
		}
		BOOST_AUTO_TEST_CASE(Binary_minus)
		{
			CRational first(1, 2);
			CRational second(1, 6);

			CRational result = first - second;
			BOOST_CHECK(result.GetNumerator() == 1 && result.GetDenominator() == 3);

			result = first - 1;
			BOOST_CHECK(result.GetNumerator() == -1 && result.GetDenominator() == 2);

			result = 1 - first;
			BOOST_CHECK(result.GetNumerator() == 1 && result.GetDenominator() == 2);
		}
		BOOST_AUTO_TEST_CASE(Plus_assign)
		{
			CRational first(1, 2);
			CRational second(1, 6);

			first += second;
			BOOST_CHECK(first.GetNumerator() == 2 && first.GetDenominator() == 3);

			first += 1;
			BOOST_CHECK(first.GetNumerator() == 5 && first.GetDenominator() == 3);
		}
		BOOST_AUTO_TEST_CASE(Minus_assign)
		{
			CRational first(1, 2);
			CRational second(1, 6);

			first -= second;
			BOOST_CHECK(first.GetNumerator() == 1 && first.GetDenominator() == 3);

			first -= 1;
			BOOST_CHECK(first.GetNumerator() == -2 && first.GetDenominator() == 3);
		}
		BOOST_AUTO_TEST_CASE(Multiply)
		{
			CRational first(1, 2);
			CRational second(2, 3);
			
			CRational result = first * second;
			BOOST_CHECK(result.GetNumerator() == 1 && result.GetDenominator() == 3);

			result = first * (-3);
			BOOST_CHECK(result.GetNumerator() == -3 && result.GetDenominator() == 2);

			result = 7 * second;
			BOOST_CHECK(result.GetNumerator() == 14 && result.GetDenominator() == 3);
		}
		BOOST_AUTO_TEST_CASE(Divide)
		{
			CRational first(1, 2);
			CRational second(2, 3);

			CRational result = first / second;
			BOOST_CHECK(result.GetNumerator() == 3 && result.GetDenominator() == 4);

			result = first / 5;
			BOOST_CHECK(result.GetNumerator() == 1 && result.GetDenominator() == 10);

			result = 7 / second;
			BOOST_CHECK(result.GetNumerator() == 21 && result.GetDenominator() == 2);
		}
		BOOST_AUTO_TEST_CASE(Multiply_assign)
		{
			CRational first(1, 2);
			CRational second(2, 3);

			first *= second;
			BOOST_CHECK(first.GetNumerator() == 1 && first.GetDenominator() == 3);

			first *= 3;
			BOOST_CHECK(first.GetNumerator() == 1 && first.GetDenominator() == 1);
		}
		BOOST_AUTO_TEST_CASE(Divide_assign)
		{
			CRational first(1, 2);
			CRational second(2, 3);

			first /= second;
			BOOST_CHECK(first.GetNumerator() == 3 && first.GetDenominator() == 4);

			first /= 3;
			BOOST_CHECK(first.GetNumerator() == 1 && first.GetDenominator() == 4);
		}
		BOOST_AUTO_TEST_CASE(Equal_and_not_equal)
		{
			CRational first(1, 2);
			BOOST_CHECK(first == first);

			CRational second(2, 3);
			BOOST_CHECK(first != second);

			CRational third(4, 1);
			BOOST_CHECK(third == 4);

			BOOST_CHECK(first != 7);

			CRational fourth(3, 1);
			BOOST_CHECK(3 == fourth);

			BOOST_CHECK(3 != second);
		}
		BOOST_AUTO_TEST_CASE(Less_lessOrEqual_Larger_largerOrEqual)
		{
			CRational first(1, 2);
			CRational second(1, 3);
			CRational third(3, 1);
			CRational fourth(7, 2);

			BOOST_CHECK(first >= second);
			BOOST_CHECK(third > 2);
			BOOST_CHECK(first < 7);
			BOOST_CHECK(3 <= fourth);
		}
		BOOST_AUTO_TEST_CASE(Streams)
		{
			CRational rational(5, 3);
			stringstream sstream;
			sstream << rational;

			CRational result;
			sstream >> result;
			BOOST_CHECK(result.GetNumerator() == 5 && result.GetDenominator() == 3);
		}
		BOOST_AUTO_TEST_CASE(Compound_fraction)
		{
			CRational rational(-9, 4);
			pair<int, CRational> result = rational.ToCompoundFraction();
			BOOST_CHECK(result.first == -2);
			BOOST_CHECK(result.second.GetNumerator() == -1 && result.second.GetDenominator() == 4);
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()