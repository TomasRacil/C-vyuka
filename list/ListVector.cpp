// list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <vector>

int main()
{
    int a[6]{ 1,2,3,4,5,6 };
    std::list<int> l{ 6,5,4,3,2,1 };
    std::vector<int> v{ 1,2,3,4,5,6 };
    
    for (int i : a) {
        std::cout << i << std::endl;
    }
    for (int i : l) {
        std::cout << i << std::endl;
    }
    for (int i : v) {
        std::cout << i << std::endl;
    }
}
