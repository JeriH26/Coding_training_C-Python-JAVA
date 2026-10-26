#include <cassert>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
Practice Day 2

Only edit the TODO function bodies.
Goal: vector / string / range-for.
*/

int sum_vector(const vector<int>& nums) {
    // TODO: return the sum of all numbers.
    int total = 0;

    for (int x : nums){
        total += x;
    }
    return total;
}

int max_value(const vector<int>& nums) {
    // TODO: return the largest value. Assume nums is not empty.
    int max_num = nums[0];

    for (int x : nums){
        if (max_num < x){
            max_num = x;
        }
    }
    return max_num;
}

int count_vowels(const string& s) {
    // TODO: count a/e/i/o/u. Lowercase only is enough.
    //vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    //int count = 0;
//
    //for (int i = 0; i < s.size(); ++i){
    //    if (find(vowels.begin(), vowels.end(), s[i] != vowels.end())) {
    //        count ++;
    //    }
    //}

    int count = 0;

    for (char c : s) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            count ++;
        }
    }
    return count;
}

vector<int> reversed_copy(const vector<int>& nums) {
    // TODO: return a reversed copy without modifying nums.
    vector<int> result;
    //for (int i = static_cast<int>(nums.size())-1; i >= 0; i--) {
    //    result.push_back(nums[i]);
    //}
    for (int x : nums){
        result.insert(result.begin(), x);
    }
    return result;
}

int main() {
    assert(sum_vector({2, 4, 6}) == 12);
    assert(max_value({3, 9, 1, 5}) == 9);
    assert(count_vowels("banana") == 3);
    assert((reversed_copy({1, 2, 3}) == vector<int>{3, 2, 1}));

    cout << "Day 2 practice passed\n";
    return 0;
}
