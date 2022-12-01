#include "Matrix.h"


void Matrix::fillRandomly()
{
	std::srand(time(0));
	for (int i = 0; i < this->rows; ++i) {
		for (int j = 0; j < this->cols; ++j) {
			this->arr[i][j] = (int)std::rand() % 10;
		}
	}
}

Matrix::Matrix(int rows, int cols, bool random)
{
	this->rows = rows;
	this->cols = cols;
	this->arr = new int* [rows];
	for (int i = 0; i < rows; ++i) {
		this->arr[i] = new int[cols];
	}
	if (random) fillRandomly();
}

void Matrix::show()
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

Matrix Matrix::operator+(Matrix const& obj)
{
	if (rows == obj.rows && cols == obj.cols) {
		Matrix newM(rows, cols, false);
		for (int i = 0; i < newM.rows; ++i) {
			for (int j = 0; j < newM.cols; ++j) {
				newM.arr[i][j] = arr[i][j] + obj.arr[i][j];
			}
		}
		return newM;
	}
	else {
		throw std::invalid_argument("Scitani neni mozne. Matice maji ruznou velikost.");
	}
}

Matrix Matrix::operator-(Matrix const& obj)
{
	if (rows == obj.rows && cols == obj.cols) {
		Matrix newM(rows, cols, false);
		for (int i = 0; i < newM.rows; ++i) {
			for (int j = 0; j < newM.cols; ++j) {
				newM.arr[i][j] = arr[i][j] - obj.arr[i][j];
			}
		}
		return newM;
	}
	else {
		throw std::invalid_argument("Odcitani neni mozne. Matice maji ruznou velikost.");
	}
}

Matrix Matrix::operator*(int sclr)
{
	Matrix newM(rows, cols, false);
	for (int i = 0; i < newM.rows; ++i) {
		for (int j = 0; j < newM.cols; ++j) {
			newM.arr[i][j] = arr[i][j] * sclr;
		}
	}
	return newM;
}

Matrix Matrix::operator*(Matrix const& obj)
{
	if (cols == obj.rows) {
		Matrix newM(rows, obj.cols);
		for (int i = 0; i < newM.rows; i++) {
			for (int j = 0; j < newM.cols; j++) {
				newM.arr[i][j] = 0;
				for (int x = 0; x < cols; x++) {
					newM.arr[i][j] += arr[i][x] * obj.arr[x][j];
				}
			}
		}
		return newM;
	}
	else {
		throw std::invalid_argument("Nasobeni matic neni mozne. Matice nejsou kompatibilni.");
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < rows; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	arr = nullptr;
}

std::ostream& operator<<(std::ostream& out, const Matrix& m)
{
	// TODO: insert return statement here
	/*out << getName(m) << ": \n";*/
	for (int i = 0; i < m.rows; i++) {
		for (int j = 0; j < m.cols; j++) {
			out << m.arr[i][j] << " ";
		}
		out << "\n";
	}
	out << "\n";
	return out;
}

std::istream& operator>>(std::istream& in, Matrix& m)
{
	/// <summary>
	/// TODO reading rows from one line.
	/// </summary>
	/// <param name="in"></param>
	/// <param name="m"></param>
	/// <returns></returns>
	for (int i = 0; i < m.rows; i++) {
		for (int j = 0; j < m.cols; j++) {
			in >> m.arr[i][j];
			std::cout << " ";
		}
		std::cout << std::endl;
	}
	return in;
}
