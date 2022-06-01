#pragma once

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

class Matrix {
private:
    int size;
    float** m;
public:
    Matrix(int);
    Matrix(const Matrix&);
    Matrix();
    void setHand();
    void setRand(std::string);
    void printM();
    float findDet();

    Matrix operator++(int);
    Matrix operator*(Matrix&);
};
