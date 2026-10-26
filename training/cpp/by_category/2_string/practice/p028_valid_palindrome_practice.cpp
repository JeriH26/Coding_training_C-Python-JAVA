// P028 Valid Palindrome Practice - two pointers
#include <cassert>
#include <cctype>
#include <stdexcept>
#include <string>
using namespace std;

bool solve(const string& s) {
    // TODO: Move inward, skip non-alphanumeric chars, compare lowercase chars.
    int left = 0;
    int right = static_cast<int>(s.size()) - 1;
    while (left < right){
        while (left < right && !isalnum(static_cast<unsigned char>(s[left]))){
            left ++;
        }

        while (left < right && !isalnum(static_cast<unsigned char>(s[right]))){
            right --;
        }

        char a = static_cast<char>(tolower(static_cast<unsigned char>(s[left])));
        char b = static_cast<char>(tolower(static_cast<unsigned char>(s[right])));
        if (a != b){
            return false;
        }

        left ++;
        right --;
    }

    return true;
}

int main() {
    assert(solve("A man, a plan, a canal: Panama"));
    assert(!solve("race a car"));
    assert(solve(" "));
}
