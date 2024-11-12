#include <iostream>

class Matematika
{
public:
    static int scitani(int a, int b)
    {
        return a + b;
    }

    static int odcitani(int a, int b)
    {
        return a - b;
    }

    static int nasobeni(int a, int b)
    {
        return a * b;
    }

    static int deleni(int a, int b)
    {
        if (b == 0)
        {
            std::cout << "Chyba: Deleni nulou!" << std::endl;
            return 0;
        }
        return a / b;
    }
};

int main()
{
    // Testování metod
    std::cout << "5 + 3 = " << Matematika::scitani(5, 3) << std::endl;
    std::cout << "10 - 4 = " << Matematika::odcitani(10, 4) << std::endl;
    std::cout << "7 * 2 = " << Matematika::nasobeni(7, 2) << std::endl;
    std::cout << "15 / 3 = " << Matematika::deleni(15, 3) << std::endl;
    std::cout << "8 / 0 = " << Matematika::deleni(8, 0) << std::endl; // Test dělení nulou

    return 0;
}