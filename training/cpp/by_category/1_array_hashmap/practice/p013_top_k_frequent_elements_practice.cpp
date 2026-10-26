// P013 Top K Frequent Elements Practice - size-k min-heap
#include <algorithm>
#include <cassert>
#include <functional>
#include <queue>
#include <stdexcept>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> solve(const vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int num : nums){
        freq[num] ++;
    }

    vector<pair<int, int>> pairs;
    for (const auto&[num, count] : pairs){
        pairs.push_back({num, count});
    }

    sort(pairs.begin(), pairs.end(), [](const auto&a, const auto&b){
        return a.second > b.second;
    });

    vector<int> ans;
    for (int i = 0; i < k & i < static_cast<int>(pairs.size()); i++){
        ans.push_back(pairs[i].first);
    }
    return ans;
    
}

vector<int> solveHeap(const vector<int>& nums, int k) {
    // TODO: Count frequencies, keep a min-heap of at most k {count, number} pairs.
    unordered_map<int, int> freq;
    for (int num : nums){
        freq[num] ++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> miniheap;
    for (const auto&[num, count] : freq){
        miniheap.push({count, num});
        if (static_cast<int>(miniheap.size()) > k){
            miniheap.pop();
        }
    }

    vector<int> ans;
    while (! miniheap.empty()){
        ans.push_back(miniheap.top().second);
        miniheap.pop();
    }

    return ans;
}

int main() {
    vector<int> answer = solveHeap({1, 1, 1, 2, 2, 3}, 2);
    sort(answer.begin(), answer.end());
    assert(answer == vector<int>({1, 2}));
    assert(solveHeap({1}, 1) == vector<int>({1}));
}
