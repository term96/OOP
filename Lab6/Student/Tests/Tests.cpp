#include "stdafx.h"
#include "../Student/Student.h"
#include <sstream>

#include <iostream>

using namespace std;

BOOST_AUTO_TEST_SUITE(Student)
	string name = "Иван";
	string surname = "Иванов";
	string patronymic = "Иванович";
	int age = 20;

	BOOST_AUTO_TEST_SUITE(Constructor)
		BOOST_AUTO_TEST_CASE(Doesnt_throw_exceptions_on_correct_input)
		{
			BOOST_CHECK_NO_THROW(CStudent(name, surname, patronymic, age));
			
		}
		BOOST_AUTO_TEST_CASE(Correctly_initialize)
		{
			CStudent student(name, surname, patronymic, age);
			BOOST_CHECK_EQUAL(student.GetName(), name);
			BOOST_CHECK_EQUAL(student.GetSurname(), surname);
			BOOST_CHECK_EQUAL(student.GetPatronymic(), patronymic);
			BOOST_CHECK_EQUAL(student.GetAge(), age);
		}
		BOOST_AUTO_TEST_CASE(Throws_exception_on_empty_name)
		{
			string emptyName;
			BOOST_CHECK_THROW(CStudent(emptyName, surname, patronymic, age), invalid_argument);
		}
		BOOST_AUTO_TEST_CASE(Throws_exception_on_name_with_spaces)
		{
			string nameWithSpaces = "with spaces";
			BOOST_CHECK_THROW(CStudent(nameWithSpaces, surname, patronymic, age), invalid_argument);
		}
		BOOST_AUTO_TEST_CASE(Throws_exception_on_empty_surname)
		{
			string emptySurname;
			BOOST_CHECK_THROW(CStudent(name, emptySurname, patronymic, age), invalid_argument);
		}
		BOOST_AUTO_TEST_CASE(Throws_exception_on_surname_with_spaces)
		{
			string surnameWithSpaces = "with spaces";
			BOOST_CHECK_THROW(CStudent(name, surnameWithSpaces, patronymic, age), invalid_argument);
		}
		BOOST_AUTO_TEST_CASE(Correctly_initializes_on_empty_patronymic)
		{
			string emptyPatronymic;
			BOOST_CHECK_NO_THROW(CStudent(name, surname, emptyPatronymic, age));

			CStudent student(name, surname, emptyPatronymic, age);
			BOOST_CHECK_EQUAL(student.GetPatronymic(), emptyPatronymic);
		}
		BOOST_AUTO_TEST_CASE(Throws_exception_on_patronymic_with_spaces)
		{
			string patronymicWithSpaces = "with spaces";
			BOOST_CHECK_THROW(CStudent(name, surname, patronymicWithSpaces, age), invalid_argument);
		}
		BOOST_AUTO_TEST_CASE(Throws_exception_if_age_is_out_of_range)
		{
			int tooBigAge = 61;
			int tooSmallAge = 13;
			BOOST_CHECK_THROW(CStudent(name, surname, patronymic, tooBigAge), out_of_range);
			BOOST_CHECK_THROW(CStudent(name, surname, patronymic, tooSmallAge), out_of_range);
		}
		BOOST_AUTO_TEST_CASE(Correctly_initialize_on_age_borders)
		{
			int minAge = 14;
			int maxAge = 60;
			BOOST_CHECK_NO_THROW(CStudent(name, surname, patronymic, minAge));
			BOOST_CHECK_NO_THROW(CStudent(name, surname, patronymic, maxAge));

			CStudent studentWithMinAge(name, surname, patronymic, minAge);
			CStudent studentWithMaxAge(name, surname, patronymic, maxAge);
			BOOST_CHECK_EQUAL(studentWithMinAge.GetAge(), minAge);
			BOOST_CHECK_EQUAL(studentWithMaxAge.GetAge(), maxAge);
		}
	BOOST_AUTO_TEST_SUITE_END() // Constructor

	BOOST_AUTO_TEST_SUITE(Rename_function)
		BOOST_AUTO_TEST_CASE(Correctly_rename_on_correct_input)
		{
			CStudent student(name, surname, patronymic, age);
			string newName = "Name";
			string newSurname = "Surname";
			string newPatronymic = "Patronymic";
			BOOST_CHECK_NO_THROW(student.Rename(newName, newSurname, newPatronymic));
			BOOST_CHECK_EQUAL(student.GetName(), newName);
			BOOST_CHECK_EQUAL(student.GetSurname(), newSurname);
			BOOST_CHECK_EQUAL(student.GetPatronymic(), newPatronymic);
		}
		BOOST_AUTO_TEST_CASE(Throws_exception_on_empty_name)
		{
			CStudent student(name, surname, patronymic, age);
			BOOST_CHECK_THROW(student.Rename("", surname, patronymic), invalid_argument);
			BOOST_CHECK_EQUAL(student.GetName(), name);
		}
		BOOST_AUTO_TEST_CASE(Throws_exception_on_name_with_spaces)
		{
			CStudent student(name, surname, patronymic, age);
			BOOST_CHECK_THROW(student.Rename("With Spaces", surname, patronymic), invalid_argument);
			BOOST_CHECK_EQUAL(student.GetName(), name);
		}
		BOOST_AUTO_TEST_CASE(Throws_exception_on_empty_surname)
		{
			CStudent student(name, surname, patronymic, age);
			BOOST_CHECK_THROW(student.Rename(name, "", patronymic), invalid_argument);
			BOOST_CHECK_EQUAL(student.GetSurname(), surname);
		}
		BOOST_AUTO_TEST_CASE(Throws_exception_on_surname_with_spaces)
		{
			CStudent student(name, surname, patronymic, age);
			BOOST_CHECK_THROW(student.Rename(name, "With Spaces", patronymic), invalid_argument);
			BOOST_CHECK_EQUAL(student.GetSurname(), surname);
		}
		BOOST_AUTO_TEST_CASE(Throws_exception_on_patronymic_with_spaces)
		{
			CStudent student(name, surname, patronymic, age);
			BOOST_CHECK_THROW(student.Rename(name, surname, "With Spaces"), invalid_argument);
			BOOST_CHECK_EQUAL(student.GetPatronymic(), patronymic);
		}
		BOOST_AUTO_TEST_CASE(Correctly_rename_on_empty_patronymic)
		{
			CStudent student(name, surname, patronymic, age);
			BOOST_CHECK_NO_THROW(student.Rename(name, surname, ""));
			BOOST_CHECK_EQUAL(student.GetPatronymic(), "");
		}
		BOOST_AUTO_TEST_SUITE_END() // Rename function

	BOOST_AUTO_TEST_SUITE(SetAge_function)
		BOOST_AUTO_TEST_CASE(Change_age_correctly_on_correct_input)
		{
			CStudent student(name, surname, patronymic, age);
			int newAge = student.GetAge() + 1;
			BOOST_CHECK_NO_THROW(student.SetAge(newAge));
			BOOST_CHECK_EQUAL(student.GetAge(), newAge);
		}
		BOOST_AUTO_TEST_CASE(Change_age_correctly_on_upper_border)
		{
			CStudent student(name, surname, patronymic, age);
			int newAge = 60;
			BOOST_CHECK_NO_THROW(student.SetAge(newAge));
			BOOST_CHECK_EQUAL(student.GetAge(), newAge);
		}
		BOOST_AUTO_TEST_CASE(Throws_exception_if_age_decreased)
		{
			CStudent student(name, surname, patronymic, age);
			int newAge = student.GetAge() - 1;
			BOOST_CHECK_THROW(student.SetAge(newAge), domain_error);
			BOOST_CHECK_EQUAL(student.GetAge(), age);
		}
		BOOST_AUTO_TEST_CASE(Throws_exception_if_age_larger_than_max)
		{
			CStudent student(name, surname, patronymic, age);
			int newAge = 61;
			BOOST_CHECK_THROW(student.SetAge(newAge), out_of_range);
			BOOST_CHECK_EQUAL(student.GetAge(), age);
		}
		BOOST_AUTO_TEST_SUITE_END() // SetAge function
BOOST_AUTO_TEST_SUITE_END()