// Recursion.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>

using namespace std;

int factorial(int num) {
    /*
    * Rekruzivni fuknce pro spocitani faktorialu 
    */
    if (num > 0) {
        return num*factorial(num-1);
    }
    else {
        return 1;
    }
}

int main()
{
    cout<<factorial(3);
}
