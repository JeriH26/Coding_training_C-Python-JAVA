// P022 Longest Common Prefix
// Time: O(n * m), Space: O(1)

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solve(const vector<string>& strs) {
    if (strs.empty()) {
        return "";
    }

    string prefix = strs[0];
    for (int i = 1; i < static_cast<int>(strs.size()); i++) {
        while (strs[i].find(prefix) != 0) {
            prefix.pop_back();
            if (prefix.empty()) {
                return "";
            }
        }
    }

    return prefix;
}

int main() {
    cout << solve({"flower", "flow", "flight"}) << endl;
    cout << solve({"dog", "racecar", "car"}) << endl;
    return 0;
}

