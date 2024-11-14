#include <iostream>

void vypisHodnotu(void *ukazatel, char typ)
{
    if (typ == 'i')
    {
        int *intUkazatel = static_cast<int *>(ukazatel);
        std::cout << "Hodnota (int): " << *intUkazatel << std::endl;
    }
    else if (typ == 'd')
    {
        double *doubleUkazatel = static_cast<double *>(ukazatel);
        std::cout << "Hodnota (double): " << *doubleUkazatel << std::endl;
    }
}

int main()
{
    int cislo = 10;
    double desetinneCislo = 3.14;

    vypisHodnotu(&cislo, 'i');
    vypisHodnotu(&desetinneCislo, 'd');

    return 0;
}