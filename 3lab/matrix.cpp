#include "matrix.h"
#include <cstdlib>
#include <iomanip>

Matrix::Matrix(int Size) : size(Size)
{
	allocSpace();
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			m[i][j] = 0;
		}
	}
	std::cout << "Constructor\n";
}

Matrix::~Matrix()
{
	for (int i = 0; i < size; ++i) {
		delete[] m[i];
	}
	delete[] m;
	std::cout << "Desstructor\n";
}

Matrix::Matrix(const Matrix& p) : size(p.size)
{
	allocSpace();
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			m[i][j] = p.m[i][j];
		}
	}
}

void Matrix::allocSpace()
{
	m = new double* [size];
	for (int i = 0; i < size; ++i) {
		m[i] = new double[size];
	}
}

void Matrix::fillRandM() {
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
			m[row][col] = ((float(rand()) / float((RAND_MAX))) * 100 - 50);
		}
	}
}

void Matrix::fillHandM() {
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

void Matrix::printMatrix() {

	std::cin.ignore();

	for (int row = 0; row < size; row++)
	{
		std::cout << "\n";
		for (int col = 0; col < size; col++)
		{
			std::cout << setw(7) << fixed << setprecision(1) << m[row][col];
		}
	}
	std::cout << "\n";
}

float Matrix::findDiagSum() {
	float acc = 0;

	for (int i = 0; i < size; i++)
	{
		acc += m[i][i];
	}
	return acc;
}
