#include "Header.h"

int main()
{
	createFile("intoTheFile.txt");
	cout << "Info:\n";
	showList("intoTheFile.txt");
	changeList("intoTheFile.txt", "OutTheFile.txt");
	cout << "Texts written for last 4 years(2019-2022):\n\n";
	showList("OutTheFile.txt");
	cout << "Texts released after 5 years from being written:\n\n";
	outOther("intoTheFile.txt");
}

