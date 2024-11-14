#include <iostream>
#include <memory>

void vypisHodnotu(std::unique_ptr<int> ptr)
{
    std::cout << "Hodnota: " << *ptr << std::endl;
}

int main()
{
    std::unique_ptr<int> uniquePtr(new int(10));
    vypisHodnotu(std::move(uniquePtr));

    std::shared_ptr<int> sharedPtr1(new int(5));
    std::shared_ptr<int> sharedPtr2 = sharedPtr1;
    std::cout << "Hodnota 1: " << *sharedPtr1 << std::endl;
    std::cout << "Hodnota 2: " << *sharedPtr2 << std::endl;

    return 0;
}