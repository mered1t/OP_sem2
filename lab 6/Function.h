#pragma once

#include "Tree.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <string> inputArr();
void printArr(vector <string>);
vector <string> enterWords();
string enterWordtoSearch();
bool isNumber(const string&);
void addToTree(vector <string>, Tree&);
void findWordnLevel(Tree&);