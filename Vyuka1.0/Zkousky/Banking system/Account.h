#pragma once
#include <vector>
#include <iostream>
#include "Transaction.h"

class Bank;

class Account
{
private:
	int account;
	int balance;
	Bank* bank;
	std::vector<Transaction> transactions;

	void updateTransactions();
	void caculateBalance();

public:
	Account(int account, Bank* bank);
	void makePayment(int to, int amount, Date date);
	void showTransactionBefore(Date date);
	void showTransactionAfter(Date date);

	friend std::ostream& operator<<(std::ostream& out, Account& obj);
	friend class Bank;
};

