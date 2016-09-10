// FindText.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char * argv[])
{
	// Неверное количество аргументов
	if (argc != 3) {
		cout << "Invalid arguments count: \n"
			<< "Usage: findtext.exe <file name> <text to search>\n";
		return 1;
	}

	// Искомая строка пустая
	if (strlen(argv[2]) == 0) {
		cout << "<text to search> should not be empty\n";
		return 1;
	}

	// Поток для чтения из входного файла
	ifstream input(argv[1]);

	if (!input.is_open()) {
		cout << "Failed to open " << argv[1] << " for reading\n";
		return 1;
	}

	// Сюда будем считывать строку из файла
	string stroke = "";
	char ch = 0;

	// Текущая строка
	int current = 1;

	// Строка найдена хотя бы 1 раз
	bool found = false;

	while (!input.eof()) {
		// Считываем строку
		input.get(ch);
		while (ch != '\n') {
			stroke += ch;
			if (input.eof()) {
				break;
			}
			input.get(ch);
		}
		
		if (stroke.find(argv[2]) != string::npos) {
			cout << current << "\n";
			found = true;
		}

		stroke = "";
		current++;
	}

	if (!found) {
		cout << "Text not found\n";
		return 1;
	}

    return 0;
}

