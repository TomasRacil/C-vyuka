#include <iostream>

void funkce()
{
    int *ukazatel = new int(10);
    // ... kód, který pracuje s ukazatelem ...
    // chybí delete ukazatel;
} // ukazatel zaniká na konci funkce, ale paměť zůstává alokovaná

int main()
{
    funkce();
    // ... zbytek programu ...
    return 0;
}