// P008 Search Insert Position
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

    return left;
}

int main() {
    cout << solve({1, 3, 5, 6}, 5) << endl;
    cout << solve({1, 3, 5, 6}, 2) << endl;
    cout << solve({1, 3, 5, 6}, 7) << endl;
    return 0;
}

