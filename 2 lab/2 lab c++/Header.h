#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdio>

using namespace std;

struct writeDate;
struct Composition;

void createFile(const string&);
void showList(const string&);
int getNumOfTexts();

Composition inputInfo();
string getTextName();
string getDay();
string getMonth();
bool isNumber(const string&);
int getYearWrite();
int getYearRelease(int writeYear);
void changeList(const string&, const string&);
void outOther(const string&);