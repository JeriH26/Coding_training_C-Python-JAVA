#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Day 8: auto / const / lambda

Core idea:
- auto lets the compiler infer the type.
- const communicates that a value should not change.
- lambda is a small inline function object.

Drills:
1. Use a lambda to count strings longer than 3 chars.
2. Change print_names so it cannot mutate the vector.
3. Explain why const references avoid copies.
*/

int count_if_custom(const vector<int>& nums, bool (*predicate)(int)) {
    int count = 0;
    for (int x : nums) {
        if (predicate(x)) {
            ++count;
        }
    }
    return count;
}

bool positive(int x) {
    return x > 0;
}

int main() {
    const vector<int> nums = {-2, 0, 3, 4};
    auto positives = count_if_custom(nums, positive);
    assert(positives == 2);

    auto is_long = [](const string& s) {
        return s.size() >= 5;
    };

    assert(is_long("hello"));
    assert(!is_long("cpp"));

    vector<string> names = {"Ada", "Grace", "Bjarne"};
    int long_names = 0;
    for (const auto& name : names) {
        if (is_long(name)) {
            ++long_names;
        }
    }
    assert(long_names == 2);

    cout << "Day 8 passed\n";
    return 0;
}

