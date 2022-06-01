#include "matrix.h"

Matrix::Matrix(int Size) : size(Size = 3)
{
	m = new float* [size];
	for (int i = 0; i < size; i++) {
		m[i] = new float[size];
		for (int j = 0; j < size; j++)
		{
			m[i][j] = 0;
		}
	}
}

Matrix::Matrix() : size(3)
{
	m = new float* [size];
	for (int i = 0; i < size; i++) {
		m[i] = new float[size];
		for (int j = 0; j < size; j++)
		{
			m[i][j] = 0;
		}
	}
}

Matrix::Matrix(const Matrix& p)
{
	size = 3;
	m = new float* [size];
	for (int i = 0; i < size; i++) {
		m[i] = new float[size];
		for (int j = 0; j < size; j++) {
			m[i][j] = p.m[i][j];
		}
	}
}

void Matrix::setRand(std::string ans) {
	float number;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			number = ((float(rand()) / float((RAND_MAX))) * 20 - 10);
			if(ans == "y" || ans == "Y")
			number = round(number * 1) / 1;
			else{ number = round(number * 10) / 10; }
			m[i][j] = number;
		}
	}
}

void Matrix::printM()
{
	std::cin.ignore();
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cout << std::setw(9) << m[i][j];
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

float Matrix::findDet()
{
	float det = 0;
	float a = m[0][0] * m[1][1] * m[2][2];
	float b = m[0][1] * m[1][2] * m[2][0];
	float c = m[0][2] * m[1][0] * m[2][1];
	float d = m[2][0] * m[1][1] * m[0][2];
	float e = m[2][1] * m[1][2] * m[0][0];
	float f = m[2][2] * m[1][0] * m[0][1];
	det = a + b + c - d - e - f;
	return det;
}

Matrix Matrix::operator++(int)
{
	std::cin.ignore();
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			m[i][j]++;
		}
	}
	return *this;
}

Matrix Matrix::operator*(Matrix& M2)
{
	Matrix temp{};
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {
				temp.m[i][j] += (m[i][k] * M2.m[k][j]);
				temp.m[i][j] = round(temp.m[i][j] * 10) / 10;
			}
		}
	}
	return temp;
}

void Matrix::setHand() {
	float n;
	std::cout << "Enter the values of matrix: ";

	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
			std::cin >> n;
			m[row][col] = n;
		}
	}
}