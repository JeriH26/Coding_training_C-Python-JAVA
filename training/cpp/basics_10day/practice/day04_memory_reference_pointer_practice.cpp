#include <cassert>
#include <iostream>

using namespace std;

/*
Practice Day 4

Only edit the TODO function bodies.
Goal: reference / pointer / address / dereference.
*/

void increment_by_reference(int& x) {
    // TODO: modify the original x.
    ++x;
}

void swap_by_reference(int& a, int& b) {
    // TODO: swap a and b.
    int temp = a;
    a = b;
    b = temp;
}

int read_or_zero(const int* p) {
    // TODO: if p is null return 0, otherwise return the value pointed to by p.
    if (p == nullptr){
        return 0;
    };
    return *p;
}

void increment_by_pointer(int* p) {
    // TODO: if p is not null, increment the value pointed to by p.
    if (p != nullptr){
        ++(*p);
    }
}

int main() {
    int a = 10;
    increment_by_reference(a);
    assert(a == 11);

    int x = 1;
    int y = 2;
    swap_by_reference(x, y);
    assert(x == 2);
    assert(y == 1);

    assert(read_or_zero(&x) == 2);
    assert(read_or_zero(nullptr) == 0);

    increment_by_pointer(&y);
    assert(y == 2);

    cout << "Day 4 practice passed\n";
    return 0;
}
