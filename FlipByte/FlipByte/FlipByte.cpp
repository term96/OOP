// FlipByte.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

// ��������� ������� ���������� �������� ����� ����� number
int FlipByte(int number)
{
	int flipped = 0;

	for (int i = 0; i < 8; i++)
	{
		int bitMask = (1 << (7 - i));
		if ((number & bitMask) != 0)
		{
			flipped |= (1 << i);
		}
	}

	return flipped;
}

int main(int argc, char * argv[])
{
	// �������� ���������� ����������
	if (argc != 2) {
		cout << "Invalid arguments count:\n"
			<< "Usage: flipbyte.exe <byte>\n";
		return 1;
	}

	int number;

	string error = "Invalid <byte>:\n<byte> should be a number in a range 0-255\n";

	// ��������� ������� �������� � �����
	try
	{
		number = stoi(argv[1]);
	}
	catch (...)
	{
		cout << error;
		return 1;
	}

	// �������� �� ����� �� ������� 0-255
	if (number < 0 || number > 255) {
		cout << error;
		return 1;
	}

	int flipped = FlipByte(number);

	cout << flipped << "\n";

	return 0;
}

