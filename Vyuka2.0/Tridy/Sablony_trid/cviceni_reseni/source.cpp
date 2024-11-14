#include <iostream>
#include <vector>

template <typename T>
class Stack
{
public:
    void push(T value)
    {
        data.push_back(value);
    }

    void pop()
    {
        if (!data.empty())
        {
            data.pop_back();
        }
        else
        {
            std::cout << "Chyba: Zasobnik je prazdny!" << std::endl;
        }
    }

    T top() const
    {
        if (!data.empty())
        {
            return data.back();
        }
        else
        {
            std::cout << "Chyba: Zasobnik je prazdny!" << std::endl;
            return T{}; // Vraťte defaultní hodnotu typu T
        }
    }

private:
    std::vector<T> data;
};

int main()
{
    Stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    std::cout << "Vrchol zasobniku: " << intStack.top() << std::endl; // Vypíše 30
    intStack.pop();
    std::cout << "Vrchol zasobniku po pop(): " << intStack.top() << std::endl; // Vypíše 20

    Stack<std::string> stringStack;
    stringStack.push("Ahoj");
    stringStack.push("svete!");
    std::cout << "Vrchol zasobniku: " << stringStack.top() << std::endl; // Vypíše "svete!"

    return 0;
}