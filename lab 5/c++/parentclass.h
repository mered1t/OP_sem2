#pragma once

#include <ctime>
#include <stdlib.h>
#include <iostream>
#include <iomanip>

class TMatrix {
protected:
	int row;
	int col;
public:
	TMatrix(int, int);
	virtual void valueUp() = 0;
	virtual void valueDown() = 0;
	virtual float countAverage() = 0;
	virtual void setValue(int, int) = 0;
};