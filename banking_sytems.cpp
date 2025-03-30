#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Account {
private:
    string accountNumber;
    string ownerName;
    double balance;

public:
    Account(string accNum, string owner, double initialBalance)
        : accountNumber(accNum), ownerName(owner), balance(initialBalance) {}

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited " << amount << ". New balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn " << amount << ". New balance: " << balance << endl;
        }
    }

    void displayDetails() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Owner: " << ownerName << endl;
        cout << "Balance: " << balance << endl;
    }
};

class BankingSystem {
private:
    vector<Account> accounts;

public:
    void createAccount(string accNum, string owner, double initialBalance) {
        accounts.push_back(Account(accNum, owner, initialBalance));
        cout << "Account created successfully for " << owner << endl;
    }

    void displayAllAccounts() {
        for (auto& account : accounts) {
            account.displayDetails();
            cout << "------------------------" << endl;
        }
    }
};

int main() {
    BankingSystem bank;
    bank.createAccount("12345", "John Doe", 1000.0);
    bank.createAccount("67890", "Jane Smith", 500.0);

    cout << "All accounts:\n";
    bank.displayAllAccounts();

    return 0;
}