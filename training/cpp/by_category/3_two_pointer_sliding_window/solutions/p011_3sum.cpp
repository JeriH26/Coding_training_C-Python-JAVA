// P011 3Sum
// Time: O(n^2), Space: O(1) excluding output

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> solve(vector<int> nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for (int i = 0; i < static_cast<int>(nums.size()); i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int left = i + 1;
        int right = static_cast<int>(nums.size()) - 1;
        while (left < right) {
            int total = nums[i] + nums[left] + nums[right];
            if (total == 0) {
                ans.push_back({nums[i], nums[left], nums[right]});
                left++;
                right--;
                while (left < right && nums[left] == nums[left - 1]) {
                    left++;
                }
                while (left < right && nums[right] == nums[right + 1]) {
                    right--;
                }
            } else if (total < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> ans = solve({-1, 0, 1, 2, -1, -4});
    for (const auto& triplet : ans) {
        cout << "[" << triplet[0] << "," << triplet[1] << "," << triplet[2] << "] ";
    }
    cout << endl;
    return 0;
}

