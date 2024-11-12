// 6MemoryLeaks.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>

using namespace std;

void myFunction() {
    int* ptr = new int[42000]; 
    ptr[2] = 10;
    cout << ptr[2];

    //delete ptr; // only remove the pointer not array
    delete [] ptr;
}

int main()
{
    myFunction();
    return 0;
}