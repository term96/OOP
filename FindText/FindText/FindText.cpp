// FindText.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char * argv[])
{
	// �������� ���������� ����������
	if (argc != 3) {
		cout << "Invalid arguments count: \n"
			<< "Usage: findtext.exe <file name> <text to search>\n";
		return 1;
	}

	// ������� ������ ������
	if (strlen(argv[2]) == 0) {
		cout << "<text to search> should not be empty\n";
		return 1;
	}

	// ����� ��� ������ �� �������� �����
	ifstream input(argv[1]);

	if (!input.is_open()) {
		cout << "Failed to open " << argv[1] << " for reading\n";
		return 1;
	}

	// ���� ����� ��������� ������ �� �����
	string stroke = "";
	char ch = 0;

	// ������� ������
	int current = 1;

	// ������ ������� ���� �� 1 ���
	bool found = false;

	while (!input.eof()) {
		// ��������� ������
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

