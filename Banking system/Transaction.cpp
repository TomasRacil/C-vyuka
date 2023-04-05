#include "Transaction.h"

Transaction::Transaction(int from, int to, int amount, Date date)
{
	this->from = from;
	this->to = to;
	this->amount = amount;
	this->date = date;
}

Transaction::Transaction(std::string transaction)
{
	std::stringstream ss(transaction);
	std::vector<std::string> items;
	std::string item;
	while (std::getline(ss, item, ';')) {
		items.push_back(item);
	}
	from = stoi(items[0]);
	to = stoi(items[1]);
	amount = stoi(items[2]);
	date = Date(items[3]);
}

bool Transaction::isConectedToAccount(int account)
{
	if (from == account or to == account) return true;
	return false;
}

bool Transaction::isIncoming(int account)
{
	if (to == account) {
		return true;
	}
	return false;
}

int Transaction::getAmount()
{
	return amount;
}

Date Transaction::getDate()
{
	return date;
}

bool Transaction::operator<(const Transaction& obj)
{
	if (this->date < obj.date) {
		return true;
	}
	return false;
}

Date::Date()
{
}

Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::Date(std::string date)
{
	std::stringstream ss(date);
	std::vector<std::string> items;
	std::string item;
	while (std::getline(ss, item, '.')) {
		items.push_back(item);
	}
	day = stoi(items[0]);
	month = stoi(items[1]);
	year = stoi(items[2]);
}

bool Date::operator<(const Date& obj)
{
	if (year < obj.year) return true;
	else if (year > obj.year) return false;
	else {
		if (month < obj.month) return true;
		else if (month > obj.month) return false;
		else {
			if (day < obj.day) return true;
			else return false;
		}
	}
	return false;
}

std::ostream& operator<<(std::ostream& out, const Date& obj)
{
	out << obj.day << "." << obj.month << "." << obj.year;
	return out;
}

std::ostream& operator<<(std::ostream& out, const Transaction& obj)
{
	out << obj.from<<";"<<obj.to<<";"<<obj.amount<<";"<<obj.date;
	return out;
}
