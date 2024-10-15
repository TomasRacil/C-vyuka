#include "Bank.h"

Bank::Bank(std::string path) {
    this->path = path;
    std::ifstream file;
    file.open(path);
    std::string line;
    while (std::getline(file, line)) {
        transactions.push_back(Transaction(line));
    }
    std::sort(this->transactions.begin(), this->transactions.end());
}

void Bank::createTransaction(int from, int to, int amount, Date date)
{
    Account a = getAccount(from);
    if (a.balance >= amount && from!=to) {
        this->transactions.push_back(Transaction(from, to, amount, date));
        std::sort(this->transactions.begin(), this->transactions.end());
    }
    else {
        std::cout << "Transaction not possible"<<std::endl;
    }
    
}

Account Bank::getAccount(int account)
{
    return Account(account, this);
}

std::vector<Transaction> Bank::getAccountTransactions(int account)
{
    std::vector<Transaction> selected_transaction;
    for (Transaction t : this->transactions) {
        if (t.isConectedToAccount(account)) selected_transaction.push_back(t);
    }
    return selected_transaction;
}

Bank::~Bank()
{
    std::ofstream file;
    file.open(this->path);
    std::stringstream out;
    for (const Transaction& t : this->transactions) {
        out << t << std::endl;
    }
    file.write(out.str().c_str(), out.str().size());
}

std::ostream& operator<<(std::ostream& out, const Bank& obj)
{
    // TODO: insert return statement here
    for (const Transaction& t : obj.transactions) {
        out << t << std::endl;
    }
    return out;
}
