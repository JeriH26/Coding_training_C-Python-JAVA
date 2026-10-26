// P002 Valid Anagram Practice - frequency map
#include <cassert>
#include <stdexcept>
#include <string>
#include <unordered_map>
using namespace std;

bool solve(const string& s, const string& t) {
    // TODO: Count characters in s, then remove the counts using t.
    if (s.size() != t.size()){
        return false;
    }

    unordered_map<char, int> freq;
    for (char ch : s){
        freq[ch] ++;
    }

    for (char ch : t){
        if(freq.find(ch) == freq.end()){
            return false;
        }
        freq[ch] --;

        if (freq[ch] < 0){
            return false;
        }
    }

    return true;
}

int main() {
    assert(solve("anagram", "nagaram"));
    assert(!solve("rat", "car"));
    assert(!solve("a", "ab"));
}
