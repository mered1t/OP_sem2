#pragma once

#include "parentclass.h"
#include "subclasses.h"

#include <iostream>
#include <string>
#include <ctime>
#include <vector>

void enterSize(int&, int&);
int getAmount();
void getRandMinMax(int&, int&);

bool isNumber(std::string&);

std::vector<intMatrix> generateIntMatrixes(int, int, int, int, int);
intMatrix generateSingleIntMatrix(int, int, int, int);

std::vector<floatMatrix> generateFloatMatrixes(int, int, int, int, int);
floatMatrix generateSingleFloatMatrix(int, int, int, int);

void toPrintIntMatrix(std::vector<intMatrix>);
void toPrintFloatMatrix(std::vector<floatMatrix>);

std::vector<intMatrix> toUpInt(std::vector<intMatrix>);
std::vector<floatMatrix> toDownFloat(std::vector<floatMatrix>);

float findAverage(std::vector<intMatrix>, std::vector<floatMatrix>);