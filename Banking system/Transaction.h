#pragma once
#include <string>
#include <sstream>
#include <vector>

struct Date
{
	int year;
	int month;
	int day;

	Date();
	Date(int day, int month, int year);
	Date(std::string date);
	bool operator<(const Date& obj);
	friend std::ostream& operator<<(std::ostream& out, const Date& obj);
};

class Transaction
{
private:
	int from;
	int to;
	int amount;
	Date date;

public:
	Transaction(int from, int to, int amount, Date date);
	Transaction(std::string transaction);
	bool isConectedToAccount(int account);
	bool isIncoming(int account);
	int getAmount();
	Date getDate();
	bool operator<(const Transaction& obj);
	friend std::ostream& operator<<(std::ostream& out, const Transaction& obj);
};

