// Dictionary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Dictionary.h"
#include <Windows.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	if (argc != 2) {
		cout << "Неверное количество параметров.\n"
			<< "Использование: dictionary.exe <имя файла словаря>\n";
		return 1;
	}

	Dictionary dictionary;

	ifstream file(argv[1]);
	if (file.is_open())
	{
		ReadFromFile(dictionary, file);
		file.close();
	}

	bool dictionaryChanged = InteractionLoop(dictionary);

	if (dictionaryChanged && NeedToSave())
	{
		ofstream output(argv[1]);
		SaveChanges(dictionary, output);
	}

    return 0;
}

