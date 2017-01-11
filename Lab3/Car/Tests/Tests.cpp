#include "stdafx.h"
#include "../Car/Car.h"

using namespace std;

struct CarFixture
{
	CCar car;
};

struct CarWithEngineOn : CarFixture
{
	CarWithEngineOn()
	{
		car.TurnOnEngine();
	}
};

BOOST_FIXTURE_TEST_SUITE(Car_test, CarFixture);
	BOOST_AUTO_TEST_CASE(Can_turn_engine_on)
	{
		BOOST_CHECK(car.TurnOnEngine());
		BOOST_CHECK(!car.TurnOnEngine());
	}
	BOOST_AUTO_TEST_CASE(Can_turn_engine_off)
	{
		BOOST_CHECK(car.TurnOnEngine());
		BOOST_CHECK(car.TurnOffEngine());
		BOOST_CHECK(!car.TurnOffEngine());

		BOOST_CHECK(car.TurnOnEngine());
		BOOST_CHECK(car.SetGear(1));
		BOOST_CHECK(!car.TurnOffEngine());
	}
	BOOST_AUTO_TEST_CASE(Car_is_at_rest_after_turning_engine_on)
	{
		BOOST_CHECK(!car.IsEngineOn());
		BOOST_CHECK(car.TurnOnEngine());
		BOOST_CHECK(car.IsEngineOn());
	
		BOOST_CHECK(car.GetDirection() == Direction::AT_REST);
		BOOST_CHECK(car.GetSpeed() == 0);
		BOOST_CHECK(car.GetGear() == 0);
	}

	BOOST_FIXTURE_TEST_SUITE(Engine_is_turned_on, CarWithEngineOn)
		BOOST_AUTO_TEST_CASE(Correctly_change_gear)
		{
			BOOST_CHECK(car.SetGear(1));
			BOOST_CHECK(car.GetGear() == 1);
			BOOST_CHECK(car.SetSpeed(30));
			BOOST_CHECK(!car.SetGear(-1));

			BOOST_CHECK(car.SetSpeed(0));
			BOOST_CHECK(car.SetGear(-1));

			BOOST_CHECK(car.SetSpeed(10));
			BOOST_CHECK(!car.SetGear(1));

			BOOST_CHECK(car.SetSpeed(0));
			BOOST_CHECK(car.SetGear(1));

			BOOST_CHECK(car.SetGear(-1));
			BOOST_CHECK(car.SetSpeed(10));
			BOOST_CHECK(car.SetGear(0));
			BOOST_CHECK(!car.SetGear(1));
		}
		BOOST_AUTO_TEST_CASE(Correctly_change_speed)
		{
			BOOST_CHECK(car.SetGear(1));
			BOOST_CHECK(car.GetGear() == 1);

			BOOST_CHECK(car.SetSpeed(30));
			BOOST_CHECK(car.GetSpeed() == 30);

			BOOST_CHECK(car.SetSpeed(0));
			BOOST_CHECK(car.GetSpeed() == 0);

			BOOST_CHECK(car.SetSpeed(10));
			BOOST_CHECK(car.SetGear(0));

			BOOST_CHECK(!car.SetSpeed(11));
			BOOST_CHECK(car.GetSpeed() == 10);

			BOOST_CHECK(car.SetSpeed(9));
			BOOST_CHECK(car.GetSpeed() == 9);
		}

		BOOST_AUTO_TEST_CASE(check_set_speed_when_value_out_of_gearspeed_range)
		{
			BOOST_CHECK(!car.SetSpeed(31));
			BOOST_CHECK(car.GetSpeed() == 30);
		}
		
	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()