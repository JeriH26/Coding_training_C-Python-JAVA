// P028 Valid Palindrome
// Time: O(n), Space: O(1)

#include <cctype>
#include <iostream>
#include <string>
using namespace std;

bool solve(const string& s) {
    int left = 0;
    int right = static_cast<int>(s.size()) - 1;

    while (left < right) {
        while (left < right && !isalnum(static_cast<unsigned char>(s[left]))) {
            left++;
        }
        while (left < right && !isalnum(static_cast<unsigned char>(s[right]))) {
            right--;
        }

        char a = static_cast<char>(tolower(static_cast<unsigned char>(s[left])));
        char b = static_cast<char>(tolower(static_cast<unsigned char>(s[right])));
        if (a != b) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

int main() {
    cout << boolalpha << solve("A man, a plan, a canal: Panama") << endl;
    return 0;
}

