#include "functions.h"

void enterSize(int& row, int& col)
{
	std::string rows, cols;
	std::cout << "Enter the number of rows: "; std::cin >> rows;
	while (!isNumber(rows) || std::stoi(rows) < 1) {
		std::cout << "Enter the correct value: ";
		std::cin >> rows;
	}

	std::cout << "Enter the number of cols: "; std::cin >> cols;
	while (!isNumber(cols) || std::stoi(cols) < 1) {
		std::cout << "Enter the correct value: ";
		std::cin >> cols;
	}

	row = std::stoi(rows); 
	col = std::stoi(cols);
}

int getAmount()
{
	int amount = rand() % 4 + 1;
	return amount;
}

void getRandMinMax(int &Min, int &Max)
{
	std::string min, max;
	std::cout << "\nEnter the min number for rand: "; std::cin >> min;
	while (!isNumber(min)) {
		std::cout << "Enter the correct value: ";
		std::cin >> min;
	}

	std::cout << "Enter the max number for rand: "; std::cin >> max;
	while (!isNumber(max) || stoi(max)<stoi(min)) {
		std::cout << "Enter the correct value: ";
		std::cin >> max;
	}

	Min = std::stoi(min);
	Max = std::stoi(max);
}

bool isNumber(std::string& num) {
	int st = 1;
	for (char i : num) {
		if (i == '-' && st == 1) { continue; }
		if (!isdigit(i)) return false;
		st++;
	}
	return true;
}

std::vector<intMatrix> generateIntMatrixes(int row, int col, int amount, int min, int max)
{
	std::vector<intMatrix> intMatrixes;
	intMatrix matrix(row, col);
	for (int i = 0; i < amount; i++)
	{
		matrix = generateSingleIntMatrix(row, col, min, max);
		intMatrixes.push_back(matrix);
	}
	return intMatrixes;
}

intMatrix generateSingleIntMatrix(int row, int col, int min, int max)
{
	intMatrix matrix(row, col);
	matrix.setValue(min, max);

	return matrix;
}

std::vector<floatMatrix> generateFloatMatrixes(int row, int col, int amount, int min, int max)
{
	std::vector<floatMatrix> intMatrixes;
	floatMatrix matrix(row, col);
	for (int i = 0; i < amount; i++)
	{
		matrix = generateSingleFloatMatrix(row, col, min, max);
		intMatrixes.push_back(matrix);
	}
	return intMatrixes;
}
	

floatMatrix generateSingleFloatMatrix(int row, int col, int min, int max)
{
	floatMatrix matrix(row, col);
	matrix.setValue(min, max);

	return matrix;
}

void toPrintIntMatrix(std::vector<intMatrix> matrixes)
{
	for (int i = 0; i < matrixes.size(); i++)
	{
		std::cout << "\nint matrix #" << i + 1<<": ";
		matrixes[i].printMatrix();
	}
}

void toPrintFloatMatrix(std::vector<floatMatrix> matrixes) {

	for (int i = 0; i < matrixes.size(); i++)
	{
		std::cout << "\nfloat matrix #" << i + 1 << ": ";
		matrixes[i].printMatrix();
	}
}

std::vector<intMatrix> toUpInt(std::vector<intMatrix> matrixes) {

	for (int i = 0; i < matrixes.size(); i++)
	{
		matrixes[i].valueUp();
	}
	return matrixes;
}

std::vector<floatMatrix> toDownFloat(std::vector<floatMatrix> matrixes) {

	for (int i = 0; i < matrixes.size(); i++)
	{
		matrixes[i].valueDown();
	}
	return matrixes;
}

float findAverage(std::vector<intMatrix> intmatrixes, std::vector<floatMatrix> floatmatrixes) {

	float min_counter_int = floatmatrixes[0].countAverage();
	float min_counter_float = intmatrixes[0].countAverage();
	float avFl = 0, avInt = 0;
	int findex = 0;
	int index = 0;

	for (int i = 0; i < intmatrixes.size(); i++)
	{
		avFl = floatmatrixes[i].countAverage();
		avInt = intmatrixes[i].countAverage();
		if (avInt < min_counter_int) { min_counter_int = avInt; index = i; }
		if (avFl < min_counter_float) { min_counter_float = avFl; findex = i; }
	}

	if (min_counter_float <= min_counter_int) {
		std::cout << "\n\nFloat matrix #" << findex + 1 << " with min av:\n"; floatmatrixes[findex].printMatrix(); return min_counter_float;}
	if(min_counter_float > min_counter_int) { std::cout << "\n\nInt matrix #" << index + 1 << " with min av:\n"; intmatrixes[index].printMatrix(); return min_counter_int; }
}