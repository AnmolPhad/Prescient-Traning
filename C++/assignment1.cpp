#include <iostream>
#include <string>
using namespace std;

class Account
{
protected:
    int accountNumber;
    string name;
    double balance;
    string accountType;

public:
    Account()
    {
        accountNumber = 0;
        name = "";
        balance = 0.0;
        accountType = "";
    }

    Account(int accNo, string n, double initialBalance, string type)
    {
        accountNumber = accNo;
        name = n;
        balance = initialBalance;
        accountType = type;
    }

    virtual ~Account() {}

    int getAccountNumber() const
    {
        return accountNumber;
    }

    string getName() const
    {
        return name;
    }

    double getBalance() const
    {
        return balance;
    }

    string getAccountType() const
    {
        return accountType;
    }
};

int main(void)
{
    return 0;
}