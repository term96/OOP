// FindText.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool FindText(ifstream & input, string const& toFind)
{
	// ���� ����� ��������� ������ �� �����
	string line;
	char ch = 0;

	// ������� ������
	int current = 1;

	// ������ ������� ���� �� 1 ���
	bool found = false;

	while (!input.eof())
	{
		getline(input, line);

		if (line.find(toFind) != string::npos)
		{
			cout << current << "\n";
			found = true;
		}

		line = "";
		current++;
	}

	return found;
}

int main(int argc, char * argv[])
{
	// �������� ���������� ����������
	if (argc != 3)
	{
		cout << "Invalid arguments count: \n"
			<< "Usage: findtext.exe <file name> <text to search>\n";
		return 1;
	}

	// ������� ������ ������
	if (strlen(argv[2]) == 0)
	{
		cout << "<text to search> should not be empty\n";
		return 1;
	}

	// ����� ��� ������ �� �������� �����
	ifstream input(argv[1]);

	if (!input.is_open())
	{
		cout << "Failed to open " << argv[1] << " for reading\n";
		return 1;
	}

	if (!FindText(input, argv[2]))
	{
		cout << "Text not found\n";
		return 1;
	}

	return 0;
}