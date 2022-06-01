#include "functions.h"

int main()
{
    srand(time(NULL));
    Info();

    Matrix M1; GenerateMatrix(1, M1);
    Matrix M2(3); GenerateMatrix(2, M2);
    Matrix M3(M1); 

    std::cout << "\n1)\n "; M1.printM();
    std::cout << "2)"; M2.printM();
    std::cout << "3)"; M3.printM();

    std::cout << "\nM3 = M1 * M2:\n";
    M3 = M1 * M2;
    M3.printM();
    
    std::cout << "Increment M3:";
    M3++;
    M3.printM();

    float det = M3.findDet();
    std::cout << "Determinant M3 = "<<det;
    std::cin.ignore(1);
}
