#include <iostream>

using namespace std;

int vypocetFaktorialu(int cislo)
    {
        int vysledek = 1;
        for (int i = cislo; i > 0; i--)
        {
            if (cislo == 1)
                return 1;
            vysledek *= i ;
        }
        return vysledek;
    }

int main()
{
    
    cout << vypocetFaktorialu(4) << endl;

    return 0;
}