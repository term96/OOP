// Dictionary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <Windows.h>

using namespace std;

typedef map<string, string> Dictionary;
typedef map<string, string>::iterator DictElement;

void ReadFromFile(Dictionary &dictionary, ifstream &file)
{
	string word, translation;
	while (!file.eof())
	{
		getline(file, word);
		getline(file, translation);
		dictionary.emplace(word, translation);
	}
}

void SaveChanges(Dictionary &dictionary, ofstream &file)
{
	DictElement it;
	for (it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		file << it->first << '\n' << it->second << '\n';
	}
	cout << "Изменения сохранены. До свидания.\n";
}

void HandleUserInput(string const& input, Dictionary &dictionary, bool &needToSave)
{
	DictElement element = dictionary.find(input);
	if (element == dictionary.end())
	{
		cout << "Неизвестное слово '" << input << "'.Введите перевод или пустую строку для отказа.\n";
		string translation;
		getline(cin, translation);

		if (translation.empty())
		{
			cout << "Неизвестное слово '" << input << "' проигнорировано.\n";
		}
		else
		{
			dictionary.emplace(input, translation);
			needToSave = true;

			cout << "Слово '" << input << "' сохранено в словаре как '" << translation << "'\n";
		}
	}
	else
	{
		cout << element->second << '\n';
	}
}

int main(int argc, char *argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Dictionary dictionary;

	if (argc != 2) {
		cout << "Неверное количество параметров.\n"
			<< "Использование: dictionary.exe <имя файла словаря>\n";
		return 1;
	}

	ifstream file(argv[1]);
	if (file.is_open())
	{
		ReadFromFile(dictionary, file);
		file.close();
	}

	bool needToSave = false;
	string input;
	getline(cin, input);

	while (input.compare("...") != 0)
	{
		HandleUserInput(input, dictionary, needToSave);
		getline(cin, input);
	}

	if (needToSave)
	{
		cout << "В словарь были внесены изменения. Введите Y или y для сохранения перед выходом.\n";
		char answer = cin.get();

		if (answer == 'Y' || answer == 'y')
		{
			ofstream output(argv[1]);
			SaveChanges(dictionary, output);
		}
	}

    return 0;
}

