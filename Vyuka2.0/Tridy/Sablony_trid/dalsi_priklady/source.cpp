// TemplateClasses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

template <typename T, int N>
class Array
{
public:
    void fillArray(T val);
    void print();
    T *at(int idx);

private:
    T items[N];
};

int main()
{
    Array<int, 10> ar1;
    ar1.fillArray(1);
    *ar1.at(1) = 2;
    ar1.print();

    Array<std::string, 10> ar2;
    ar2.fillArray("a");
    *ar2.at(1) = "b";
    ar2.print();
}

template <typename T, int N>
void Array<T, N>::fillArray(T val)
{
    for (int i = 0; i < N; i++)
    {
        items[i] = val;
    }
}

template <typename T, int N>
void Array<T, N>::print()
{
    for (int i = 0; i < N; i++)
    {
        std::cout << items[i] << ", ";
    }
    std::cout << std::endl;
}

template <typename T, int N>
T *Array<T, N>::at(int idx)
{
    return &items[idx];
}
