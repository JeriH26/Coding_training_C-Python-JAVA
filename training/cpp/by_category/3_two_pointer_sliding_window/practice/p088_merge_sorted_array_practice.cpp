// LeetCode 88 practice: merge nums2 into nums1 in place.
// Do not call sort(). Use three indexes and fill nums1 from right to left.

#include <cassert>
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int write = m + n - 1;

        // TODO: While nums2 still has unmerged values:
        // 1. Compare nums1[i] and nums2[j].
        // 2. Write the larger value into nums1[write].
        // 3. Move the indexes that were used.
        while (j >= 0){
            if (i >= 0 && nums1[i] > nums2[j]){
                nums1[write] = nums1[i];
                --i;
            }else{
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
    cout << "C++ LeetCode 88 practice passed\n";
    return 0;
}
