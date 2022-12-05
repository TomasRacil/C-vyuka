// Containers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <forward_list>
#include <forward_list>

template <class ForwardIter>
void print(ForwardIter begin, ForwardIter end)
{
    for (; begin != end; ++begin)
        std::cout << *begin << " ";
    std::cout << std::endl;
}
//template <class C>
//void prit2(C iterable) {
//    for (auto a : iterable)
//        std::cout << a << " ";
//    std::cout << std::endl;
//}

int main()
{
    //Sequence containers
    // 
    //Vector
    //Constructor
    std::vector<int> v1{ 1, 2 };
    //Filling vector with values
    for (int i = 3; i <= 5; i++)
        v1.push_back(i);

    std::cout << "Vector size: " << v1.size() << std::endl;
    std::cout << "Vector capacity: " << v1.capacity() << std::endl;
    std::cout << "Vecotr max-size: " << v1.max_size() << std::endl;
    v1.reserve(20);
    v1.resize(15);
    std::cout << "Vector size: " << v1.size() << std::endl;
    std::cout << "Vector capacity: " << v1.capacity() << std::endl;
    std::cout << "Vecotr max-size: " << v1.max_size() << std::endl;
    v1.shrink_to_fit();
    std::cout << "Vector size: " << v1.size() << std::endl;
    std::cout << "Vector capacity: " << v1.capacity() << std::endl;
    std::cout << "Vecotr max-size: " << v1.max_size() << std::endl;

    if (v1.empty())
        std::cout << "Vector is empty" << std::endl;
    else
        std::cout << "Vector is not empty" << std::endl;

    std::cout << "Vector values: ";
    for (auto i = v1.begin(); i != v1.end(); ++i)
        std::cout << *i << " ";
    std::cout << std::endl;

    std::cout << "First element: " << v1.front() << std::endl;
    std::cout << "Last element: " << v1.back() << std::endl;
    std::cout << "Element at 2nd index: " << v1.at(2) << std::endl;
    v1.pop_back();
    std::cout << "Vector values: ";
    print(v1.begin(), v1.end());
    

    //List
    std::list<int> l1 { 2, 1, 3, 2};
    std::cout << "List values: ";
    print(l1.begin(), l1.end());
    l1.sort();
    print(l1.begin(), l1.end());
    l1.unique();
    print(l1.begin(), l1.end());
    l1.merge({ 5,6,7 });
    print(l1.begin(), l1.end());
    l1.pop_front();
    print(l1.begin(), l1.end());

    //deque
    std::deque<int> dq1{ 5,6 };

    //forward list
    std::forward_list<int> fl1;
    fl1.assign({ 3,4,5 });
    for (auto a : fl1)
        std::cout << a << " ";
    std::cout << std::endl;

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
