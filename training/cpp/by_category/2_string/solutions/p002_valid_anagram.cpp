// P002 Valid Anagram
// Time: O(n), Space: O(1) for fixed alphabet

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool solve(const string& s, const string& t) {
    if (s.size() != t.size()) {
        return false;
    }

    unordered_map<char, int> freq;
    for (char ch : s) {
        freq[ch]++;
    }

    for (char ch : t) {
        if (freq.find(ch) == freq.end()) {
            return false;
        }
        freq[ch]--;
        if (freq[ch] < 0) {
            return false;
        }
    }

    return true;
}

int main() {
    cout << boolalpha;
    cout << solve("anagram", "nagaram") << endl;
    cout << solve("rat", "car") << endl;
    return 0;
}

