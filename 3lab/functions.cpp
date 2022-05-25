#include "functions.h"


int getCountMatrix() {
	string num;
	cout << "Enter the number of matrix (more than 0): ";
	cin >> num;
	while (!isNumber(num) || stoi(num) < 1) {
		cout << "Enter correct number: ";
		cin >> num;
	}
	return stoi(num);
}

int chooseM(int it) {
	string n;
	cout << "\nEnter the mode for values of matrix #"<< it + 1<< " (1 or 2): ";
	cin >> n;
	while (!isNumber(n) || stoi(n) != 1 && stoi(n) != 2) {
		cout << "Enter correct number: ";
		cin >> n;
	}
	return stoi(n);
}

int getSize() {
	string s;
	cout << "Enter the size of matrix (more than 0): ";
	cin >> s;
	while (!isNumber(s) || stoi(s) < 1) {
		cout << "Enter correct number: ";
		cin >> s;
	}
	return stoi(s);
}

Matrix GenerateMatrix(int size, int i, Matrix matrix){
	int mode = chooseM(i);

	if (mode == 1) { matrix.fillHandM(); }
	else { matrix.fillRandM(); }
	return matrix;
}

vector<Matrix> GenerateMatrixArray(vector<Matrix> matrixes){

	

	int amount = getCountMatrix();
	int size = getSize();
	for (int i = 0; i < amount; i++)
	{
		Matrix matrix(size);
		matrix = GenerateMatrix(size, i, matrix);
		matrixes.push_back(matrix);
	}
	return matrixes;
}

void showMatrix(vector<Matrix> matrixes) {
	cout << "\nInfo:\n";

	int numb = 1;
	for (int i = 0; i < matrixes.size(); i++) {
		cout <<"\n" << numb << ")  ";
		numb++;
		matrixes[i].printMatrix();
	}
}

void findDiagSum(vector<Matrix> matrixes) {
	float max = matrixes[0].findMaxDiag();
	float acc = 0;
	int ind = 0; cout << "\n";

	for (int i = 0; i < matrixes.size(); i++) {
		acc = matrixes[i].findMaxDiag();
		cout << "Sum of diagonal elements of " << i + 1 << " matrix = " << acc << "\n";
		if (max < acc) { max = acc; ind = i; }
	}
	cout << "\nThe matrix with the biggest step: #" << ind + 1<< ":";
	matrixes[ind].printMatrix();
}

bool isNumber(const string& word) {
	for (char i : word) {
		if (!isdigit(i)) return false;
	}
	return true;
}

void Info() {
	cout << "Modes of entering the values\n1 - self fill\n2 - random fill\n";
	cout << "__________________________________________\n\n";
}


