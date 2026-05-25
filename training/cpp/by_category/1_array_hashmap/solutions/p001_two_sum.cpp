// P001 Two Sum
// Time: O(n), Space: O(n)

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> solve(const vector<int>& nums, int target) {
    unordered_map<int, int> seen;

    for (int i = 0; i < static_cast<int>(nums.size()); i++) {
        int need = target - nums[i];
        if (seen.find(need) != seen.end()) {
            return {seen[need], i};
        }
        seen[nums[i]] = i;
    }

    return {};
}

int main() {
    vector<int> ans = solve({2, 7, 11, 15}, 9);
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}

