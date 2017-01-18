#include "stdafx.h"
#include "..\FindMaxEx\FindMaxEx.h"
#include <vector>

using namespace std;

struct Sportsman
{
	Sportsman(string const & fullname, int height, int weight)
	{
		m_fullname = fullname;
		m_height = height;
		m_weight = weight;
	}
	Sportsman() = default;
	string m_fullname;
	int m_height;
	int m_weight;
};
	
bool AreEqual(Sportsman const & first, Sportsman const & second)
{
	return first.m_fullname.compare(second.m_fullname) == 0
		&& first.m_height == second.m_height
		&& first.m_weight == second.m_weight;
}

BOOST_AUTO_TEST_SUITE(FindMaxEx)
	Sportsman maxWeight("Дима", 180, 72);
	Sportsman maxHeight("Костя", 185, 70);
	Sportsman maxFullname("Петя", 175, 67);
	vector<Sportsman> sportsmans = { maxWeight, maxHeight, maxFullname };
	BOOST_AUTO_TEST_CASE(Find_max_string)
	{
		vector<string> arr = { "Andrei", "Sergei", "Boris" };
		string max;
		FindMax(arr, max);
		BOOST_CHECK_EQUAL(max, "Sergei");
	}
	BOOST_AUTO_TEST_CASE(Find_max_int)
	{
		vector<int> arr = { 30, 40, 50 };
		int max;
		FindMax(arr, max);
		BOOST_CHECK_EQUAL(max, 50);
	}
	BOOST_AUTO_TEST_CASE(Find_max_double)
	{
		vector<double> arr = { 100.23, 40, 50.93 };
		double max;
		FindMax(arr, max);
		BOOST_CHECK_CLOSE_FRACTION(max, 100.23, DBL_EPSILON);
	}
	BOOST_AUTO_TEST_CASE(Find_sportsman_with_max_weight)
	{
		Sportsman max;
		FindMax(sportsmans, max, [](Sportsman const & left, Sportsman const & right) {
			return left.m_weight < right.m_weight; });
		BOOST_CHECK(AreEqual(max, maxWeight));
	}
	BOOST_AUTO_TEST_CASE(Find_sportsman_with_max_height)
	{
		Sportsman max;
		FindMax(sportsmans, max, [](Sportsman const & left, Sportsman const & right) {
			return left.m_height < right.m_height; });
		BOOST_CHECK(AreEqual(max, maxHeight));
	}
	BOOST_AUTO_TEST_CASE(Find_sportsman_with_max_fullname)
	{
		Sportsman max;
		FindMax(sportsmans, max, [](Sportsman const & left, Sportsman const & right) {
			return left.m_fullname.compare(right.m_fullname) < 0; });
		BOOST_CHECK(AreEqual(max, maxFullname));
	}
BOOST_AUTO_TEST_SUITE_END()