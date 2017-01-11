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
				ostream << "��������� �������\n";
			else
				ostream << "�� ������� �������� ���������\n";
			continue;
		}

		if (input.compare("EngineOff") == 0)
		{
			if (TurnOffEngine())
				ostream << "��������� ��������\n";
			else
				ostream << "�� ������� ��������� ���������\n";
			continue;
		}

		if (input.compare("SetGear") == 0)
		{
			istream >> input;
			int gear = StringToInt(input);
			if (gear < -1 || gear > 5)
			{
				ostream << "������� ������������ �������� ��������\n";
				continue;
			}

			if (SetGear(gear))
				ostream << "�������� " << to_string(gear) << " ��������\n";
			else
				ostream << "�� ������� ������� ��������\n";
			continue;
		}

		if (input.compare("SetSpeed") == 0)
		{
			istream >> input;
			int speed = StringToInt(input);
			if (speed < 0)
			{
				ostream << "������� ������������ �������� ��������\n";
				continue;
			}

			if (SetSpeed(speed))
				ostream << "����������� �������� " << to_string(speed) << "\n";
			else
				ostream << "�� ������� ������� ��������\n";
			continue;
		}

		ostream << "����������� �������\n";
	}
}

std::string CVirtualCar::GetInfo() const
{
	string info;
	bool isEngineOn = m_car.IsEngineOn();
	Direction direction = m_car.GetDirection();
	int speed = m_car.GetSpeed();
	int gear = m_car.GetGear();

	info += (isEngineOn) ? "��������� �������\n" : "��������� ��������\n";
	
	switch (direction)
	{
	case FORWARD:
		info += "���������� ���� �����\n";
		break;
	case BACKWARD:
		info += "���������� ���� �����\n";
		break;
	case AT_REST:
		info += "���������� ����� �� �����\n";
		break;
	default:
		break;
	}

	info += "������� ��������: " + to_string(speed) + "\n";
	info += "������� ��������: " + to_string(gear) + "\n";

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
