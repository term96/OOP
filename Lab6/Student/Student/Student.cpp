#include "stdafx.h"
#include "Student.h"

#include <iostream>

using namespace std;

CStudent::CStudent(std::string const & name, std::string const & surname, std::string const & patronymic, int age)
{
	CheckFullName(name, surname, patronymic);
	CheckAge(age);
	
	m_name = name;
	m_surname = surname;
	m_patronymic = patronymic;
	m_age = age;
}

std::string const & CStudent::GetName() const
{
	return m_name;
}

std::string const & CStudent::GetSurname() const
{
	return m_surname;
}

std::string const & CStudent::GetPatronymic() const
{
	return m_patronymic;
}

int CStudent::GetAge() const
{
	return m_age;
}

void CStudent::Rename(std::string name, std::string surname, std::string patronymic)
{
	CheckFullName(name, surname, patronymic);

	m_name = move(name);
	m_surname = move(surname);
	m_patronymic = move(patronymic);
}

void CStudent::SetAge(int age)
{
	CheckAge(age);
	if (age < m_age)
	{
		throw domain_error("Age can't be decreased");
	}

	m_age = age;
}

bool CStudent::HasSpaces(std::string const & input)
{
	if (input.find(' ') == string::npos)
	{
		return false;
	}
	return true;
}

void CStudent::CheckFullName(std::string const & name, std::string const & surname, std::string const & patronymic)
{
	if (name.empty() || HasSpaces(name))
	{
		throw invalid_argument("Invalid name");
	}
	if (surname.empty() || HasSpaces(surname))
	{
		throw invalid_argument("Invalid surname");
	}
	if (HasSpaces(patronymic))
	{
		throw invalid_argument("Invalid patronymic");
	}
}

void CStudent::CheckAge(int age)
{
	if (age < 14 || age > 60)
	{
		throw out_of_range("Age is out of range");
	}
}
