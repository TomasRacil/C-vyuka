#include <iostream>

using namespace std;
void prohod(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    // *a = *a + *b;
    // *b = *a - *b;
    // *a = *a - *b;
}

int main()
{
    int a = 0, b = 1;
    cout << "Pred prohozenim: a: " << a << ",b: " << b << endl;
    prohod(&a, &b);
    cout << "Po prohozeni: a: " << a << ",b: " << b << endl;

    return 0;
}