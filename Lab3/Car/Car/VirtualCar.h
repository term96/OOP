#pragma once

#include "Car.h"
#include <iostream>
#include <string>

class CVirtualCar
{
public:
	CVirtualCar();
	~CVirtualCar();

	std::string GetInfo() const;
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetSpeed(int speed);
	bool SetGear(int gear);
	void HandleUserCommands(std::istream &istream, std::ostream &ostream);

private:
	int StringToInt(std::string &input) const;

	CCar m_car;
};

