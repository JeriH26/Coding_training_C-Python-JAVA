#include <cassert>
#include <iostream>

using namespace std;

/*
Day 1: variable / function / scope / if / for / while

Core idea:
- A variable stores a value.
- A function receives input, does work, and may return output.
- Scope means where a name exists.
- Loops repeat while a condition is true.

Drills:
1. Change sum_from_1_to_n so it uses while instead of for.
2. Add a function is_odd.
3. Print numbers 1..20, but print only numbers divisible by 3.
*/

int add(int a, int b) {
    int result = a + b;
    return result;
}

bool is_even(int x) {
    return x % 2 == 0;
}

int sum_from_1_to_n(int n) {
    int total = 0;
    for (int i = 1; i <= n; ++i) {
        total += i;
    }
    return total;
}

int main() {
    int age = 25;
    int next_year = age + 1;

    assert(add(2, 3) == 5);
    assert(is_even(10));
    assert(!is_even(7));
    assert(sum_from_1_to_n(5) == 15);

    if (next_year >= 18) {
        cout << "adult\n";
    } else {
        cout << "minor\n";
    }

    cout << "sum 1..10 = " << sum_from_1_to_n(10) << "\n";
    cout << "Day 1 passed\n";
    return 0;
}

