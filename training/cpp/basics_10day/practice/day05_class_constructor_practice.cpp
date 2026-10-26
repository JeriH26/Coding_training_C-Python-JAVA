#include <cassert>
#include <iostream>
#include <string>

using namespace std;

/*
Practice Day 5

Edit the TODO methods.
Goal: class / constructor / public / private.
*/

class BankAccount {
public:
    BankAccount(string owner, int initial_balance)
        : owner_(owner), balance_(initial_balance) {
        // TODO: if initial_balance is negative, store 0 instead.
        if (balance_ < 0){
            balance_ = 0;
        }
    }

    const string& owner() const {
        // TODO: return owner_.
        return owner_;
    }

    int balance() const {
        // TODO: return balance_.
        return balance_;
    }

    void deposit(int amount) {
        // TODO: add only positive amounts.
        if (amount > 0){
            balance_ += amount;
        }
    }

    bool withdraw(int amount) {
        // TODO: withdraw only when amount is positive and balance is enough.
        if (amount > 0 && balance_ >= amount){
            balance_ -= amount;
            return true;
        }
        return false;
    }

private:
    string owner_;
    int balance_;
};

int main() {
    BankAccount account("Junyi", 100);
    assert(account.owner() == "Junyi");
    assert(account.balance() == 100);

    account.deposit(50);
    assert(account.balance() == 150);

    assert(account.withdraw(40));
    assert(account.balance() == 110);
    assert(!account.withdraw(999));
    assert(account.balance() == 110);

    BankAccount invalid("Test", -5);
    assert(invalid.balance() == 0);

    cout << "Day 5 practice passed\n";
    return 0;
}
