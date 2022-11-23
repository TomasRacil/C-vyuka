// FriendFunction1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// OperatorOvrloading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Complex {
private:
    int real, imag;
public:
    Complex(int r = 0, int i = 0) { real = r;   imag = i; }

    // This is automatically called when '+' is used with
    // between two Complex objects
    Complex operator + (Complex const& obj) {
        Complex res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        return res;
    }
    friend std::ostream& operator << (std::ostream& out, const Complex& c);
    friend std::istream& operator >> (std::istream& in, Complex& c);
};

std::ostream& operator << (std::ostream& out, const Complex& c)
{
    out << c.real;
    out << " + " << c.imag << "i" << std::endl;
    return out;
}

std::istream& operator >> (std::istream& in, Complex& c)
{
    std::cout << "Enter Real Part ";
    in >> c.real;
    std::cout << "Enter Imaginary Part ";
    in >> c.imag;
    return in;
}

int main()
{
    Complex c1;
    std::cin >> c1;
    std::cout << c1 << std::endl;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
