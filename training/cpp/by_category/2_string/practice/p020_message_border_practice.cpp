// P020 Message Border Practice
#include <cassert>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

vector<string> solve(const vector<string>& lines) {
    // TODO: Find maximum width, add top/bottom borders, and pad every line.
    int width = 0;
    for (const string& line: lines){
        width = max(width, static_cast<int>(line.size()));
    }

    string border(width + 4, '*');
    vector<string> ans;
    ans.push_back(border);

    for (const string& line: lines){
        string pad = line + string(width - line.size(), ' ');
        ans.push_back("* " + pad + " *");
    }
    
    ans.push_back(border);
    return ans;
}

int main() {
    assert(solve({"hello", "world"}) ==
           vector<string>({"*********", "* hello *", "* world *", "*********"}));
    assert(solve({"a", "abc"}) ==
           vector<string>({"*******", "* a   *", "* abc *", "*******"}));
}
