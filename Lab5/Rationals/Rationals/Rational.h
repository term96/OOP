#pragma once

#include <iostream>

class CRational
{
public:
	CRational();
	CRational(int value);
	CRational(int numerator, int denominator);

	int GetNumerator() const;
	int GetDenominator() const;

	double ToDouble() const;

	std::pair<int, CRational> ToCompoundFraction() const;

	CRational operator+() const;
	CRational operator-() const;
	CRational& operator+=(CRational const& rational);
	CRational& operator-=(CRational const& rational);
	CRational& operator*=(CRational const& rational);
	CRational& operator/=(CRational const& rational);

	friend CRational operator+(CRational const& left, CRational const& right);
	friend CRational operator-(CRational const& left, CRational const& right);
	friend CRational operator*(CRational const& left, CRational const& right);
	friend CRational operator/(CRational const& left, CRational const& right);
	friend bool operator==(CRational const& left, CRational const& right);
	friend bool operator!=(CRational const& left, CRational const& right);
	friend bool operator<(CRational const& left, CRational const& right);
	friend bool operator<=(CRational const& left, CRational const& right);
	friend bool operator>(CRational const& left, CRational const& right);
	friend bool operator>=(CRational const& left, CRational const& right);

	friend std::ostream& operator<<(std::ostream& stream, CRational & rational);
	friend std::istream& operator>>(std::istream& stream, CRational & rational);
private:
	static void Normalize(CRational & rational);
	static int GCD(int a, int b); // мнд
	static int LCM(int a, int b); // мнй
	int m_numerator;
	int m_denominator;
};

