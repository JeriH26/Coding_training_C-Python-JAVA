// P006 Valid Parentheses Practice - stack
#include <cassert>
#include <stack>
#include <stdexcept>
#include <string>
#include <unordered_map>
using namespace std;

bool solve(const string& s) {
    // TODO: Push opening brackets; match and pop when a closing bracket appears.
    unordered_map<char, char> closeTOpen = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    stack<char> st;

    for (char ch: s){
        if (closeTOpen.find(ch) != closeTOpen.end()){
            if (st.empty() || st.top() != closeTOpen[ch]){
                return false;
            }
            st.pop();
        }else{
            st.push(ch);
        }
    }

    return st.empty();
}

int main() {
    assert(solve("()[]{}"));
    assert(!solve("(]"));
    assert(!solve("([)]"));
    assert(solve(""));
}
