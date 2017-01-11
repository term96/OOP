#include "stdafx.h"
#include "VirtualCar.h"

#include <iostream>
#include <string>

using namespace std;

const int INVALID_VALUE = -10;

CVirtualCar::CVirtualCar()
	:m_car()
{
}

CVirtualCar::~CVirtualCar()
{
}

void CVirtualCar::HandleUserCommands(std::istream & istream, std::ostream & ostream)
{
	string input;
	while (!istream.eof())
	{
		istream >> input;

		if (input.compare("Info") == 0)
		{
			ostream << GetInfo();
			continue;
		}

		if (input.compare("EngineOn") == 0)
		{
			if (TurnOnEngine())
				ostream << "Двигатель включен\n";
			else
				ostream << "Не удалось включить двигатель\n";
			continue;
		}

		if (input.compare("EngineOff") == 0)
		{
			if (TurnOffEngine())
				ostream << "Двигатель выключен\n";
			else
				ostream << "Не удалось выключить двигатель\n";
			continue;
		}

		if (input.compare("SetGear") == 0)
		{
			istream >> input;
			int gear = StringToInt(input);
			if (gear < -1 || gear > 5)
			{
				ostream << "Введено некорректное значение передачи\n";
				continue;
			}

			if (SetGear(gear))
				ostream << "Включена " << to_string(gear) << " передача\n";
			else
				ostream << "Не удалось сменить передачу\n";
			continue;
		}

		if (input.compare("SetSpeed") == 0)
		{
			istream >> input;
			int speed = StringToInt(input);
			if (speed < 0)
			{
				ostream << "Введено некорректное значение скорости\n";
				continue;
			}

			if (SetSpeed(speed))
				ostream << "Установлена скорость " << to_string(speed) << "\n";
			else
				ostream << "Не удалось сменить скорость\n";
			continue;
		}

		ostream << "Неизвестная команда\n";
	}
}

std::string CVirtualCar::GetInfo() const
{
	string info;
	bool isEngineOn = m_car.IsEngineOn();
	Direction direction = m_car.GetDirection();
	int speed = m_car.GetSpeed();
	int gear = m_car.GetGear();

	info += (isEngineOn) ? "Двигатель включен\n" : "Двигатель выключен\n";
	
	switch (direction)
	{
	case FORWARD:
		info += "Автомобиль едет вперёд\n";
		break;
	case BACKWARD:
		info += "Автомобиль едет назад\n";
		break;
	case AT_REST:
		info += "Автомобиль стоит на месте\n";
		break;
	default:
		break;
	}

	info += "Текущая скорость: " + to_string(speed) + "\n";
	info += "Текущая передача: " + to_string(gear) + "\n";

	return move(info);
}


int CVirtualCar::StringToInt(std::string & input) const
{
	int num = INVALID_VALUE;

	try {
		num = stoi(input);
	}
	catch (...) {}

	return num;
}

bool CVirtualCar::TurnOnEngine()
{
	return m_car.TurnOnEngine();
}

bool CVirtualCar::TurnOffEngine()
{
	return m_car.TurnOffEngine();
}

bool CVirtualCar::SetSpeed(int speed)
{
	return m_car.SetSpeed(speed);
}

bool CVirtualCar::SetGear(int gear)
{
	return m_car.SetGear(gear);
}
