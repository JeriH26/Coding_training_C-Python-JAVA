#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Day 2: vector / string / range-for

Core idea:
- vector<T> is a growable array.
- string is text with useful operations like size, push_back, substr.
- range-for is the clean way to visit every element.

Drills:
1. Write max_value(vector<int> nums).
2. Write count_vowels(string s).
3. Reverse a vector without using reverse().
*/

int sum_vector(const vector<int>& nums) {
    int total = 0;
    for (int x : nums) {
        total += x;
    }
    return total;
}

string first_three(const string& s) {
    if (s.size() <= 3) {
        return s;
    }
    return s.substr(0, 3);
}

int count_char(const string& s, char target) {
    int count = 0;
    for (char c : s) {
        if (c == target) {
            ++count;
        }
    }
    return count;
}

int main() {
    vector<int> nums = {2, 4, 6};
    nums.push_back(8);

    assert(nums.size() == 4);
    assert(nums[0] == 2);
    assert(sum_vector(nums) == 20);
    assert(first_three("developer") == "dev");
    assert(count_char("banana", 'a') == 3);

    cout << "nums:";
    for (int x : nums) {
        cout << " " << x;
    }
    cout << "\nDay 2 passed\n";
    return 0;
}

