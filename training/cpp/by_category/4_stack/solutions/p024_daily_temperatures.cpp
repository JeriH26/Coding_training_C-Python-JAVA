// P024 Daily Temperatures
// Time: O(n), Space: O(n)

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> solve(const vector<int>& temperatures) {
    vector<int> ans(temperatures.size(), 0);
    stack<int> st;

    for (int i = 0; i < static_cast<int>(temperatures.size()); i++) {
        while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
            int prev = st.top();
            st.pop();
            ans[prev] = i - prev;
        }
        st.push(i);
    }

    return ans;
}

int main() {
    vector<int> ans = solve({73, 74, 75, 71, 69, 72, 76, 73});
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}

