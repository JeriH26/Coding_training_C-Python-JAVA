// P024 Daily Temperatures Practice - monotonic stack
#include <cassert>
#include <stack>
#include <stdexcept>
#include <vector>
using namespace std;

vector<int> solve(const vector<int>& temperatures) {
    // TODO: Keep indexes whose warmer future day has not been found yet.
    vector<int> ans(temperatures.size(), 0);
    stack<int> st;

    for (int i = 0; i < static_cast<int>(temperatures.size()); i++){
        while (!st.empty() && temperatures[i] > temperatures[st.top()]){
            int prev = st.top();
            st.pop();
            ans[prev] = i - prev;
        }
        st.push(i);
    }

    return ans;
}

int main() {
    assert(solve({73, 74, 75, 71, 69, 72, 76, 73}) ==
           vector<int>({1, 1, 4, 2, 1, 1, 0, 0}));
    assert(solve({30, 40, 50, 60}) == vector<int>({1, 1, 1, 0}));
}
