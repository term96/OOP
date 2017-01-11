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
	// двигатель может быть выключен только при нулевой скорости на нейтральной передаче
	if (m_isEngineOn && m_speed == 0 && m_gear == 0)
	{
		m_isEngineOn = false;
		return true;
	}

	return false;
}

bool CCar::SetGear(int newGear)
{
	// при включенном двигателе переключиться можно с любой передачи на любую при условии, что текущая скорость автомобиля 
	// находится в диапазоне скоростей новой передачи, и направление движения автомобиля допускает включение данной передачи
	if (!m_isEngineOn || !IsSpeedInRange(m_speed, newGear) || !IsDirectionCorrect(m_direction, newGear))
		return false;

	// на задний ход можно переключиться только с нейтральной или первой передачи на нулевой скорости;
	if (newGear == -1)
	{
		if (m_gear > 1 || m_speed != 0)
			return false;
	}

	// с заднего хода можно переключиться на первую передачу только на нулевой скорости;
	if (newGear == 1 && m_gear < 1)
	{
		if (m_speed != 0)
			return false;
	}

	m_gear = newGear;

	ChangeDirection();
	return true;
}

bool CCar::SetSpeed(int speed)
{
	// на каждой передаче можно развить скорость в пределах отведенного данной передаче диапазона
	if (!IsSpeedInRange(speed, m_gear))
		return false;

	//на нейтральной передаче нельзя разогнаться
	if (m_gear == 0 && speed >= m_speed)
		return false;

	m_speed = speed;

	ChangeDirection();
	return true;
}

void CCar::ChangeDirection()
{
	if (m_speed == 0)
	{
		m_direction = Direction::AT_REST;
		return;
	}

	if (m_gear > 0)
	{
		m_direction = Direction::FORWARD;
	}
	else if (m_gear == -1)
	{
		m_direction = Direction::BACKWARD;
	}
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
		return (speed >= 0 && speed <= 20) ? true : false;
	case 0:
		return (speed >= 0) ? true : false;
	case 1:
		return (speed >= 0 && speed <= 30) ? true : false;
	case 2:
		return (speed >= 20 && speed <= 50) ? true : false;
	case 3:
		return (speed >= 30 && speed <= 60) ? true : false;
	case 4:
		return (speed >= 40 && speed <= 90) ? true : false;
	case 5:
		return (speed >= 50 && speed <= 150) ? true : false;
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