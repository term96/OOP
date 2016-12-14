#include "stdafx.h"
#include "Rational.h"
#include <string>

using namespace std;

CRational::CRational()
{
	m_numerator = 0;
	m_denominator = 1;
}

CRational::CRational(int value)
{
	m_numerator = value;
	m_denominator = 1;
}

CRational::CRational(int numerator, int denominator)
{
	if (denominator < 0)
	{
		numerator = -numerator;
		denominator = -denominator;
	}
	
	if (denominator == 0)
	{
		numerator = 0;
		denominator = 1;
	}

	m_numerator = numerator;
	m_denominator = denominator;
	
	Normalize(*this);
}

int CRational::GetNumerator() const
{
	return m_numerator;
}

int CRational::GetDenominator() const
{
	return m_denominator;
}

double CRational::ToDouble() const
{
	return m_numerator / m_denominator;
}

std::pair<int, CRational> CRational::ToCompoundFraction() const
{
	int integer = m_numerator / m_denominator;
	CRational rational = *this - integer;
	return std::pair<int, CRational>(integer, rational);
}

CRational CRational::operator+() const
{
	return *this;
}

CRational CRational::operator-() const
{
	return move(CRational(-m_numerator, m_denominator));
}

CRational& CRational::operator+=(CRational const & rational)
{
	*this = *this + rational;
	return *this;
}

CRational& CRational::operator-=(CRational const & rational)
{
	*this = *this - rational;
	return *this;
}

CRational& CRational::operator*=(CRational const & rational)
{
	*this = *this * rational;
	return *this;
}

CRational& CRational::operator/=(CRational const & rational)
{
	*this = *this / rational;
	return *this;
}

void CRational::Normalize(CRational & rational)
{
	int a = (rational.m_numerator > 0) ? rational.m_numerator : -rational.m_numerator;
	int b = rational.m_denominator;
	int divisor = GCD(a, b);

	rational.m_numerator /= divisor;
	rational.m_denominator /= divisor;
}

int CRational::GCD(int a, int b)
{
	while (a != 0 && b != 0)
	{
		if (a > b)
		{
			a = a % b;
		}
		else
			b = b % a;
	}
	return a + b;
}

int CRational::LCM(int a, int b)
{
	return b / GCD(a, b) * a;
}

CRational operator+(CRational const & left, CRational const & right)
{
	CRational result;
	int multiple = CRational::LCM(left.m_denominator, right.m_denominator);
	
	result.m_denominator = multiple;
	result.m_numerator = multiple / left.m_denominator * left.m_numerator
		+ multiple / right.m_denominator * right.m_numerator;
		
	CRational::Normalize(result);
	return move(result);
}

CRational operator-(CRational const & left, CRational const & right)
{
	return move(left + (-right));
}

CRational operator*(CRational const & left, CRational const & right)
{
	CRational result;
	result.m_numerator = left.m_numerator * right.m_numerator;
	result.m_denominator = left.m_denominator * right.m_denominator;

	CRational::Normalize(result);
	return move(result);
}

CRational operator/(CRational const & left, CRational const & right)
{
	CRational rational(right.m_denominator, right.m_numerator);
	return move(left * rational);
}

bool operator==(CRational const & left, CRational const & right)
{
	if (left.m_numerator == right.m_numerator && left.m_denominator == right.m_denominator)
		return true;
	return false;
}

bool operator!=(CRational const & left, CRational const & right)
{
	return !(left == right);
}

bool operator<(CRational const & left, CRational const & right)
{
	int multiple = CRational::LCM(left.m_denominator, right.m_denominator);
	int leftNum = multiple / left.m_denominator * left.m_numerator;
	int rightNum = multiple / right.m_denominator * right.m_numerator;

	return leftNum < rightNum;
}

bool operator<=(CRational const & left, CRational const & right)
{
	return (left < right || left == right);
}

bool operator>(CRational const & left, CRational const & right)
{
	return !(left <= right);
}

bool operator>=(CRational const & left, CRational const & right)
{
	return !(left < right);
}

ostream& operator<<(ostream & stream, CRational & rational)
{
	stream << rational.m_numerator;
	stream << '/';
	stream << rational.m_denominator;

	return stream;
}

istream &operator>>(istream & stream, CRational & rational)
{
	int newNumerator;
	int newDenominator;

	if (stream >> newNumerator && stream.get() && stream >> newDenominator)
	{
		rational.m_numerator = newNumerator;
		rational.m_denominator = newDenominator;
	}

	return stream;
}