// P005 Longest Substring Without Repeating Characters
// Time: O(n), Space: O(k)

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int solve(const string& s) {
    unordered_set<char> seen;
    int left = 0;
    int best = 0;

    for (int right = 0; right < static_cast<int>(s.size()); right++) {
        while (seen.find(s[right]) != seen.end()) {
            seen.erase(s[left]);
            left++;
        }

        seen.insert(s[right]);
        best = max(best, right - left + 1);
    }

    return best;
}

int main() {
    cout << solve("abcabcbb") << endl;
    cout << solve("bbbbb") << endl;
    return 0;
}

