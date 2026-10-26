// P021 Contains Duplicate Practice - hash set
#include <cassert>
#include <stdexcept>
#include <unordered_set>
#include <vector>
using namespace std;

bool solve(const vector<int>& nums) {
    // TODO: Return true when a number is already in the set.
    unordered_set<int> seen;
    for (int num: nums){
        if (seen.find(num) != seen.end()){
            return true;
        }
        seen.insert(num);
    }

    return false;
}

int main() {
    assert(solve({1, 2, 3, 1}));
    assert(!solve({1, 2, 3, 4}));
    assert(!solve({}));
}
