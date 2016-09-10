// Invert.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

// ������� ���������� ��������������� ����������
double findCofactor(const double matrix[3][3], int row, int col)
{
	// �������������� �����
	double minor[2][2];
	int a = 0;

	// ������� �������������� �����
	for (int i = 0; i < 3; i++)
	{
		if (i == row)
		{
			continue;
		}
		int b = 0;
		for (int j = 0; j < 3; j++)
		{
			if (j == col)
			{
				continue;
			}
			minor[a][b] = matrix[i][j];
			b++;
		}
		a++;
	}

	// ������� �������������� ������������
	double determinant = (minor[0][0] * minor[1][1]) - (minor[1][0] * minor[0][1]);
	if (determinant == 0)
	{
		return 0;
	}

	return pow(-1, (row + col)) * determinant;
}

int main(int argc, char * argv[])
{
	if (argc != 2) {
		cout << "Invalid arguments count:\n"
			<< "Usage: invert.exe <matrix file>\n";
		return 1;
	}

	// ����� ��� ������ ����� � ��������
	ifstream input(argv[1]);

	// �� ������� ������� ����
	if (!input.is_open())
	{
		cout << "Failed to open " << argv[1] << " for reading\n";
		return 1;
	}

	double matrix[3][3];

	// ��������� ������� �� �����
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			input >> matrix[i][j];
		}
	}

	// ������� ������������ �������
	double determinant = (matrix[0][0] * matrix[1][1] * matrix[2][2]) - (matrix[0][0] * matrix[1][2] * matrix[2][1])
		- (matrix[0][1] * matrix[1][0] * matrix[2][2]) + (matrix[0][1] * matrix[1][2] * matrix[2][0])
		+ (matrix[0][2] * matrix[1][0] * matrix[2][1]) - (matrix[0][2] * matrix[1][1] * matrix[2][0]);

	// ���� ������������ = 0, �� �������� ������� �� ����������
	if (determinant == 0)
	{
		cout << "Invert matrix doesn't exist, because determinant = 0\n";
		return 0;
	}

	// ������� ������� �������������� ����������
	double cofactorMatrix[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cofactorMatrix[i][j] = findCofactor(matrix, i, j);
		}
	}

	// ������� �������� �������
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << fixed << setprecision(3) << cofactorMatrix[j][i] / determinant << " ";
		}
		cout << "\n";
	}

    return 0;
}

