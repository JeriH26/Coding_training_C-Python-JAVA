// P025 Evaluate Reverse Polish Notation Practice - stack
#include <cassert>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

int solve(const vector<string>& tokens) {
    // TODO: Push numbers. For an operator, pop b then a and push a operator b.
    stack<int> st;

    for (const string& token: tokens){
        if (token == "+" || token == "-" || token == "*" || token == "/"){
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();

            if (token == "+"){
                st.push(a + b);
            }else if(token == "-"){
                st.push(a - b);
            }else if(token == "*"){
                st.push(a * b);
            }else{
                st.push(a / b);
            }
        }else{
            st.push(stoi(token));
        }
    }

    return st.top();
}

int main() {
    assert(solve({"2", "1", "+", "3", "*"}) == 9);
    assert(solve({"4", "13", "5", "/", "+"}) == 6);
    assert(solve({"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}) == 22);
}
