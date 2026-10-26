// P008 Search Insert Position Practice - lower-bound binary search
#include <cassert>
#include <stdexcept>
#include <vector>
using namespace std;

int solve(const vector<int>& nums, int target) {
    // TODO: Return target's index, or the index where it should be inserted.
    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;

    while (left <= right){
        int mid = left + (right - left) / 2;

        if (nums[mid] == target){
            return mid;
        }
        if (nums[mid] < target){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }

    return left;
}

int main() {
    assert(solve({1, 3, 5, 6}, 5) == 2);
    assert(solve({1, 3, 5, 6}, 2) == 1);
    assert(solve({1, 3, 5, 6}, 7) == 4);
    assert(solve({}, 4) == 0);
}
