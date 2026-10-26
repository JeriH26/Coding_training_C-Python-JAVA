// P023 Min Stack Practice - two stacks
#include <cassert>
#include <stack>
#include <stdexcept>
using namespace std;

class MinStack {
private:
    stack<int> values;
    stack<int> mins;

public:
    void push(int val) {
        // TODO: Push val and update mins when val is a new minimum.
        values.push(val);
        if (mins.empty() || val <= mins.top()){
            mins.push(val);
        }
    }

    void pop() {
        // TODO: Remove the matching minimum when necessary, then remove the value.
        if (values.top() == mins.top()){
            mins.pop();
        }
        values.pop();
    }

    int top() const {
        // TODO: Return the top value.
        return values.top();
    }

    int getMin() const {
        // TODO: Return the current minimum.
        return mins.top();
    }
};

int main() {
    MinStack st;
    st.push(-2);
    st.push(0);
    st.push(-3);
    assert(st.getMin() == -3);
    st.pop();
    assert(st.top() == 0);
    assert(st.getMin() == -2);
}
