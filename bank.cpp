#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string name;
    double balance;

public:
    void createAccount() {
        cout << "Enter account number: ";
        cin >> accountNumber;
        cin.ignore();

        cout << "Enter account holder name: ";
        getline(cin, name);

        cout << "Enter initial balance: ";
        cin >> balance;

        cout << "\nAccount created successfully.\n";
    }

    void deposit() {
        double amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;

        if (amount > 0) {
            balance += amount;
            cout << "Amount deposited successfully.\n";
        } else {
            cout << "Invalid amount.\n";
        }
    }

    void withdraw() {
        double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;

        if (amount <= 0) {
            cout << "Invalid amount.\n";
        } else if (amount > balance) {
            cout << "Insufficient balance.\n";
        } else {
            balance -= amount;
            cout << "Amount withdrawn successfully.\n";
        }
    }

    void showBalance() {
        cout << "Current balance: " << balance << endl;
    }

    void displayAccount() {
        cout << "\n--- Account Details ---\n";
        cout << "Account Number : " << accountNumber << endl;
        cout << "Account Holder : " << name << endl;
        cout << "Balance        : " << balance << endl;
    }
};

int main() {
    BankAccount acc;
    int choice;
    bool accountCreated = false;

    do {
        cout << "\n===== BANKING SYSTEM MENU =====\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Display Account Details\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                acc.createAccount();
                accountCreated = true;
                break;

            case 2:
                if (accountCreated)
                    acc.deposit();
                else
                    cout << "Please create an account first.\n";
                break;

            case 3:
                if (accountCreated)
                    acc.withdraw();
                else
                    cout << "Please create an account first.\n";
                break;

            case 4:
                if (accountCreated)
                    acc.showBalance();
                else
                    cout << "Please create an account first.\n";
                break;

            case 5:
                if (accountCreated)
                    acc.displayAccount();
                else
                    cout << "Please create an account first.\n";
                break;

            case 6:
                cout << "Thank you for using the banking system.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 2);

    return 0;
}
