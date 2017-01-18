#pragma once

#include <string>

class CStudent
{
public:
	CStudent(std::string const & name, std::string const & surname, std::string const & patronymic, int age);

	std::string const & GetName() const;
	std::string const & GetSurname() const;
	std::string const & GetPatronymic() const;
	int GetAge() const;

	void Rename(std::string name, std::string surname, std::string patronymic);
	void SetAge(int age);
private:
	static bool HasSpaces(std::string const & input);
	static void CheckFullName(std::string const & name, std::string const & surname, std::string const & patronymic);
	static void CheckAge(int age);

	std::string m_name;
	std::string m_surname;
	std::string m_patronymic;
	int m_age = 0;
};

