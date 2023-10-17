// DynamicArrays.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>

using namespace std;

int main()
{
    //int myArray[5];
    int size;
    cout << "Size: ";
    cin >> size;

    int* myArray = new int[size];

    for (int i = 0; i < size; i++) {
        cout << "Array[" << i << "] ";
        cin >> myArray[i];
    }
    for (int i = 0; i < size; i++) {
        cout << myArray[i] << "\t";
        //cout << *(myArray+i) << "\t";
    }

    delete[]myArray; // nezbytne u dynamicky alokovanych poli
    myArray = NULL;

    return 0;
    //.
}