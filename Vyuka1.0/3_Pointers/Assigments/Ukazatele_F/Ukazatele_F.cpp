// Ukazatele.cpp : Tento soubor obsahuje funkci main. Provádìní programu se tam zahajuje a ukonèuje.
//

#include <iostream>

void AlokujPamet(int** data, int delka) {
    *data = (int*)malloc(sizeof(int) * delka);
    *data[0] = 1;
}

int main()
{
    int* a;
    int cislo;


    a = &cislo;
    *a = 25;

    printf("Hodnota promenne cislo je: %d\n", cislo);

    int** b;

    b = &a;
    *b = &cislo;
    **b = 50;

    printf("Hodnota promenne cislo je: %d\n", cislo);

    int* buffer = NULL;

    AlokujPamet(&buffer, 100);
    printf("Buffer data 0: %d\n", buffer[0]);
    buffer[5] = 10;
}