#pragma once
#include <string>
#include <iostream>
class Item
{
private:
	std::string name;
	std::string category;
	std::string curency;
	float price;
	float czk_to_eur = 25.5;
public:
	Item(std::string name, std::string category, float price, std::string curency);
	void changeCurency();
	std::string getName();
	std::string getCategory();
	std::string getCurency();
	float getPrice();
	Item discountedItem(float discount);
	bool operator < (Item const& obj);
	friend std::ostream& operator<<(std::ostream& out, Item& m);
};

