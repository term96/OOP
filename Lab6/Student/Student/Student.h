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

	void Rename(std::string const & name, std::string const & surname, std::string const & patronymic);
	void SetAge(int age);
private:
	bool HasSpaces(std::string const & input) const;
	void CheckFullName(std::string const & name, std::string const & surname, std::string const & patronymic) const;
	void CheckAge(int age) const;

	std::string m_name;
	std::string m_surname;
	std::string m_patronymic;
	int m_age = 0;
};

