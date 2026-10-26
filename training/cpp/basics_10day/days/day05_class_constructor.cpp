#include <cassert>
#include <iostream>
#include <string>

using namespace std;

/*
Day 5: class / constructor / public / private

Core idea:
- A class bundles data and behavior.
- private data protects object state.
- A constructor creates a valid object.

Drills:
1. Add withdraw(int amount), rejecting negative balances.
2. Add a get_owner() method.
3. Create two accounts and transfer money.
*/

class BankAccount {
public:
    BankAccount(string owner, int initial_balance)
        : owner_(owner), balance_(initial_balance) {
        if (balance_ < 0) {
            balance_ = 0;
        }
    }

    void deposit(int amount) {
        if (amount > 0) {
            balance_ += amount;
        }
    }

    int balance() const {
        return balance_;
    }

private:
    string owner_;
    int balance_;
};

int main() {
    BankAccount account("Junyi", 100);
    account.deposit(50);
    account.deposit(-10);

    assert(account.balance() == 150);

    BankAccount invalid("Test", -99);
    assert(invalid.balance() == 0);

    cout << "Day 5 passed\n";
    return 0;
}

