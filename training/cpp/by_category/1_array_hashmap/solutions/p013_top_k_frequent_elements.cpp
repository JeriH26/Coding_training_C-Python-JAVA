// P013 Top K Frequent Elements
// Sort version: O(n log n), heap version: O(n log k)

#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> solve(const vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }

    vector<pair<int, int>> pairs;
    for (const auto& [num, count] : freq) {
        pairs.push_back({num, count});
    }

    sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    vector<int> ans;
    for (int i = 0; i < k && i < static_cast<int>(pairs.size()); i++) {
        ans.push_back(pairs[i].first);
    }
    return ans;
}

vector<int> solveHeap(const vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    for (const auto& [num, count] : freq) {
        minHeap.push({count, num});
        if (static_cast<int>(minHeap.size()) > k) {
            minHeap.pop();
        }
    }

    vector<int> ans;
    while (!minHeap.empty()) {
        ans.push_back(minHeap.top().second);
        minHeap.pop();
    }
    return ans;
}

void printVector(const vector<int>& nums) {
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    printVector(solve(nums, 2));
    printVector(solveHeap(nums, 2));
    return 0;
}

