#include <iostream>

template <typename T>
class Box
{
public:
    Box(T value) : data(value) {}

    T getValue() const { return data; }

private:
    T data;
};

int main()
{
    Box<int> intBox(10);
    std::cout << "Integer value: " << intBox.getValue() << std::endl;

    Box<double> doubleBox(3.14);
    std::cout << "Double value: " << doubleBox.getValue() << std::endl;

    Box<std::string> stringBox("Hello");
    std::cout << "String value: " << stringBox.getValue() << std::endl;

    return 0;
}