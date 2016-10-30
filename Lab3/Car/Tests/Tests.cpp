#include "stdafx.h"
#include "../Car/Car.h"

using namespace std;

struct CarFixture
{
	CCar car;
};

BOOST_FIXTURE_TEST_SUITE(Car_test, CarFixture);
BOOST_AUTO_TEST_CASE(Car_is_at_rest_after_turning_engine_on)
{
	BOOST_CHECK(!car.IsEngineOn());
	BOOST_CHECK(car.TurnOnEngine());
	BOOST_CHECK(car.IsEngineOn());
	
	BOOST_CHECK(car.GetDirection() == Direction::AT_REST);
	BOOST_CHECK(car.GetSpeed() == 0);
	BOOST_CHECK(car.GetGear() == 0);
}
BOOST_AUTO_TEST_SUITE_END()