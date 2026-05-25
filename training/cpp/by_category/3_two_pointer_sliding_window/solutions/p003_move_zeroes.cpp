// P003 Move Zeroes
// Time: O(n), Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int>& nums) {
    int write = 0;

    for (int read = 0; read < static_cast<int>(nums.size()); read++) {
        if (nums[read] != 0) {
            swap(nums[write], nums[read]);
            write++;
        }
    }
}

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};
    solve(nums);
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}

