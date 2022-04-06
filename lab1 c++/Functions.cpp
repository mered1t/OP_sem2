#include "Header.h"

void inputFile(string inFile) {

	ofstream outFile;
	outFile.open(inFile);

	cout << "Enter the text\nTo go on a new line press Enter\nTo stop writing press Ctrl + N\n";
	cout << "_______________________________\n\n";

	if (!outFile.is_open()) {
		cout << "Error: File hasn't opened";
	}
	else {
		string line;
		int breaker = 14;
		while (line[0] != breaker) {
			outFile << line << endl;
			getline(cin, line);
		}
	}
	outFile.close();
}
void printFile(string intoFile) {
	ifstream inFile;
	inFile.open(intoFile);
	if (!inFile.is_open()) {
		cout << "Error: File hasn't opened";
	}
	else {
		string line;
		while (!inFile.eof()) {
			getline(inFile, line);
			cout << line << endl;
		}
		cout << endl;
	}
	inFile.close();
}
string spaceEdit(string line) {
	int counter = 0;
	int spaceCounter = 0;
	int acc = 0;

	if (!line.empty()) {
		int i = 0;
		int length = line.length();
		if (line[0] == ' ') {
			while (line[i] == ' ') {
				i++;
			}
			line = line.erase(0, i);
		}
		length = line.length();
		if (line[length - 1] == ' ') {
			int i = length - 1;
			while (line[i] == ' ') {
				i--;
			}
			line = line.erase(i + 1);
		}

		for (int i = 1; i < line.length(); i++) {
			if (line[i] == ' ') {
				line = line.insert(i, " ");
				i++;
				spaceCounter++;
			}
		}
		line = line + " - " + to_string(spaceCounter);
	}
	return line;
}

void changeFile(string intoFile, string endFile) {
	ifstream inFile;
	ofstream newFile;
	inFile.open(intoFile);
	newFile.open(endFile);
	if (!inFile.is_open() || !newFile.is_open()) {
		cout << "Error: File hasn't opened" << endl;
	}
	else {
		while (!inFile.eof()) {
			string storage;
			getline(inFile, storage);
			storage = spaceEdit(storage);
			newFile << storage << endl;
		}
	}
	inFile.close();
	newFile.close();
}