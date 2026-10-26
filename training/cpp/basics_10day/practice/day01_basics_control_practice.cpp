#include <cassert>
#include <iostream>

using namespace std;

/*
Practice Day 1

Only edit the TODO function bodies.
Goal: variable / function / scope / if / for / while.
*/

int add(int a, int b) {
    // TODO: return the sum of a and b.
    int sum = a + b;
    return sum;
}

bool is_odd(int x) {
    // TODO: return true if x is odd.
    return x % 2 != 0;
}

int sum_from_1_to_n(int n) {
    // TODO: use a loop to calculate 1 + 2 + ... + n.
    int total = 0;
    for (int i = 1; i <= n; ++i) {
        total += i;
    }
    return total;
}

int count_multiples_of_3(int n) {
    // TODO: count numbers from 1 to n that are divisible by 3.
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (i % 3 == 0){
            count ++;
        }
    };
    return count;
}

int main() {
    assert(add(2, 3) == 5);
    assert(is_odd(7));
    assert(!is_odd(8));
    assert(sum_from_1_to_n(5) == 15);
    assert(count_multiples_of_3(10) == 3);

    cout << "Day 1 practice passed\n";
    return 0;
}
