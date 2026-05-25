// P023 Min Stack
// Time: O(1) per operation, Space: O(n)

#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> values;
    stack<int> mins;

public:
    void push(int val) {
        values.push(val);
        if (mins.empty() || val <= mins.top()) {
            mins.push(val);
        }
    }

    void pop() {
        if (values.top() == mins.top()) {
            mins.pop();
        }
        values.pop();
    }

    int top() const {
        return values.top();
    }

    int getMin() const {
        return mins.top();
    }
};

int main() {
    MinStack st;
    st.push(-2);
    st.push(0);
    st.push(-3);
    cout << st.getMin() << endl;
    st.pop();
    cout << st.top() << endl;
    cout << st.getMin() << endl;
    return 0;
}

