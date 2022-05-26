#include "functions.h"

int getCountMatrix() {
	std::string num;
	std::cout << "Enter the number of matrix (1 or more): ";
	std::cin >> num;
	while (!isNumber(num) || stoi(num) < 1) {
		std::cout << "Enter correct number: ";
		std::cin >> num;
	}
	return stoi(num);
}

int chooseM(int it) {
	std::string n;
	std::cout << "\nEnter the mode for values of matrix #" << it + 1 << " (1 or 2): ";
	std::cin >> n;
	while (!isNumber(n) || stoi(n) != 1 && stoi(n) != 2) {
		std::cout << "Enter correct number: ";
		std::cin >> n;
	}
	return stoi(n);
}

int getSize() {
	std::string s;
	std::cout << "Enter the size of matrix (1 or more): ";
	std::cin >> s;
	while (!isNumber(s) || stoi(s) < 1) {
		std::cout << "Enter correct number: ";
		std::cin >> s;
	}
	return stoi(s);
}

Matrix GenerateMatrix(int size, int i) {
	int mode = chooseM(i);
	Matrix matrix(size);
	if (mode == 1) { matrix.fillHandM(); }
	else { matrix.fillRandM(); }
	return matrix;
}

std::vector<Matrix> GenerateMatrixArray() {
	srand(time(NULL));
	std::vector<Matrix> matrixes;

	int amount = getCountMatrix();
	int size = getSize();
	for (int i = 0; i < amount; i++)
	{
		Matrix matrix = GenerateMatrix(size, i);
		matrixes.push_back(matrix);
	}
	return matrixes;
}

void showMatrix(std::vector<Matrix> matrixes) {
	std::cout << "\nInfo:\n";

	int numb = 1;
	for (int i = 0; i < matrixes.size(); i++) {
		std::cout << "\n" << numb << ")  ";
		numb++;
		matrixes[i].printMatrix();
	}
}

void findMaxDiagSum(std::vector<Matrix> matrixes) {
	float max = matrixes[0].findDiagSum();
	float acc = 0;
	int ind = 0; std::cout << "\n";

	for (int i = 0; i < matrixes.size(); i++) {
		acc = matrixes[i].findDiagSum();
		std::cout << "Sum of diagonal elements of " << i + 1 << " matrix = " << acc << "\n";
		if (max < acc) { max = acc; ind = i; }
	}
	std::cout << "\nThe matrix with the biggest step: #" << ind + 1 << ":";
	matrixes[ind].printMatrix();
	std::cin.ignore(1);
}

bool isNumber(const std::string & word) {
	for (char i : word) {
		if (!isdigit(i)) return false;
	}
	return true;
}

void Info() {
	std::cout << "Modes of entering the values\n1 - self fill\n2 - random fill\n";
	std::cout << "__________________________________________\n\n";
}

