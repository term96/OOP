// Crypt.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char ShuffleBits(char byte)
{
	// Хранит байты, у которых установлен в единицу один определённый бит, от 00000001 до 10000000
	int bits[8] = { 1, 2, 4, 8, 16, 32, 64, 128 };
	
	char result = 0;

	if (byte & bits[0])
	{
		result |= bits[2];
	}

	if (byte & bits[1])
	{
		result |= bits[3];
	}

	if (byte & bits[2])
	{
		result |= bits[4];
	}

	if (byte & bits[3])
	{
		result |= bits[6];
	}

	if (byte & bits[4])
	{
		result |= bits[7];
	}

	if (byte & bits[5])
	{
		result |= bits[0];
	}

	if (byte & bits[6])
	{
		result |= bits[1];
	}

	if (byte & bits[7])
	{
		result |= bits[5];
	}

	return result;
}

char DeshuffleBits(char byte)
{
	// Хранит байты, у которых установлен в единицу один определённый бит, от 00000001 до 10000000
	int bits[8] = { 1, 2, 4, 8, 16, 32, 64, 128 };

	char result = 0;

	if (byte & bits[2])
	{
		result |= bits[0];
	}

	if (byte & bits[3])
	{
		result |= bits[1];
	}

	if (byte & bits[4])
	{
		result |= bits[2];
	}

	if (byte & bits[6])
	{
		result |= bits[3];
	}

	if (byte & bits[7])
	{
		result |= bits[4];
	}

	if (byte & bits[0])
	{
		result |= bits[5];
	}

	if (byte & bits[1])
	{
		result |= bits[6];
	}

	if (byte & bits[5])
	{
		result |= bits[7];
	}

	return result;
}

void Crypt(ifstream & input, ofstream & output, char key)
{
	char byte, cryptedByte;
	while (!input.eof())
	{
		byte = input.get();
		if (byte == EOF)
		{
			break;
		}
		cryptedByte = ShuffleBits(byte ^ key);
		output << cryptedByte;
	}
}

void Decrypt(ifstream & input, ofstream & output, char key)
{
	char byte, decryptedByte;
	while (!input.eof())
	{
		byte = input.get();
		if (byte == EOF)
		{
			break;
		}
		decryptedByte = DeshuffleBits(byte) ^ key;
		output << decryptedByte;
	}
}

int main(int argc, char * argv[])
{
	if (argc != 5)
	{
		cout << "Invalid parameters count\n"
			<< "Usage: crypt.exe <action> <input file> <output file> <key>\n";
		return 1;
	}

	ifstream input(argv[2]);
	if (!input.is_open())
	{
		cout << "Failed to open file " << argv[2] << '\n';
		return 1;
	}

	ofstream output(argv[3]);
	if (!output.is_open())
	{
		cout << "Failed to open file " << argv[3] << '\n';
		return 1;
	}

	string error = "Invalid <byte>:\n<byte> should be a number in a range 0-255\n";
	int key;
	try
	{
		key = stoi(argv[4]);
	}
	catch (...)
	{
		cout << error;
		return 1;
	}

	// Проверка на выход за пределы 0-255
	if (key < 0 || key > 255) {
		cout << error;
		return 1;
	}
	// TO DO: Handle exceptions
	
	string action = argv[1];

	if (action == "crypt")
	{
		Crypt(input, output, key);
	}
	else if (action == "decrypt")
	{
		Decrypt(input, output, key);
	}
	else
	{
		cout << "Invalid parameter <action>\n"
			<< "<action> should be a word 'crypt' or 'decrypt'\n";
		return 1;
	}
	return 0;
}

