#include "Item.h"

Item::Item( std::string name, std::string category, float price, std::string curency)
{
	this->name = name;
	this->category = category;
	this->price = price;
	this->curency = curency;
}

void Item::changeCurency()
{
	if (curency == "EUR") {
		price = price * czk_to_eur;
		curency = "CZK";
	}
	else
	{
		price = price / czk_to_eur;
		curency = "EUR";
	}
}

std::string Item::getName()
{
	return name;
}

std::string Item::getCategory()
{
	return category;
}

std::string Item::getCurency()
{
	return curency;
}

float Item::getPrice()
{
	return price;
}


Item Item::discountedItem(float discount)
{
	return Item(name, category, price * (100.0-discount)/100, curency);
}

bool Item::operator<(Item const& obj)
{
	if (curency != obj.curency) changeCurency();
	if (price < obj.price) {
		changeCurency();
		return true;
	}
	else {
		return false;
	}
}

std::ostream& operator<<(std::ostream& out, Item& m)
{
	out << m.name << ";" << m.category << ";" << m.price << " " << m.curency <<std::endl;
	return out;
}
