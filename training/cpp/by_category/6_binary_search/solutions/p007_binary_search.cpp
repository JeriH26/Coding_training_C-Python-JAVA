// P007 Binary Search
// Time: O(log n), Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

int solve(const vector<int>& nums, int target) {
    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    cout << solve({-1, 0, 3, 5, 9, 12}, 9) << endl;
    cout << solve({-1, 0, 3, 5, 9, 12}, 2) << endl;
    return 0;
}

