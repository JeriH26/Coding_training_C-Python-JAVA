// LeetCode 88: Merge Sorted Array
// Time: O(m + n), Extra space: O(1)

#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int write = m + n - 1;

        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[write] = nums1[i];
                --i;
            } else {
                nums1[write] = nums2[j];
                --j;
            }
            --write;
        }
    }
};

void check(vector<int> nums1, int m, vector<int> nums2, int n,
           const vector<int>& expected) {
    Solution solution;
    solution.merge(nums1, m, nums2, n);
    assert(nums1 == expected);
}

int main() {
    check({1, 2, 3, 0, 0, 0}, 3, {2, 5, 6}, 3, {1, 2, 2, 3, 5, 6});
    check({1}, 1, {}, 0, {1});
    check({0}, 0, {1}, 1, {1});
    check({2, 0}, 1, {1}, 1, {1, 2});
    cout << "C++ LeetCode 88 passed\n";
    return 0;
}
