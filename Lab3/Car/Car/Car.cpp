#include "stdafx.h"
#include "Car.h"


bool CCar::TurnOnEngine()
{
	if (!m_isEngineOn)
	{
		m_isEngineOn = true;
		return true;
	}

	return false;
}

bool CCar::TurnOffEngine()
{
	// ��������� ����� ���� �������� ������ ��� ������� �������� �� ����������� ��������
	if (m_isEngineOn && m_speed == 0 && m_gear == 0)
	{
		m_isEngineOn = false;
		return true;
	}

	return false;
}

bool CCar::SetGear(int newGear)
{
	// ��� ���������� ��������� ������������� ����� � ����� �������� �� ����� ��� �������, ��� ������� �������� ���������� 
	// ��������� � ��������� ��������� ����� ��������, � ����������� �������� ���������� ��������� ��������� ������ ��������
	if (!m_isEngineOn || !IsSpeedInRange(m_speed, newGear) || !IsDirectionCorrect(m_direction, newGear))
		return false;

	// �� ������ ��� ����� ������������� ������ � ����������� ��� ������ �������� �� ������� ��������;
	if (newGear == -1)
	{
		if (m_gear > 1 || m_speed != 0)
			return false;
	}

	// � ������� ���� ����� ������������� �� ������ �������� ������ �� ������� ��������;

	if (newGear == 1 && m_gear < 1)
	{
		if (m_speed != 0)
			return false;
	}

	m_gear = newGear;
	return true;
}

bool CCar::SetSpeed(int speed)
{
	// �� ������ �������� ����� ������� �������� � �������� ����������� ������ �������� ���������
	if (!IsSpeedInRange(speed, m_gear))
		return false;

	//�� ����������� �������� ������ �����������
	if (m_gear == 0 && speed >= m_speed)
		return false;

	m_speed = speed;
	return true;
}

bool CCar::IsEngineOn() const
{
	return m_isEngineOn;
}

Direction CCar::GetDirection() const
{
	return m_direction;
}

int CCar::GetSpeed() const
{
	return m_speed;
}

int CCar::GetGear() const
{
	return m_gear;
}

bool CCar::IsSpeedInRange(int speed, int gear) const
{
	switch (gear)
	{
	case -1:
		if (speed >= 0 && speed <= 20)
			return true;
	case 0:
		if (speed >= 0)
			return true;
	case 1:
		if (speed >= 0 && speed <= 30)
			return true;
	case 2:
		if (speed >= 20 && speed <= 50)
			return true;
	case 3:
		if (speed >= 30 && speed <= 60)
			return true;
	case 4:
		if (speed >= 40 && speed <= 90)
			return true;
	case 5:
		if (speed >= 50 && speed <= 150)
			return true;
	default:
		return false;
	}
}

bool CCar::IsDirectionCorrect(Direction direction, int gear) const
{
	if (direction == Direction::FORWARD && gear == -1)
		return false;

	if (direction == Direction::BACKWARD && gear > 0)
		return false;

	return true;
}