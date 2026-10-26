// Merge Intervals Practice - sort and sweep
#include <algorithm>
#include <cassert>
#include <stdexcept>
#include <vector>
using namespace std;

vector<vector<int>> solve(vector<vector<int>> intervals) {
    // TODO: Sort intervals, then merge into the last interval in the result.
    if (intervals.empty()){
        return {};
    }

    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merge;
    merge.push_back(intervals[0]);

    for (int i = 1; i < static_cast<int>(intervals.size()); i++){
        if (intervals[i][0] <= merge.back()[1]){
            merge.back()[1] =  max(merge.back()[1], intervals[i][1]);
        }else{
            merge.push_back(intervals[i]);
        }
    }

    return merge;
}

int main() {
    assert(solve({{1, 3}, {2, 6}, {8, 10}, {15, 18}}) ==
           vector<vector<int>>({{1, 6}, {8, 10}, {15, 18}}));
    assert(solve({{1, 4}, {4, 5}}) == vector<vector<int>>({{1, 5}}));
    assert(solve({}).empty());
}
