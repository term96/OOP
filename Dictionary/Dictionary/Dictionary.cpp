#include "stdafx.h"
#include "Dictionary.h"
#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

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
		file << it->first << "\n" << it->second << "\n";
	}
	cout << "Изменения сохранены. До свидания.\n";
}

void HandleUserInput(string const& input, Dictionary &dictionary, bool &dictionaryChanged, istream &inStream)
{
	DictElement element = dictionary.find(input);
	if (element == dictionary.end())
	{
		cout << "Неизвестное слово '" << input << "'.Введите перевод или пустую строку для отказа.\n";
		string translation;
		getline(inStream, translation);

		if (translation.empty())
		{
			cout << "Неизвестное слово '" << input << "' проигнорировано.\n";
		}
		else
		{
			dictionary.emplace(input, translation);
			dictionaryChanged = true;

			cout << "Слово '" << input << "' сохранено в словаре как '" << translation << "'\n";
		}
	}
	else
	{
		cout << element->second << '\n';
	}
}

bool InteractionLoop(Dictionary &dictionary, istream &inStream)
{
	bool dictionaryChanged = false;
	string input;
	getline(inStream, input);

	while (input.compare("...") != 0)
	{
		HandleUserInput(input, dictionary, dictionaryChanged, inStream);
		getline(inStream, input);
	}

	return dictionaryChanged;
}

bool NeedToSave(istream &inStream)
{
	cout << "В словарь были внесены изменения. Введите Y или y для сохранения перед выходом.\n";
	char answer = inStream.get();

	return (answer == 'Y' || answer == 'y');
}
