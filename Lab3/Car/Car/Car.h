#pragma once

enum Direction
{
	FORWARD, BACKWARD, AT_REST
};

class CCar
{
public:
	CCar() {};
	~CCar() {};

	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool SetSpeed(int speed);

	bool IsEngineOn() const;
	Direction GetDirection() const;
	int GetSpeed() const;
	int GetGear() const;
private:
	bool IsSpeedInRange(int speed, int gear) const;
	bool IsDirectionCorrect(Direction direction, int gear) const;

	bool m_isEngineOn = false;
	Direction m_direction = Direction::AT_REST;
	int m_gear = 0;
	int m_speed = 0;
};

