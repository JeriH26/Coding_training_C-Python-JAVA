// P005 Longest Substring Without Repeating Practice - sliding window
#include <cassert>
#include <stdexcept>
#include <string>
#include <unordered_set>
using namespace std;

int solve(const string& s) {
    // TODO: Expand right; while duplicated, remove from the left.
    unordered_set<char> seen;
    int left = 0;
    int best = 0;

    for (int right = 0; right < static_cast<int>(s.size()); right ++){
        if (seen.find(s[right]) != seen.end()){
            seen.erase(s[left]);
            left ++;
        }

        seen.insert(s[right]);
        best = max(best, right - left + 1);
    }

    return best;

}

int main() {
    assert(solve("abcabcbb") == 3);
    assert(solve("bbbbb") == 1);
    assert(solve("") == 0);
}
