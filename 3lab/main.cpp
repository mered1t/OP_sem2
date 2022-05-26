#include "сlass.h"
#include "functions.h"

int main()
{
	std::vector<Matrix> matrixes;

	Info();
	matrixes = GenerateMatrixArray();
	showMatrix(matrixes);
	findMaxDiagSum(matrixes);
	std::cin.ignore(1);
}
