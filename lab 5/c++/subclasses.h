#pragma once

#include "parentclass.h"

class intMatrix : public TMatrix {

private:
	int** iMat;
public:
	intMatrix(int, int);
	intMatrix(const intMatrix&);
	void valueUp() override;
	void valueDown() override;
	float countAverage() override;
	void setValue(int, int) override;
	void printMatrix();
	//~intMatrix();
};

class floatMatrix : public TMatrix {
private:
	float** fMat;
public:
	floatMatrix(int, int);
	floatMatrix(const floatMatrix&);
	void valueDown() override;
	void valueUp() override;
	float countAverage() override;
	void setValue(int, int) override;
	void printMatrix();
	//~floatMatrix();
};