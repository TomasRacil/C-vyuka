#pragma once

#include <cstdlib>
#include <ctime>
#include <iostream>

class Matrix
{
private:
	int** arr;
	int rows;
	int cols;
	void fillRandomly();
public:
	Matrix(int rows, int cols , bool random = true);
	void show();
	Matrix operator + (Matrix const& obj);
	Matrix operator - (Matrix const& obj);
	Matrix operator * (int sclr);
	Matrix operator * (Matrix const& obj);

	friend std::ostream& operator << (std::ostream& out, const Matrix& m);
	friend std::istream& operator >> (std::istream& in, Matrix& m);
	~Matrix();
};

