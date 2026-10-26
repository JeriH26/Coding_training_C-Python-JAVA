// P003 Move Zeroes Practice - in-place two pointers
#include <cassert>
#include <stdexcept>
#include <vector>
using namespace std;

void solve(vector<int>& nums) {
    // TODO: Move each nonzero value to the next write position without changing order.
    int write = 0;

    for (int read = 0; read < static_cast<int>(nums.size()); read++){
        if (nums[read] != 0){
            swap(nums[write], nums[read]);
            write ++;
        }
    }
}

int main() {
    vector<int> first = {0, 1, 0, 3, 12};
    solve(first);
    assert(first == vector<int>({1, 3, 12, 0, 0}));

    vector<int> second = {0};
    solve(second);
    assert(second == vector<int>({0}));
}
