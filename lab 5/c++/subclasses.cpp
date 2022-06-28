#include "subclasses.h"

/*Методи класу intMatrix*/

intMatrix::intMatrix(int Row, int Col) : TMatrix(Row, Col)
{
	iMat = new int* [row];
	for (int i = 0; i < row; i++)
	{
		iMat[i] = new int[col];
		for (int j = 0; j < col; j++)
		{
			iMat[i][j] = 0;
		}
	}
}

intMatrix::intMatrix(const intMatrix& copy) : TMatrix(copy.row, copy.col)
{
	iMat = new int * [row];
	for (int i = 0; i < row; i++) 
	{
		iMat[i] = new int[col];
		for (int j = 0; j < col; j++)
		{
			iMat[i][j] = copy.iMat[i][j];
		}
	}
}

/*intMatrix::~intMatrix()
{
	for (int i = 0; i < row; i++)
	{
		delete[] iMat[i];
	}
	delete[] iMat;
}*/

void intMatrix::valueUp()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			iMat[i][j] += 9;
		}
	}
}

void intMatrix::valueDown()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			iMat[i][j] -= 5;
		}
	}
}

float intMatrix::countAverage()
{
	float acc = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			acc += iMat[i][j];
		}
	}
	acc /= row * col;
	return acc;
}

void intMatrix::setValue(int min, int max)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			iMat[i][j] = int(((float(rand()) / float(RAND_MAX)) * (max - min + 1)) + min);
		}
	}
}

void intMatrix::printMatrix()
{
	std::cout << "\n";
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			std::cout << std::setw(5) << iMat[i][j];
		}
		std::cout << "\n";
	}
}

/*Методи класу floatMatrix*/ 

floatMatrix::floatMatrix(int Row, int Col) : TMatrix(Row, Col)
{
	fMat = new float* [row];
	for (int i = 0; i < row; i++)
	{
		fMat[i] = new float[col];
	}
}

floatMatrix::floatMatrix(const floatMatrix& copy) : TMatrix(copy.row, copy.col)
{
		fMat = new float* [row];
		for (int i = 0; i < row; i++) {
			fMat[i] = new float[col];
			for (int j = 0; j < col; j++) {
				fMat[i][j] = copy.fMat[i][j];
			}
		}
}

/*floatMatrix::~floatMatrix()
{
	for (int i = 0; i < row; i++)
	{
		delete[] fMat[i];
	}
	delete[] fMat;
}*/

void floatMatrix::valueDown()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			fMat[i][j] -= 5;
		}
	}
}

void floatMatrix::valueUp()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			fMat[i][j] += 9;
		}
	}
}

float floatMatrix::countAverage()
{
	float acc = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			acc += fMat[i][j];
		}
	}
	acc /= row * col;
	return acc;
}

void floatMatrix::setValue(int min, int max)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			fMat[i][j] = ((float(rand()) / float(RAND_MAX)) * (max - min)) + min;
		}
	}
}

void floatMatrix::printMatrix()
{
	std::cout << "\n";
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			std::cout << std::fixed << std::setprecision(1) << std::setw(6) << fMat[i][j];
		}
		std::cout << "\n";
	}
}