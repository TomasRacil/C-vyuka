#include "Account.h"
#include "Bank.h"

Account::Account(int account, Bank* bank)
{
	this->account = account;
	this->balance = 0;
	this->bank = bank;
	this->transactions = {};
	this->updateTransactions();
}

void Account::caculateBalance()
{
	balance = 0;
	for (Transaction t : this->transactions) {
		if (t.isIncoming(this->account)) balance += t.getAmount();
		else balance -= t.getAmount();
	}
}

void Account::makePayment(int to, int amount, Date date)
{
	bank->createTransaction(this->account, to, amount, date);
	updateTransactions();
}

void Account::updateTransactions()
{
	this->transactions = bank->getAccountTransactions(this->account);
	this->caculateBalance();
}

void Account::showTransactionAfter(Date date)
{
	std::cout << account << ": transactions after: " << date << ":" << std::endl;
	for (Transaction t : transactions) {
		if (!(t.getDate() < date)) std::cout << t << std::endl;
	}
}

void Account::showTransactionBefore(Date date)
{
	std::cout << account << ": transactions before: " << date << ":" << std::endl;
	for (Transaction t : transactions) {
		if (t.getDate() < date) std::cout << t << std::endl;
	}
}

std::ostream& operator<<(std::ostream& out, Account& obj)
{
	obj.updateTransactions();
	out << "Account: " << obj.account << std::endl;
	out << "Balance: " << obj.balance << std::endl;
	for (const Transaction& t : obj.transactions) {
		out << t << std::endl;
	}
	return out;
}
