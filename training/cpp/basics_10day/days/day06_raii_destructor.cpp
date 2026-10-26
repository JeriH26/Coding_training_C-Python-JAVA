#include <cassert>
#include <iostream>
#include <string>

using namespace std;

/*
Day 6: RAII / object lifetime / destructor

Core idea:
- RAII means Resource Acquisition Is Initialization.
- Constructor acquires or starts something.
- Destructor releases or finishes it automatically when scope ends.

Drills:
1. Add a ResourceTimer that prints start/end messages.
2. Add a counter proving destructor runs when a scope ends.
3. Explain why RAII handles early returns and exceptions well.
*/

class ScopeCounter {
public:
    explicit ScopeCounter(int& live_count)
        : live_count_(live_count) {
        ++live_count_;
    }

    ~ScopeCounter() {
        --live_count_;
    }

private:
    int& live_count_;
};

int create_and_destroy() {
    int live = 0;
    {
        ScopeCounter first(live);
        assert(live == 1);
        {
            ScopeCounter second(live);
            assert(live == 2);
        }
        assert(live == 1);
    }
    assert(live == 0);
    return live;
}

int main() {
    assert(create_and_destroy() == 0);
    cout << "Day 6 passed\n";
    return 0;
}

