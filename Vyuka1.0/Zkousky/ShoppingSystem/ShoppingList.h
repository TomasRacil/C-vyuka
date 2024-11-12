#pragma once
#include <algorithm>
#include <fstream>
#include <ostream>
#include <sstream>
#include <vector>
#include "Item.h"

class ShoppingList
{
private:
	std::vector<Item> items;
	float discount;
public:
	ShoppingList();
	ShoppingList(std::string file);
	void addItem(Item item);
	Item* getItem(std::string name);
	ShoppingList getItemsByCategory(std::string category);
	void changeDicount(float discount);
	std::string calculateTotalPrice(std::string curency);
	friend std::ostream& operator<<(std::ostream& out, ShoppingList& m);
};

