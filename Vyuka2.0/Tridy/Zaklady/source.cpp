#include <iostream>
#include <string>

using namespace std;

class Kruh
{
private:
    double polomer;

public:
    // Konstruktor
    Kruh(double r)
    {
        polomer = r;
    }

    // Metoda pro výpočet obsahu
    double obsah()
    {
        return 3.14159 * polomer * polomer;
    }

    // Metoda pro výpočet obvodu
    double obvod()
    {
        return 2 * 3.14159 * polomer;
    }
};

int main()
{
    Kruh k1(5);
    cout << "Obsah kruhu: " << k1.obsah() << endl;
    cout << "Obvod kruhu: " << k1.obvod() << endl;

    return 0;
}