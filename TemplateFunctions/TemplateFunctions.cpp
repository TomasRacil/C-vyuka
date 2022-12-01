// TemplateFunctions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void print(int x) {
    std::cout << x << std::endl;
}
void print(float x) {
    std::cout << x << std::endl;
}
void print(double x) {
    std::cout << x << std::endl;
}

template<typename T>
void print(T x) {
    std::cout << x << std::endl;
}

template<typename T>
T squareArea(T a, T b) {
    return a * b;
}

int main()
{
    print(5);
    print(5.5f);
    print(5.5);

    print(squareArea<int>(5, 1.5));
    print(squareArea<float>(5, 1.5));
    print(squareArea<double>(5, 1.5));
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
