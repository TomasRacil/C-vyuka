

#include <iostream>

#include "Transaction.h"
#include "Bank.h"
#include "Account.h"

int main()
{
	Date d = Date(5,3,2023);
	std::cout << d << std::endl;
	Transaction t = Transaction("1;2;538;1.1.2023");
	std::cout << t << std::endl;
	Bank b = Bank("bank.txt");
	std::cout << b << std::endl;
	Account a1 = b.getAccount(1);
	Account a2 = b.getAccount(2);
	std::cout << a1 << std::endl << a2 << std::endl;
	a2.makePayment(1, 100, Date(7, 3, 2023));
	a1.makePayment(2, 10000, Date(7,3,2023));
	std::cout << a1 << std::endl << a2 << std::endl;
	a1.showTransactionBefore(d);
	a1.showTransactionAfter(d);
}

