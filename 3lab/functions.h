#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "class.h"
using namespace std;

void Info();
int chooseM(int);
int getCountMatrix();
int getSize();
void showMatrix(vector<Matrix>);
Matrix GenerateMatrix(int, int, Matrix);
vector<Matrix> GenerateMatrixArray(vector<Matrix>);
void findDiagSum(vector<Matrix>);
bool isNumber(const string&);
