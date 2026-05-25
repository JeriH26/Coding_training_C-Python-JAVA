// Merge Intervals
// Time: O(n log n), Space: O(n)

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> solve(vector<vector<int>> intervals) {
    if (intervals.empty()) {
        return {};
    }

    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    merged.push_back(intervals[0]);

    for (int i = 1; i < static_cast<int>(intervals.size()); i++) {
        if (intervals[i][0] <= merged.back()[1]) {
            merged.back()[1] = max(merged.back()[1], intervals[i][1]);
        } else {
            merged.push_back(intervals[i]);
        }
    }

    return merged;
}

int main() {
    vector<vector<int>> ans = solve({{1, 3}, {2, 6}, {8, 10}, {15, 18}});
    for (const auto& interval : ans) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;
    return 0;
}

