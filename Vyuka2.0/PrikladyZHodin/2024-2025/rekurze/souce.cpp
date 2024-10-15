#include <stdio.h>
#include <iostream>

using namespace std;

void rekurze(double level)
{
    // printf("\33[2K\r");
    // printf("\n", level);
    cout << level << endl;
    rekurze(level + 1);
}

int main()
{
    rekurze(1);
    return 0;
}