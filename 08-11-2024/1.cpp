/*
Scenario 1: Banking System
In a banking system, you have two classes: BankAccount and Transaction. The BankAccount class stores a user's account information, including private data members like balance and accountNumber. The Transaction class handles various types of transactions, such as deposits, withdrawals, and transfers.

Question:
How would you design these two classes so that the Transaction class can access the private data members of the BankAccount class to perform operations directly on them? Demonstrate this using the concept of friend classes in C++.
*/

#include <iostream>
#include <string>
using namespace std;

class bankaccount {
private:
    double balance;
    string accountnumber;

public:
    bankaccount() : balance(0.0), accountnumber(" ") {}

    void input() {
        cout << "Enter balance: ";
        cin >> this->balance;
        cin.ignore();
        cout << "Enter account number: ";
        getline(cin, this->accountnumber);
    }

    void display() const {
        cout << "Balance: $" << this->balance << endl;
        cout << "Account number: " << this->accountnumber << endl;
    }

    const string& getAccountNumber() const { return accountnumber; }

    ~bankaccount() {}

    friend class transaction;
};

class transaction {
public:
    void deposit(bankaccount& acc) {
        double amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        if (amount > 0) {
            acc.balance += amount;
            cout << "Deposited $" << amount << " successfully." << endl;
        }
        else {
            cout << "Invalid amount." << endl;
        }
    }

    void withdraw(bankaccount& acc) {
        double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        if (amount > 0 && amount <= acc.balance) {
            acc.balance -= amount;
            cout << "Withdrew $" << amount << " successfully." << endl;
        }
        else {
            cout << "Insufficient balance or invalid amount." << endl;
        }
    }

    void transfer(bankaccount& fromAcc, bankaccount& toAcc) {
        double amount;
        cout << "Enter amount to transfer: ";
        cin >> amount;
        if (amount > 0 && amount <= fromAcc.balance) {
            fromAcc.balance -= amount;
            toAcc.balance += amount;
            cout << "Transferred $" << amount << " successfully." << endl;
        }
        else {
            cout << "Insufficient balance or invalid amount." << endl;
        }
    }
};

int main() {
    bankaccount a1, a2;
    transaction t;
    int choice;
    string accountNumberInput;

    cout << "Enter details for Account 1:" << endl;
    a1.input();
    cout << endl << "Enter details for Account 2:" << endl;
    a2.input();

    cout << endl << "--- Account Details ---" << endl;
    cout << "Account 1: ";
    a1.display();
    cout << "Account 2: ";
    a2.display();

    cout << endl << "1. Deposit" << endl << "2. Withdraw" << endl << "3. Transfer" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();

    switch (choice) {
    case 1: 
        cout << "Enter the account number to deposit into: ";
        getline(cin, accountNumberInput);
        if (accountNumberInput == a1.getAccountNumber()) {
            t.deposit(a1);
        }
        else if (accountNumberInput == a2.getAccountNumber()) {
            t.deposit(a2);
        }
        else {
            cout << "Invalid account number." << endl;
        }
        break;

    case 2:
        cout << "Enter the account number to withdraw from: ";
        getline(cin, accountNumberInput);
        if (accountNumberInput == a1.getAccountNumber()) {
            t.withdraw(a1);
        }
        else if (accountNumberInput == a2.getAccountNumber()) {
            t.withdraw(a2);
        }
        else {
            cout << "Invalid account number." << endl;
        }
        break;

    case 3: 
        cout << "Enter the account number to transfer from: ";
        getline(cin, accountNumberInput);
        if (accountNumberInput == a1.getAccountNumber()) {
            t.transfer(a1, a2);
        }
        else if (accountNumberInput == a2.getAccountNumber()) {
            t.transfer(a2, a1);
        }
        else {
            cout << "Invalid account number." << endl;
        }
        break;

    default:
        cout << "Invalid choice." << endl;
    }

    cout << endl << "--- Updated Account Details ---" << endl;
    cout << "Account 1: ";
    a1.display();
    cout << "Account 2: ";
    a2.display();
    system("pause");
    return 0;
}
