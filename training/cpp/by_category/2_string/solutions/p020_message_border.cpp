// P020 Message Border
// Build a border around message lines.

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<string> solve(const vector<string>& lines) {
    int width = 0;
    for (const string& line : lines) {
        width = max(width, static_cast<int>(line.size()));
    }

    string border(width + 4, '*');
    vector<string> ans;
    ans.push_back(border);

    for (const string& line : lines) {
        string padded = line + string(width - line.size(), ' ');
        ans.push_back("* " + padded + " *");
    }

    ans.push_back(border);
    return ans;
}

int main() {
    vector<string> ans = solve({"hello", "world"});
    for (const string& line : ans) {
        cout << line << endl;
    }
    return 0;
}
