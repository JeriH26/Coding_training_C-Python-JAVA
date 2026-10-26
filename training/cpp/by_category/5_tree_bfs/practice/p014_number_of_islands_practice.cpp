// P014 Number of Islands Practice - DFS
#include <cassert>
#include <stdexcept>
#include <vector>
using namespace std;

void dfs(vector<vector<char>>& grid, int row, int col) {
    // TODO: Stop outside the grid or on water; mark land and visit four neighbors.
    int rows = grid.size();
    int cols = grid[0].size();

    if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] != '1'){
        return;
    }

    grid[row][col] = '0';
    dfs(grid, row + 1, col);
    dfs(grid, row - 1, col);
    dfs(grid, row, col + 1);
    dfs(grid, row, col - 1);
}

int solve(vector<vector<char>> grid) {
    // TODO: Count each unvisited land cell as a new island, then erase it with dfs.
    if (grid.empty() || grid[0].empty()){
        return 0;
    }

    int island = 0;
    for (int r = 0; r < grid.size(); r++){
        for (int c = 0; c < grid[0].size(); c++){
            if (grid[r][c] == '1'){
                island ++;
                dfs(grid, r, c);
            }
        }
    }

    return island;
}

int main() {
    assert(solve({{'1', '1', '0', '0', '0'},
                  {'1', '1', '0', '0', '0'},
                  {'0', '0', '1', '0', '0'},
                  {'0', '0', '0', '1', '1'}}) == 3);
    assert(solve({}) == 0);
}
