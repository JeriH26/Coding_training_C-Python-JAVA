// P002 Valid Anagram Practice - frequency map
#include <cassert>
#include <stdexcept>
#include <string>
#include <unordered_map>
using namespace std;

bool solve(const string& s, const string& t) {
    // TODO: Count characters in s, then remove the counts using t.
    (void)s; (void)t;
    throw logic_error("TODO: implement Valid Anagram");
}

int main() {
    assert(solve("anagram", "nagaram"));
    assert(!solve("rat", "car"));
    assert(solve("", ""));
}
