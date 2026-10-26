// P011 3Sum Practice - sort plus two pointers
#include <algorithm>
#include <cassert>
#include <stdexcept>
#include <vector>
using namespace std;

vector<vector<int>> solve(vector<int> nums) {
    // TODO: Sort, fix one number, then search the rest with left/right pointers.
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for (int i = 0; i < static_cast<int>(nums.size()); i++){
        if (i > 0 && nums[i] == nums[i - 1]){
            continue;
        }

        int left = i + 1;
        int right = static_cast<int>(nums.size()) - 1;
        while (left < right){
            int total = nums[i] + nums[left] + nums[right];
            if (total == 0){
                ans.push_back({nums[i], nums[left], nums[right]});
                left ++;
                right --;
                while (left < right && nums[left] == nums[left - 1]){
                    left ++;
                }
                while (left < right && nums[right] == nums[right + 1]){
                    right --;
                }
            }else if(total < 0){
                left ++;
            }else{
                right --;
            }
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> answer = solve({-1, 0, 1, 2, -1, -4});
    sort(answer.begin(), answer.end());
    assert(answer == vector<vector<int>>({{-1, -1, 2}, {-1, 0, 1}}));
    assert(solve({0, 1, 1}).empty());
    assert(solve({0, 0, 0}) == vector<vector<int>>({{0, 0, 0}}));
}
