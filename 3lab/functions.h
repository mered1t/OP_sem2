#pragma once

#include "ñlass.h"
#include <vector>
#include <string>

int getCountMatrix();
int chooseM(int);
int getSize();
bool isNumber(const std::string&);
Matrix GenerateMatrix(int, int);
std::vector<Matrix> GenerateMatrixArray();
void showMatrix(std::vector<Matrix>);
void findMaxDiagSum(std::vector<Matrix>);
void Info();
