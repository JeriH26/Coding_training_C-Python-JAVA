// P006 Valid Parentheses
// Time: O(n), Space: O(n)

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

bool solve(const string& s) {
    unordered_map<char, char> closeToOpen = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };
    stack<char> st;

    for (char ch : s) {
        if (closeToOpen.find(ch) != closeToOpen.end()) {
            if (st.empty() || st.top() != closeToOpen[ch]) {
                return false;
            }
            st.pop();
        } else {
            st.push(ch);
        }
    }

    return st.empty();
}

int main() {
    cout << boolalpha;
    cout << solve("()[]{}") << endl;
    cout << solve("(]") << endl;
    return 0;
}

