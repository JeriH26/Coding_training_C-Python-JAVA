// P001 Two Sum Practice - hash map
#include <cassert>
#include <stdexcept>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> solve(const vector<int>& nums, int target) {
    // TODO: Store each number's index. For each number, look for target - number.
    unordered_map<int, int> seen;
    for (int i = 0; i < static_cast<int>(nums.size()); i++){
        int need = target - nums[i];
        if (seen.find(need) != seen.end()){
            return {seen[need], i};
        }

        seen[nums[i]] = i;
    }
    return {};
}

int main() {
    assert(solve({2, 7, 11, 15}, 9) == vector<int>({0, 1}));
    assert(solve({3, 2, 4}, 6) == vector<int>({1, 2}));
}
