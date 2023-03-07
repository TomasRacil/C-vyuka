// ShoppingSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Item.h"
#include "ShoppingList.h"

int main()
{
    ShoppingList sl = ShoppingList("list.txt");
    sl.getItem("rohliky")->changeCurency();
    std::cout << sl << std::endl;
    ShoppingList pl = sl.getItemsByCategory("potraviny");
    std::cout << pl << std::endl;
    std::cout << pl.calculateTotalPrice("CZK") << std::endl;;
    sl.changeDicount(10);
    std::cout << sl<<std::endl;
    std::cout << sl.calculateTotalPrice("EUR") << std::endl;
}

