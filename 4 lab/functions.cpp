#include "functions.h"

int chooseM(int it) {
	std::string n;
	std::cout << "\nEnter the mode for values of matrix #" << it << " (1 or 2): ";
	std::cin >> n;
	while (!isNumber(n) || stoi(n) != 1 && stoi(n) != 2) {
		std::cout << "Enter correct number: ";
		std::cin >> n;
	}
	return stoi(n);
}

Matrix GenerateMatrix(int i, Matrix& matrix) {
	int mode = chooseM(i);
	if (mode == 2) {
		std::string ans = onlyInt(i);
		matrix.setRand(ans);
	}
	else { matrix.setHand(); }
	return matrix;
}

bool isNumber(const std::string& word) {
	for (char i : word) {
		if (!isdigit(i)) return false;
	}
	return true;
}

void Info() {
	std::cout << "Modes of entering the values\n1 - self fill\n2 - random fill\n";
	std::cout << "__________________________________________\n\n";
}

std::string onlyInt(int it)
{
	std::string ans;
	std::cout << "Create only int values for matrix #" << it << " ? (y or n): ";
	std::cin >> ans;
	while (ans!= "y" && ans!="Y" && ans!= "N" && ans!="n") {
		std::cout << "Enter correct answer: ";
		std::cin >> ans;
	}
	return ans;
}
