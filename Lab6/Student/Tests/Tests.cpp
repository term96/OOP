#include "stdafx.h"
#include "../Student/Student.h"
#include <sstream>

using namespace std;

BOOST_AUTO_TEST_SUITE(Student)
	string name = "Иван";
	string surname = "Иванов";
	string patronymic = "Иванович";
	int age = 20;

	BOOST_AUTO_TEST_SUITE(Constructor)
		BOOST_AUTO_TEST_CASE(Good_input)
		{
			BOOST_CHECK_NO_THROW(CStudent(name, surname, patronymic, age));
		}
		BOOST_AUTO_TEST_CASE(Invalid_name)	
		{
			string name1 = "";
			string name2 = "Неверное имя";

			BOOST_CHECK_THROW(CStudent(name1, surname, patronymic, age), invalid_argument);
			BOOST_CHECK_THROW(CStudent(name2, surname, patronymic, age), invalid_argument);
		}
		BOOST_AUTO_TEST_CASE(Invalid_surname)
		{
			string surname1 = "";
			string surname2 = "Неверная фамилия";

			BOOST_CHECK_THROW(CStudent(name, surname1, patronymic, age), invalid_argument);
			BOOST_CHECK_THROW(CStudent(name, surname2, patronymic, age), invalid_argument);
		}
		BOOST_AUTO_TEST_CASE(Invalid_or_empty_patronymic)
		{
			string patronymic1 = "";
			string patronymic2 = "Неверное отчество";

			BOOST_CHECK_NO_THROW(CStudent(name, surname, patronymic1, age));
			BOOST_CHECK_THROW(CStudent(name, surname, patronymic2, age), invalid_argument);
		}
		BOOST_AUTO_TEST_CASE(Invalid_age)
		{
			int age1 = 13;
			int age2 = 61;

			BOOST_CHECK_THROW(CStudent(name, surname, patronymic, age1), out_of_range);
			BOOST_CHECK_THROW(CStudent(name, surname, patronymic, age2), out_of_range);
		}
	BOOST_AUTO_TEST_SUITE_END() // Constructor

	CStudent student(name, surname, patronymic, age);
	BOOST_AUTO_TEST_SUITE(Rename)
		BOOST_AUTO_TEST_CASE(Good_input)
		{
			BOOST_CHECK_NO_THROW(student.Rename(name, surname, patronymic));
		}
		BOOST_AUTO_TEST_CASE(Invalid_name)
		{
			string name1 = "";
			string name2 = "Неверное имя";

			BOOST_CHECK_THROW(student.Rename(name1, surname, patronymic), invalid_argument);
			BOOST_CHECK_THROW(student.Rename(name2, surname, patronymic), invalid_argument);
		}
		BOOST_AUTO_TEST_CASE(Invalid_surname)
		{
			string surname1 = "";
			string surname2 = "Неверная фамилия";

			BOOST_CHECK_THROW(student.Rename(name, surname1, patronymic), invalid_argument);
			BOOST_CHECK_THROW(student.Rename(name, surname2, patronymic), invalid_argument);
		}
		BOOST_AUTO_TEST_CASE(Invalid_or_empty_patronymic)
		{
			string patronymic1 = "";
			string patronymic2 = "Неверное отчество";

			BOOST_CHECK_NO_THROW(student.Rename(name, surname, patronymic1));
			BOOST_CHECK_THROW(student.Rename(name, surname, patronymic2), invalid_argument);
		}
	BOOST_AUTO_TEST_SUITE_END() // Rename
	BOOST_AUTO_TEST_SUITE(Set_age)
		BOOST_AUTO_TEST_CASE(Good_input)
		{
			BOOST_CHECK_NO_THROW(student.SetAge(age));
		}
		BOOST_AUTO_TEST_CASE(New_age_less_than_old)
		{
			int newAge = 19;
			BOOST_CHECK_THROW(student.SetAge(newAge), domain_error);
		}
		BOOST_AUTO_TEST_CASE(Out_of_range)
		{
			int newAge = 61;
			BOOST_CHECK_THROW(student.SetAge(newAge), out_of_range);
		}
	BOOST_AUTO_TEST_SUITE_END() // Set age
BOOST_AUTO_TEST_SUITE_END()