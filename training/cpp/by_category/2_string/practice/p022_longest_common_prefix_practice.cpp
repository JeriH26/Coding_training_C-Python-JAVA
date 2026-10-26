// P022 Longest Common Prefix Practice
#include <cassert>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

string solve(const vector<string>& strs) {
    // TODO: Start with the first string and shorten it until every string matches.
    if (strs.empty()){
        return "";
    }

    string prefix = strs[0];
    for (int i = 0; i < static_cast<int>(strs[i].size()); i++){
        while (strs[i].find(prefix) != 0){
            prefix.pop_back();
            if (prefix.empty()){
                return "";
            }
        }
    }

    return prefix;
}

int main() {
    assert(solve({"flower", "flow", "flight"}) == "fl");
    assert(solve({"dog", "racecar", "car"}) == "");
    assert(solve({}) == "");
}
