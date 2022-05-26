#pragma once

#include <iostream>
#include <iomanip>
#include <cstdlib>

class Matrix {
public:
    Matrix(int);
    ~Matrix();
    Matrix(const Matrix&);
    void fillHandM();
    void fillRandM();
    void printMatrix();
    float findDiagSum();
private:
    int size;
    double** m;
    void allowSpace();
};
