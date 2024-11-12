// 1MatrixOperations.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>

using namespace std;

struct Matrix {
	int** arr;
	int rows;
	int cols;
};

Matrix* initRandMatrix(int rows, int cols);
Matrix* initMatrix(int rows, int cols);
void randFillMatrix(Matrix* mat);
void showMatrix(Matrix* mat);
Matrix* sumMatrix(Matrix* A, Matrix* B);
Matrix* multiplyMatrixScalar(Matrix* A, int sclr);
Matrix* matrixMultiplication(Matrix* A, Matrix* B);
void deleteMatrix(Matrix* mt);

int main()
{
	int rows, cols;

	cout << "Zadej pocet radku a sloupcu matice A: " << endl;
	cin >> rows >> cols;
	Matrix* A = initRandMatrix(rows, cols);
	showMatrix(A);

	cout << "Zadej pocet radku a sloupcu matice B: " << endl;
	cin >> rows >> cols;
	Matrix* B = initRandMatrix(rows, cols);
	showMatrix(B);

	bool run = true;

	while (run)
	{
		cout << "Zadej operaci k provedeni 0-Zobraz matice; 1-Secti matice; 2-Vynasob skalrem; 3-vynasob mezi sebou; 4-smaz matice a ukonci program: " << endl;
		int option;
		cin >> option;
		cout << endl;
		switch (option) {
		case 0:
		{
			showMatrix(A);
			showMatrix(B); 
			break;
		}
		case 1:
		{
			Matrix* C = sumMatrix(A, B);
			if (C != nullptr) {
				showMatrix(C);
			}
			else {
				cout << "Neplatna operace" << endl;
			}
			deleteMatrix(C);
			break;
		}
		case 2:
		{
			cout << "Zadej skalar: ";
			int sclr;
			cin >> sclr;
			Matrix* D = multiplyMatrixScalar(A, sclr);
			showMatrix(D);
			deleteMatrix(D);
			break;
		}
		case 3:
		{
			Matrix* E = matrixMultiplication(A, B);
			if (E != nullptr) {
				showMatrix(E);
			}
			else {
				cout << "Neplatna operace" << endl;
			}
			deleteMatrix(E); 
			break;
		}
		case 4: 
		{
			deleteMatrix(B);
			showMatrix(B);
			deleteMatrix(A);
			showMatrix(A);
			run = false;
			break;
		}
			
		}
	}

	}

Matrix* initRandMatrix(int rows, int cols)
{
	Matrix* newM = initMatrix(rows, cols);
	randFillMatrix(newM);
	return newM;
}

Matrix* initMatrix(int rows, int cols)
{
	Matrix* newM = new Matrix;
	newM->rows = rows;
	newM->cols = cols;
	newM->arr = new int* [rows];
	for (int i = 0; i < rows; ++i) {
		newM->arr[i] = new int[cols];
	}
	return newM;
}
void randFillMatrix(Matrix* mat) {
	srand(time(0));
	for (int i = 0; i < mat->rows; ++i) {
		for (int j = 0; j < mat->cols; ++j) {
			mat->arr[i][j] = (int)rand() % 10;
		}
	}
}

void showMatrix(Matrix* mat)
{
	if (mat != nullptr) {
		for (int i = 0; i < mat->rows; i++) {
			for (int j = 0; j < mat->cols; j++) {
				cout << mat->arr[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}

Matrix* sumMatrix(Matrix* A, Matrix* B)
{
	if (A->rows == B->rows && A->cols == B->cols) {
		Matrix* newM = initMatrix(A->rows, A->cols);
		for (int i = 0; i < newM->rows; ++i) {
			for (int j = 0; j < newM->cols; ++j) {
				newM->arr[i][j] = A->arr[i][j] + B->arr[i][j];
			}
		}
		return newM;
	}
	else
	{
		return nullptr;
	}
	
}

Matrix* multiplyMatrixScalar(Matrix* A, int sclr)
{
	Matrix* newM = initMatrix(A->rows, A->cols);
	for (int i = 0; i < newM->rows; ++i) {
		for (int j = 0; j < newM->cols; ++j) {
			newM->arr[i][j] = A->arr[i][j] * sclr;
		}
	}
	return newM;
}

Matrix* matrixMultiplication(Matrix* A, Matrix* B)
{
	if (A->cols == B->rows) {
		Matrix* newM = initMatrix(A->rows, B->cols);
		for (int i = 0; i < newM->rows; i++) {
			for (int j = 0; j < newM->cols; j++) {
				newM->arr[i][j] = 0;
				for (int x = 0; x < A->cols; x++) {
					newM->arr[i][j] += A->arr[i][x] * B->arr[x][j];
				}
			}
		}
		return newM;
	}
	else
	{
		return nullptr;
	}
}

void deleteMatrix(Matrix* mat)
{
	if (mat != nullptr) {
		for (int i = 0; i < mat->rows; i++) {
			delete[] mat->arr[i];
		}
		delete[] mat->arr;
		mat->arr = nullptr;
		delete mat;
		mat = nullptr;
	}
}