#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

// class Transation
class Transaction
{
public:
    string date;
    string type;
    double amount;
    string description;
    int otherAccount;

    Transaction()
    {
        date = "";
        type = "";
        amount = 0;
        description = "";
        otherAccount = -1;
    }

    Transaction(string d, string t, double a,
                string desc, int other = -1)
    {
        date = d;
        type = t;
        amount = a;
        description = desc;
        otherAccount = other;
    }

    void display() const
    {
        cout << left
             << setw(15) << date
             << setw(20) << type
             << setw(12) << fixed << setprecision(2) << amount
             << setw(25) << description;

        if (otherAccount != -1)
            cout << "Account: " << otherAccount;

        cout << endl;
    }
};

class Account
{
protected:
    int accountNumber;
    string name;
    double balance;
    string accountType;

    vector<Transaction> transaction;

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

    bool deposit(double amount)
    {
        balance += amount;
    }

    vector<Transaction> &getTransation()
    {
        return transaction;
    }

    void addTransaction(const Transaction &t)
    {
        transaction.push_back(t);
    }

    bool withdraw(double amount)
    {
        if (amount > balance)
            return false;

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

    virtual bool canCheque() const
    {
        return false;
    }

    void save() const
    {
    }
};

// Saving Account
class SavingsAccount : public Account
{
public:
    SavingsAccount() { accountType = "Savings"; }
    SavingsAccount(int accNo, string n, double balance) : Account(accNo, n, balance, "Savings") {}

    bool canCheque() const override { return false; }
};

// Checking Account
class CheckingAccount : public Account
{
public:
    CheckingAccount() { accountType = "Checking"; }
    CheckingAccount(int accNo, string s, double balance) : Account(accNo, s, balance, "Checking") {}
    bool canCheque() const override { return true; }
};

// class Bank
class Bank
{
private:
    vector<Account *> accounts;
    Account *findAccount(int accountNumber)
    {
        for (auto account : accounts)
        {
            if (account->getAccountNumber() == accountNumber)
            {
                return account;
            }
        }
        return nullptr;
    }

public:
    ~Bank()
    {
        for (auto account : accounts)
        {
            delete account;
        }
    }

    // add account

    void addAccount()
    {
        int type;
        int accountNumber = 0;
        string name;
        double initialBalance;

        cout << "\n1. Saving Acccount";
        cout << "\n2. Checking Account";
        cout << "\n Enter your choice";
        cin >> type;

        accountNumber += 1;
        // cout << "Your account number is: " << accountNumber;

        cout << "Enter customer name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter initial balance: ";
        cin >> initialBalance;

        if (initialBalance < 0)
        {
            cout << "Invalid balance.\n";
            return;
        }

        if (type == 1)
        {
            accounts.push_back(
                new SavingsAccount(accountNumber, name, initialBalance));
            cout << "Savings account created successfully. With bank accountNumber :" << accountNumber << endl;
        }
        else if (type == 2)
        {
            accounts.push_back(
                new CheckingAccount(
                    accountNumber,
                    name,
                    initialBalance));

            cout << "Checking account created successfully. With bank accountNumber :" << accountNumber << endl;
        }
        else
        {
            cout << "Invalid account type.\n";
        }
    }

    // delete account
    void deleteAccount()
    {
        int accountNumber;

        cout << "\nEnter account number to delete: ";
        cin >> accountNumber;

        for (auto it = accounts.begin(); it != accounts.end(); ++it)
        {
            if ((*it)->getAccountNumber() == accountNumber)
            {
                if ((*it)->getBalance() != 0)
                {
                    cout << "Cannot delete account with non-zero balance.\n";
                    return;
                }

                delete *it;
                accounts.erase(it);

                cout << "Account deleted successfully.\n";
                return;
            }
        }
        cout << "Account not found.\n";
    }

    // cash transaction

    void cashTransaction()
    {
        int accountNumber;
        int choice;
        double amount;
        string date;

        cout << "\nEnter account number: ";
        cin >> accountNumber;

        Account *account = findAccount(accountNumber);
        if (account == nullptr)
        {
            cout << "Account not found.\n";
            return;
        }

        cout << "Enter date (YYYY-MM-DD): ";
        cin >> date;

        cout << "\n1. Deposit Cash";
        cout << "\n2. Withdraw Cash";
        cout << "\nEnter choice: ";
        cin >> choice;

        cout << "Enter amount: ";
        cin >> amount;

        if (amount <= 0)
        {
            cout << "Invalid amount.\n";
            return;
        }

        if (choice == 1)
        {
            account->deposit(amount);

            account->addTransaction(
                Transaction(date, "Cash Deposit", amount, "Cash deposited"));

            cout << "Cash deposited successfully.\n";
        }
        else if (choice == 2)
        {
            if (!account->withdraw(amount))
            {
                cout << "Insufficient balance.\n";
                return;
            }

            account->addTransaction(
                Transaction(date, "Cash Withdrawal", amount, "Cash Withrawal"));

            cout << "Cash withdrawn successfully.\n";
        }
        else
        {
            cout << "Invalid choice.\n";
        }
    }

    // cheque transaction

    void chequeTransaction()
    {
        int fromAccount;
        int toAccount;
        double amount;
        string date;

        cout << "\nEnter sender account number: ";
        cin >> fromAccount;

        Account *sender = findAccount(fromAccount);

        if (sender == nullptr)
        {
            cout << "Sender account not found.\n";
            return;
        }

        // Only checking accounts can issue cheques
        if (!sender->canCheque())
        {
            cout << "Savings account cannot perform cheque transactions.\n";
            return;
        }

        cout << "Enter receiver account number: ";
        cin >> toAccount;

        Account *receiver = findAccount(toAccount);

        if (receiver == nullptr)
        {
            cout << "Receiver account not found.\n";
            return;
        }

        if (fromAccount == toAccount)
        {
            cout << "Sender and receiver cannot be same.\n";
            return;
        }

        cout << "Enter date (YYYY-MM-DD): ";
        cin >> date;

        cout << "Enter cheque amount: ";
        cin >> amount;

        if (amount <= 0)
        {
            cout << "Invalid amount.\n";
            return;
        }

        if (!sender->withdraw(amount))
        {
            cout << "Insufficient balance.\n";
            return;
        }

        receiver->deposit(amount);

        // Sender transaction
        sender->addTransaction(
            Transaction(
                date,
                "Cheque Sent",
                amount,
                "Cheque transfer",
                toAccount));

        // Receiver transaction
        receiver->addTransaction(
            Transaction(
                date,
                "Cheque Received",
                amount,
                "Cheque transfer",
                fromAccount));

        cout << "Cheque transaction successful.\n";
    }

    void makeTransaction()
    {
        int choice;

        cout << "\n1. Cash Transaction";
        cout << "\n2. Cheque Transaction";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cashTransaction();
        }
        else if (choice == 2)
        {
            chequeTransaction();
        }
        else
        {
            cout << "Invalid choice.\n";
        }
    }
    void queryBalance()
    {
        int accountNumber;

        cout << "\nEnter account number: ";
        cin >> accountNumber;

        Account *account = findAccount(accountNumber);

        if (account == nullptr)
        {
            cout << "Account not found.\n";
            return;
        }

        account->display();
    }

    void displayAccounts()
    {
        if (accounts.empty())
        {
            cout << "\nNo accounts available.\n";
            return;
        }

        cout << "\n========== ALL ACCOUNTS ==========\n";

        for (auto account : accounts)
        {
            account->display();
            cout << "----------------------------------\n";
        }
    }

    // list transaction

    void listTransactions()
    {
        int accountNumber;
        cout << "\nEnter account number: ";
        cin >> accountNumber;

        Account *account = findAccount(accountNumber);

        if (account == nullptr)
        {
            cout << "Account not found\n";
        }
    }
};

int main(void)
{

    return 0;
}