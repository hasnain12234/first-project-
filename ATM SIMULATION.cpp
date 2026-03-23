//Muhammad Hasnain
#include <iostream>
#include <iomanip>
using namespace std;

// ===================== Account Class =====================
class Account {
private:
    double balance;

public:
    // Constructor
    Account(double initialBalance = 0.0) {
        if (initialBalance >= 0)
            balance = initialBalance;
        else
            balance = 0.0;
    }

    // Deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "? Deposit Successful!\n";
        } else {
            cout << "? Invalid deposit amount!\n";
        }
    }

    // Withdraw money
    bool withdraw(double amount) {
        if (amount <= 0) {
            cout << "? Invalid withdrawal amount!\n";
            return false;
        }
        if (amount > balance) {
            cout << "? Insufficient balance!\n";
            return false;
        }

        balance -= amount;
        cout << "? Withdrawal Successful!\n";
        return true;
    }

    // Check balance
    double getBalance() const {
        return balance;
    }
};

// ===================== ATM Controller Class =====================
class ATM {
private:
    Account userAccount;

public:
    ATM(double initialBalance) : userAccount(initialBalance) {}

    void displayMenu() {
        cout << "\n========== ATM MENU ==========\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
    }

    void run() {
        int choice;
        double amount;

        cout << fixed << setprecision(2);

        do {
            displayMenu();
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "?? Current Balance: $" 
                         << userAccount.getBalance() << endl;
                    break;

                case 2:
                    cout << "Enter amount to deposit: $";
                    cin >> amount;
                    userAccount.deposit(amount);
                    break;

                case 3:
                    cout << "Enter amount to withdraw: $";
                    cin >> amount;
                    userAccount.withdraw(amount);
                    break;

                case 4:
                    cout << "?? Thank you for using ATM!\n";
                    break;

                default:
                    cout << "? Invalid choice! Try again.\n";
            }

        } while (choice != 4);
    }
};

// ===================== Main Function =====================
int main() {
    double initialBalance;

    cout << "?? ===== WELCOME TO ATM SYSTEM ===== ??\n";
    cout << "Enter initial balance: $";
    cin >> initialBalance;

    ATM atm(initialBalance);
    atm.run();

    return 0;
}
