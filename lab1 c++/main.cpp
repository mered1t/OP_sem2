#include <iostream>
#include "Header.h"

int main()
{
    string intoFile = "inFile.txt";

    inputFile(intoFile);

    cout << endl << "Text:\n";
    printFile(intoFile);

    string endFile = "finalFile.txt";
    cout << "New text:\n";

    changeFile(intoFile, endFile);
    printFile(endFile);

    cin.ignore(0, '\n');
    cin.get();
}

