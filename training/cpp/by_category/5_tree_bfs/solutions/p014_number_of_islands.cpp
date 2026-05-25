// P014 Number of Islands
// Time: O(rows * cols), Space: O(rows * cols) in recursion depth

#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>>& grid, int r, int c) {
    int rows = grid.size();
    int cols = grid[0].size();

    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] != '1') {
        return;
    }

    grid[r][c] = '0';
    dfs(grid, r + 1, c);
    dfs(grid, r - 1, c);
    dfs(grid, r, c + 1);
    dfs(grid, r, c - 1);
}

int solve(vector<vector<char>> grid) {
    if (grid.empty() || grid[0].empty()) {
        return 0;
    }

    int islands = 0;
    for (int r = 0; r < static_cast<int>(grid.size()); r++) {
        for (int c = 0; c < static_cast<int>(grid[0].size()); c++) {
            if (grid[r][c] == '1') {
                islands++;
                dfs(grid, r, c);
            }
        }
    }

    return islands;
}

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    cout << solve(grid) << endl;
    return 0;
}

