#include "Header.h"

struct writeDate {
	char day[4];
	char month[4];
	int year;
};

struct Composition {
	char nameOfText[21];
	int rYear;
	writeDate wDate;
};

void createFile(const string& name) {
	ofstream file;
	string ans;
	cout << "Do you want to rewrite information (Y/N)? ";
	cin >> ans;
	while (ans != "Y" && ans != "y" && ans != "N" && ans != "n") {
		cout << "Wrong, enter 'Y' or 'N': ";
		cin >> ans;
	}
	if (ans == "Y" or ans == "y") file.open(name, ios::binary);
	else file.open(name, ios::binary | ios::app);

	int numb = getNumOfTexts();
	for (int i = 0; i < numb; ++i)
	{
		Composition text = inputInfo();
		file.write((char*)&text, sizeof(Composition));
		cout << "Info are now in the file" << endl << endl;
	}
	file.close();
}

int getNumOfTexts() {

	string numb;
	cout << "Enter the number of compositons: ";
	cin >> numb;
	cin.ignore();
	while (stoi(numb) < 1 || !isNumber(numb)) {
		cout << "Enter correct number(positive): ";
		cin >> numb;
		cin.ignore();
	}
	return stoi(numb);
}

Composition inputInfo() {
	Composition txt{};

	strcpy_s(txt.nameOfText, getTextName().c_str());
	strcpy_s(txt.wDate.day, getDay().c_str());
	strcpy_s(txt.wDate.month, getMonth().c_str());
	txt.wDate.year = getYearWrite();
	txt.rYear = getYearRelease(txt.wDate.year);
	return txt;
}


string getTextName() {
	string name;
	cout << "Enter name of text, up to 20 symbols: ";
	cin >> name;
	while (name.length() > 20) {
		cout << "The name is long, enter again: ";
		cin >> name;
	}
	return name;
}

string getDay() {

	string d;
	cout << "Enter the day from 1 to 31: ";
	cin >> d;
	cin.ignore();
	while (!isNumber(d) || stoi(d) < 1 || stoi(d) > 31) {
		cout << "Enter correct day: ";
		cin >> d;
	}
	if (stoi(d) < 10) { d = '0' + d; }
	return d + '.';
}

string getMonth() {
	string m;
	cout << "Enter the month from 1 to 12: ";
	cin >> m;
	while (!isNumber(m) || stoi(m) < 1 || stoi(m) > 12) {
		cout << "Enter correct month: ";
		cin >> m;
	}
	if (stoi(m) < 10) { m = '0' + m; }
	return m + '.';
}

int getYearWrite() {
	string y;
	cout << "Enter the year of writing, up to 2022: ";
	cin >> y;
	cin.ignore();
	while (!isNumber(y) || stoi(y) < 1 || stoi(y) > 2022)
	{
		cout << "Enter correct year: ";
		cin >> y;
	}
	return stoi(y);
}

int getYearRelease(int writeYear) {
	string y;
	cout << "Enter the year of release(if not released enter 0): ";
	cin >> y;
	cin.ignore();
	if (y != "0") {
		while (!isNumber(y) || stoi(y) < writeYear || stoi(y) > 2022 || stoi(y) < 0)
		{
			cout << "Enter correct year: ";
			cin >> y;
			if (y == "0") { return stoi(y); }
		}
	}
	return stoi(y);
}

bool isNumber(const string& word) {
	for (char i : word) {
		if (!isdigit(i)) return false;
	}
	return true;
}

void showList(const string& fileName) {
	Composition txt{};
	ifstream file(fileName, ios::binary);
	while (file.read((char*)&txt, sizeof(Composition))) {
		string name(txt.nameOfText), day = (txt.wDate.day), month = txt.wDate.month;
		string wYear = to_string(txt.wDate.year), rYear = to_string(txt.rYear), accR = rYear;
		if (rYear == "0") { accR = "Not released"; }
		cout << setw(15) << "Name: " << name << endl << setw(23) << " Written date: "
			<< day << month << wYear << endl << setw(23) << " Release year: " << accR << "\n\n";
	}
	cin.ignore();
	file.close();
}

void changeList(const string& readFile, const string& writeFile) {
	Composition txt{};
	ofstream outFile(writeFile, ios::binary);
	ifstream inFile(readFile, ios::binary);

	while (inFile.read((char*)&txt, sizeof(Composition))) {
		if (txt.wDate.year > 2018) { outFile.write((char*)&txt, sizeof(Composition)); }
	}
	inFile.close();
	outFile.close();
}

void outOther(const string& inFile) {
	Composition txt{};
	ifstream file(inFile, ios::binary);

	while (file.read((char*)&txt, sizeof(Composition))) {
		if ((txt.rYear - txt.wDate.year) > 5)
		{
			string name(txt.nameOfText), day = (txt.wDate.day), month = txt.wDate.month;
			string wYear = to_string(txt.wDate.year), rYear = to_string(txt.rYear);
			cout << setw(15) << "Name: " << name << endl << setw(23) << " Written date: "
				<< day << month << wYear << endl << setw(23) << " Release year: " << rYear << "\n\n";
		}
	}
	cin.ignore();
	file.close();
}