#include <cassert>
#include <iostream>

using namespace std;

/*
Practice Day 6

Edit the TODO constructor/destructor.
Goal: object lifetime / destructor / RAII.
*/

class ScopeCounter {
public:
    explicit ScopeCounter(int& live_count)
        : live_count_(live_count) {
        // TODO: increase live_count_ when object is created.
        ++live_count_;
    }

    ~ScopeCounter() {
        // TODO: decrease live_count_ when object is destroyed.
        --live_count_;
    }

private:
    int& live_count_;
};

int main() {
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

    cout << "Day 6 practice passed\n";
    return 0;
}

