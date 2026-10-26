#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Practice Day 8

Only edit the TODO function body and lambda.
Goal: auto / const / lambda.
*/

int count_long_names(const vector<string>& names, int min_length) {
    // TODO: create a lambda that returns true when name.size() >= min_length.
    auto is_long = [min_length](const string& name) {
        if (name.size() >= static_cast<size_t>(min_length)){
            return true;
        } 
        return false;
    };

    int count = 0;
    for (const auto& name : names) {
        if (is_long(name)) {
            ++count;
        }
    }
    return count;
}

int main() {
    const vector<string> names = {"Ada", "Grace", "Bjarne"};
    assert(count_long_names(names, 5) == 2);
    assert(count_long_names(names, 6) == 1);

    cout << "Day 8 practice passed\n";
    return 0;
}
