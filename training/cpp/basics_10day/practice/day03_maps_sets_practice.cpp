#include <cassert>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

/*
Practice Day 3

Only edit the TODO function bodies.
Goal: unordered_map / map / set.
*/

unordered_map<string, int> count_words(const vector<string>& words) {
    // TODO: return word frequencies.
    unordered_map<string, int> freq;
    for (const string& word : words){
        ++freq[word];
    }
    
    return freq;
}

bool has_duplicate(const vector<int>& nums) {
    // TODO: return true if any number appears twice.
    set<int> seen;
    for (int x : nums){
        if (seen.count(x) > 0){
            return true;
        }
        seen.insert(x);
    }

    return false;
}

set<int> unique_sorted_values(const vector<int>& nums) {
    // TODO: return unique values in sorted order.
    set<int> result;
    for (int x : nums){
        result.insert(x);
    }
    return result;
}

int main() {
    auto freq = count_words({"cpp", "java", "cpp"});
    assert(freq["cpp"] == 2);
    assert(freq["java"] == 1);
    assert(has_duplicate({1, 2, 3, 2}));
    assert(!has_duplicate({1, 2, 3}));
    assert((unique_sorted_values({3, 1, 3, 2}) == set<int>{1, 2, 3}));

    cout << "Day 3 practice passed\n";
    return 0;
}
