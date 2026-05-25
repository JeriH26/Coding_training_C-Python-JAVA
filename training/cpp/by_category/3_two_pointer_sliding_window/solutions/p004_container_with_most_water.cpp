// P004 Container With Most Water
// Time: O(n), Space: O(1)

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int solve(const vector<int>& height) {
    int left = 0;
    int right = static_cast<int>(height.size()) - 1;
    int best = 0;

    while (left < right) {
        int area = min(height[left], height[right]) * (right - left);
        best = max(best, area);

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return best;
}

int main() {
    cout << solve({1, 8, 6, 2, 5, 4, 8, 3, 7}) << endl;
    return 0;
}

