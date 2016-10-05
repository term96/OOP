// Invert.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

typedef double Matrix3x3[3][3];

// Функция вычисления алгебраического дополнения
double FindCofactor(Matrix3x3 const& matrix, int row, int col)
{
	// Дополнительный минор
	double minor[2][2];

	// Текущая позиция в minor
	int mRow = 0, mCol = 0;

	// Находим дополнительный минор
	for (int i = 0; i < 3; i++)
	{
		if (i == row)
		{
			continue;
		}
		mCol = 0;
		for (int j = 0; j < 3; j++)
		{
			if (j == col)
			{
				continue;
			}
			minor[mRow][mCol] = matrix[i][j];
			mCol++;
		}
		mRow++;
	}

	// Находим дополнительный определитель
	double determinant = (minor[0][0] * minor[1][1]) - (minor[1][0] * minor[0][1]);
	if (determinant == 0)
	{
		return 0;
	}

	return pow(-1, (row + col)) * determinant;
}

// Находим матрицу алгебраических дополнений
void FindCofactorMatrix(Matrix3x3 const& matrix, Matrix3x3 & cofactorMatrix)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cofactorMatrix[i][j] = FindCofactor(matrix, i, j);
		}
	}
}

// Считываем матрицу из файла
void ReadMatrix(ifstream & input, Matrix3x3 & matrix)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			input >> matrix[i][j];
		}
	}
}

// Находим определитель матрицы 3x3
double FindDeterminant(Matrix3x3 const& matrix)
{
	double determinant = (matrix[0][0] * matrix[1][1] * matrix[2][2]) - (matrix[0][0] * matrix[1][2] * matrix[2][1])
		- (matrix[0][1] * matrix[1][0] * matrix[2][2]) + (matrix[0][1] * matrix[1][2] * matrix[2][0])
		+ (matrix[0][2] * matrix[1][0] * matrix[2][1]) - (matrix[0][2] * matrix[1][1] * matrix[2][0]);
	return determinant;
}

// Выводим обратную матрицу
void PrintResult(Matrix3x3 const& cofactorMatrix, int determinant)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << fixed << setprecision(3) << cofactorMatrix[j][i] / determinant << " ";
		}
		cout << "\n";
	}
}

// Поиск обратной матрицы
int FindInvertMatrix(ifstream & input)
{
	Matrix3x3 matrix;

	ReadMatrix(input, matrix);

	double determinant = FindDeterminant(matrix);

	// Если определитель = 0, то обратной матрицы не существует
	if (determinant == 0)
	{
		cout << "Invert matrix doesn't exist, because determinant = 0\n";
		return 0;
	}

	Matrix3x3 cofactorMatrix;
	FindCofactorMatrix(matrix, cofactorMatrix);

	PrintResult(cofactorMatrix, determinant);

	return 0;
}

int main(int argc, char * argv[])
{
	if (argc != 2) {
		cout << "Invalid arguments count:\n"
			<< "Usage: invert.exe <matrix file>\n";
		return 1;
	}

	// Поток для чтения файла с матрицей
	ifstream input(argv[1]);

	// Не удалось открыть файл
	if (!input.is_open())
	{
		cout << "Failed to open " << argv[1] << " for reading\n";
		return 1;
	}

	return FindInvertMatrix(input);
}
