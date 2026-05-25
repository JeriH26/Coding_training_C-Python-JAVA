// P021 Contains Duplicate
// Time: O(n), Space: O(n)

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool solve(const vector<int>& nums) {
    unordered_set<int> seen;

    for (int num : nums) {
        if (seen.find(num) != seen.end()) {
            return true;
        }
        seen.insert(num);
    }

    return false;
}

int main() {
    cout << boolalpha;
    cout << solve({1, 2, 3, 1}) << endl;
    cout << solve({1, 2, 3, 4}) << endl;
    return 0;
}

