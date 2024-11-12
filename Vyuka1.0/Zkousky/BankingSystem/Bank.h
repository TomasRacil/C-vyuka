#pragma once
#include <vector>
#include <fstream>
#include <algorithm>
//#include "Transaction.h"
#include "Account.h"

class Bank
{
private:
	std::string path;
	std::vector<Transaction> transactions;
public:
	Bank(std::string path);
	void createTransaction(int from, int to, int amount, Date date);
	Account getAccount(int account);
	std::vector<Transaction> getAccountTransactions(int account);
	~Bank();

	friend std::ostream& operator<<(std::ostream& out, const Bank& obj);
};

