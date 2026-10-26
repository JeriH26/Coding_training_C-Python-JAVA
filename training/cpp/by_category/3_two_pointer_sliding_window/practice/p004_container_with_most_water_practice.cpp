// P004 Container With Most Water Practice - two pointers
#include <algorithm>
#include <cassert>
#include <stdexcept>
#include <vector>
using namespace std;

int solve(const vector<int>& height) {
    // TODO: Measure both ends, save the best area, move the shorter side.
    int left = 0;
    int right = static_cast<int>(height.size()) - 1;
    int best = 0;

    while (left < right){
        int area = min(height[left], height[right]) * (right - left);
        best = max(best, area);

        if (height[left] < height[right]){
            left ++;
        }else{
            right --;
        }
    }

    return best;
}

int main() {
    assert(solve({1, 8, 6, 2, 5, 4, 8, 3, 7}) == 49);
    assert(solve({1, 1}) == 1);
}
