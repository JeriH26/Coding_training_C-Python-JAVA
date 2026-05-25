// P025 Evaluate Reverse Polish Notation
// Time: O(n), Space: O(n)

#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int solve(const vector<string>& tokens) {
    stack<int> st;

    for (const string& token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();

            if (token == "+") {
                st.push(a + b);
            } else if (token == "-") {
                st.push(a - b);
            } else if (token == "*") {
                st.push(a * b);
            } else {
                st.push(a / b);
            }
        } else {
            st.push(stoi(token));
        }
    }

    return st.top();
}

int main() {
    cout << solve({"2", "1", "+", "3", "*"}) << endl;
    cout << solve({"4", "13", "5", "/", "+"}) << endl;
    return 0;
}

