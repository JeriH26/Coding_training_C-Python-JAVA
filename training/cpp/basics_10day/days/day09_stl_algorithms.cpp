#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

/*
Day 9: sort / find / lower_bound

Core idea:
- STL algorithms work on iterator ranges: [begin, end).
- sort changes the container order.
- find works on any range.
- lower_bound requires sorted data and returns the first element >= target.

Drills:
1. Sort descending with a lambda.
2. Use find to check whether 7 exists.
3. Use lower_bound to implement search_insert_position.
*/

int search_insert_position(const vector<int>& sorted_nums, int target) {
    auto it = lower_bound(sorted_nums.begin(), sorted_nums.end(), target);
    return static_cast<int>(it - sorted_nums.begin());
}

int main() {
    vector<int> nums = {5, 1, 9, 3};
    sort(nums.begin(), nums.end());
    assert((nums == vector<int>{1, 3, 5, 9}));

    auto found = find(nums.begin(), nums.end(), 5);
    assert(found != nums.end());
    assert(*found == 5);

    assert(search_insert_position(nums, 0) == 0);
    assert(search_insert_position(nums, 4) == 2);
    assert(search_insert_position(nums, 10) == 4);

    sort(nums.begin(), nums.end(), [](int a, int b) {
        return a > b;
    });
    assert((nums == vector<int>{9, 5, 3, 1}));

    cout << "Day 9 passed\n";
    return 0;
}

