#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>

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

    bool deposite(double amount )
    {
        balance += amount;
    }

    bool withdraw(double amount)
    {
        if(amount > balance )  return false;

        balance -= amount;
        return true;
    }
    virtual void display() const
    {
        cout << "\nAccount Number : " << accountNumber;
        cout << "\nName           : " << name;
        cout << "\nAccount Type   : " << accountType;
        cout << "\nBalance        : " << fixed
             << setprecision(2) << balance << endl;
    }
};

int main(void)
{
    return 0;
}