#include "ShoppingList.h"

ShoppingList::ShoppingList()
{
	discount = 0.0;
}

ShoppingList::ShoppingList(std::string path)
{
	std::ifstream file;
	file.open(path);
	std::string line;
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string item;
		std::vector<std::string> elems;
		while (std::getline(ss, item, ';')) {
			elems.push_back(item);
		}
		items.push_back(Item(elems[0], elems[1], std::stof(elems[2]), elems[3]));
	}
	std::sort(items.begin(), items.end(), [](Item li, Item ri) {
		return li < ri;
		});
	discount = 0.0;
}

void ShoppingList::addItem(Item item)
{
	items.push_back(item);
	std::sort(items.begin(), items.end());
}

Item* ShoppingList::getItem(std::string name)
{
	auto it = items.begin();
	auto end = items.end();
	for (int idx = 0; it + idx < end; idx++) {
		if ((it+idx)->getName() == name) {
			return &(*(it + idx));
		}
	}
	throw std::out_of_range("Item not in list");
}

ShoppingList ShoppingList::getItemsByCategory(std::string category)
{
	ShoppingList c = ShoppingList();
	for (Item i : items) {
		if (i.getCategory() == category) {
			Item ic = Item(i.getName(), i.getCategory(), i.getPrice(), i.getCurency());
			c.addItem(ic);
		}
	}
	return c;
}

void ShoppingList::changeDicount(float discount)
{
	this->discount = discount;
}

std::string ShoppingList::calculateTotalPrice(std::string curency)
{
	float sum = 0.0;
	for (Item i : items) {
		if (i.getCurency() != curency) {
			i.changeCurency();
			sum += i.getPrice();
			i.changeCurency();
		}
		else
		{
			sum += i.getPrice();
		}
	}
	std::string out = "Total price is " + std::to_string(sum) + " " + curency+"\n";
	if (discount > 0) {
		out+= "Price after discount " + std::to_string(sum * ((100 - discount) / 100)) + " " + curency + "\n";
	}
	return out;
}

std::ostream& operator<<(std::ostream& out, ShoppingList& m)
{
	for (Item i : m.items) {
		out << i;
		if (m.discount != 0.0) {
			Item d = i.discountedItem(m.discount);
			out << d;
		}
	}
	return out;
}
