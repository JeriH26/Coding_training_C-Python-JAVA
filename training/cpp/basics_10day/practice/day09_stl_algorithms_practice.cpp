#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

/*
Practice Day 9

Only edit the TODO function bodies.
Goal: sort / find / lower_bound.
*/

vector<int> sorted_ascending(vector<int> nums) {
    // TODO: sort nums ascending and return it.
    sort(nums.begin(), nums.end());
    return nums;
}

bool contains_value(const vector<int>& nums, int target) {
    // TODO: use find.
    auto found = find(nums.begin(), nums.end(), target);
    if (found != nums.end()){
        return true;
    }
    return false;
}

int search_insert_position(const vector<int>& sorted_nums, int target) {
    // TODO: use lower_bound.
    auto it = lower_bound(sorted_nums.begin(), sorted_nums.end(), target);
    return (it - sorted_nums.begin());
}

vector<int> sorted_descending(vector<int> nums) {
    // TODO: sort nums descending with a lambda.
    sort(nums.begin(), nums.end(), [](int a, int b){
        return a > b;
    });
    return nums;
}

int main() {
    assert((sorted_ascending({5, 1, 3}) == vector<int>{1, 3, 5}));
    assert(contains_value({1, 3, 5}, 3));
    assert(!contains_value({1, 3, 5}, 9));
    assert(search_insert_position({1, 3, 5}, 4) == 2);
    assert(search_insert_position({1, 3, 5}, 0) == 0);
    assert((sorted_descending({5, 1, 3}) == vector<int>{5, 3, 1}));

    cout << "Day 9 practice passed\n";
    return 0;
}
