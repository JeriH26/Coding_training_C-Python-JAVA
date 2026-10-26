#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/*
Day 3: unordered_map / map / set

Core idea:
- unordered_map gives fast average lookup without sorted order.
- map keeps keys sorted.
- set stores unique sorted values.

Drills:
1. Count word frequency in a vector<string>.
2. Return true if a vector has duplicates.
3. Print map keys and notice they are sorted.
*/

unordered_map<string, int> count_words(const vector<string>& words) {
    unordered_map<string, int> freq;
    for (const string& word : words) {
        ++freq[word];
    }
    return freq;
}

bool has_duplicate(const vector<int>& nums) {
    set<int> seen;
    for (int x : nums) {
        if (seen.count(x) > 0) {
            return true;
        }
        seen.insert(x);
    }
    return false;
}

int main() {
    vector<string> words = {"cpp", "java", "cpp", "python"};
    unordered_map<string, int> freq = count_words(words);

    assert(freq["cpp"] == 2);
    assert(freq["java"] == 1);
    assert(has_duplicate({1, 2, 3, 2}));
    assert(!has_duplicate({1, 2, 3}));

    map<string, int> ordered = {{"banana", 2}, {"apple", 5}, {"carrot", 1}};
    cout << "ordered keys:";
    for (const auto& entry : ordered) {
        cout << " " << entry.first;
    }
    cout << "\nDay 3 passed\n";
    return 0;
}

