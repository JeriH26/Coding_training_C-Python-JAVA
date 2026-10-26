// P007 Binary Search Practice
#include <cassert>
#include <stdexcept>
#include <vector>
using namespace std;

int solve(const vector<int>& nums, int target) {
    // TODO: Search the inclusive [left, right] range and return index or -1.
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

    return -1;
}

int main() {
    assert(solve({-1, 0, 3, 5, 9, 12}, 9) == 4);
    assert(solve({-1, 0, 3, 5, 9, 12}, 2) == -1);
    assert(solve({}, 1) == -1);
}
