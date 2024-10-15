#include <iostream>

struct Matrix
{
    int** matrix;
    int rows;
    int cols;
};

Matrix* initMatrix(int rows, int cols);
void fillRMatrix(Matrix* matrix);
int** init2DArray(int rows, int cols);
void print2DMatrix(Matrix* matrix);

int main(){
    int rows, cols;
    std::cout<<"Zadej pocet radku 1. matice: ";
    std::cin>>rows;
    std::cout<<"Zadej pocet sloupcu 1. matice: ";
    std::cin>>cols;
    Matrix* matrix1 = initMatrix(rows,cols);
    fillRMatrix(matrix1);
    print2DMatrix(matrix1);

    std::cout<<"Zadej pocet radku 2. matice: ";
    std::cin>>rows;
    std::cout<<"Zadej pocet sloupcu 2. matice: ";
    std::cin>>cols;
    Matrix* matrix2 = initMatrix(rows,cols);
    fillRMatrix(matrix2);
    print2DMatrix(matrix2);

    return 0;
}

Matrix* initMatrix(int rows, int cols){
    Matrix* m = new Matrix;
    m->cols = cols;
    m->rows = rows;
    m->matrix = init2DArray(rows, cols);
    return m;
}

void fillRMatrix(Matrix* matrix){
    srand(time(0));
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            matrix->matrix[i][j]=(int)rand()%10;
        }
    }
}

int** init2DArray(int rows, int cols){
    //init array of pointers in dynamic memory to arrrays of integer
    int** matrix = new int* [rows];

    //init each array of integers in dynamic memory
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

void print2DMatrix(Matrix* matrix){
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            std::cout << matrix->matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}