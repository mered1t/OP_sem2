#pragma once

#include <iostream>

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

    void allocSpace();
};