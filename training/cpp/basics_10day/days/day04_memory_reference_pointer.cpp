#include <cassert>
#include <iostream>
#include <memory>

using namespace std;

/*
Day 4: stack / heap / pointer / reference

Core idea:
- Stack objects live until their scope ends.
- Heap objects live until their owner releases them.
- A reference is another name for an existing object.
- A pointer stores an address and can be null.

Drills:
1. Write a function that swaps two ints by reference.
2. Write a function that safely reads from an int pointer.
3. Explain why unique_ptr is safer than raw new/delete.
*/

void increment_by_value(int x) {
    ++x;
    (void)x;
}

void increment_by_reference(int& x) {
    ++x;
}

int read_or_zero(const int* p) {
    if (p == nullptr) {
        return 0;
    }
    return *p;
}

int main() {
    int stack_value = 10;
    increment_by_value(stack_value);
    assert(stack_value == 10);

    increment_by_reference(stack_value);
    assert(stack_value == 11);

    int* raw_pointer = &stack_value;
    assert(*raw_pointer == 11);
    assert(read_or_zero(raw_pointer) == 11);
    assert(read_or_zero(nullptr) == 0);

    auto heap_value = make_unique<int>(42);
    assert(*heap_value == 42);

    cout << "stack address = " << &stack_value << "\n";
    cout << "Day 4 passed\n";
    return 0;
}
