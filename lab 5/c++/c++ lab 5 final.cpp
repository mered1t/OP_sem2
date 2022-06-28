#include "functions.h"

int main()
{
    srand(time(nullptr));

    int rows, cols, min, max, amount;
    enterSize(rows, cols);
    amount = getAmount();
    getRandMinMax(min, max);

    std::cout << "\n--------Info--------\n";
    std::vector<intMatrix> intMatrixes = generateIntMatrixes(rows, cols, amount, min, max);
    std::vector<floatMatrix> floatMatrixes = generateFloatMatrixes(rows, cols, amount, min, max);
    toPrintIntMatrix(intMatrixes);
    toPrintFloatMatrix(floatMatrixes);

    floatMatrixes = toDownFloat(floatMatrixes);
    intMatrixes = toUpInt(intMatrixes);

    std::cout << "\n--------After change--------\n";
    toPrintIntMatrix(intMatrixes);
    toPrintFloatMatrix(floatMatrixes);

    float minAv = findAverage(intMatrixes, floatMatrixes);
    std::cout << "\nThe minimal average value is " << minAv;

    std::cin.ignore(2);
}

