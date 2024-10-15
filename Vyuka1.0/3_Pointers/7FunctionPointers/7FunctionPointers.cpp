// 7FunctionPointers.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>

using namespace std;

int getNumber();
int sum(int a, int b);

bool ascendigCompare(int a, int b);
bool descendingCompare(int a, int b);

void ascendingSort(int* array, int size);
void descendingSort(int* array, int size);

void customSort(int* array, int size, bool(*compFunc)(int, int));

void printArray(int* array, int size);


int main()
{
    cout << getNumber << endl;
    cout << getNumber() << endl;

    int(*fPtr)() = getNumber;
    cout << fPtr() << endl;

    int(*fPtr2)(int, int) = sum;
    cout << fPtr2(3,4) << endl;
    cout << sum(5, 1) << endl;

    int numbers[5] = { 8,4,9,3,6 };

    printArray(numbers, 5);
    ascendingSort(numbers, 5);
    printArray(numbers, 5);
    descendingSort(numbers, 5);
    printArray(numbers, 5);
    customSort(numbers, 5, ascendigCompare);
    printArray(numbers, 5);


    return 0;
}

int getNumber() {
    return 5;
}

int sum(int a, int b) {
    return a + b;
}

bool ascendigCompare(int a, int b)
{
    return a>b;
}

bool descendingCompare(int a, int b)
{
    return a<b;
}

void ascendingSort(int* array, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (ascendigCompare(array[i], array[j])) {

                /*int temp = array[i];
                array[i] = array[j];
                array[j] = temp;*/
                array[i] = array[i] + array[j];
                array[j] = array[i] - array[j];
                array[i] = array[i] - array[j];
            }
        }
    }
}

void descendingSort(int* array, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (descendingCompare(array[i], array[j])) {

                /*int temp = array[i];
                array[i] = array[j];
                array[j] = temp;*/
                array[i] = array[i] + array[j];
                array[j] = array[i] - array[j];
                array[i] = array[i] - array[j];
            }
        }
    }
}

void customSort(int* array, int size, bool(*compFunc)(int, int))
{
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (compFunc(array[i], array[j])) {
                /*int temp = array[i];
                array[i] = array[j];
                array[j] = temp;*/
                array[i] = array[i] + array[j];
                array[j] = array[i] - array[j];
                array[i] = array[i] - array[j];
            }
        }
    }
}

void printArray(int* array, int size)
{
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}
