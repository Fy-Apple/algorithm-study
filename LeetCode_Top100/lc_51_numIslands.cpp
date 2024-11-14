//
// Created by apple on 2024/10/26.
//
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty() || grid[0].empty())
      return 0;
    int landsNum = 0;
    int row = grid.size();
    int col = grid[0].size();
    vector<bool> isVisited(row * col, false);
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if (grid[i][j] == '1') {
          ++landsNum;
          dfs(grid, i, j);
        }
      }
    }
    return landsNum;
  }

  void dfs(vector<vector<char>>& grid, int i, int j) {
    grid[i][j] = '0';
    if (j + 1 < grid[0].size() && grid[i][j + 1] == '1')
      dfs(grid, i, j + 1);
    if (i + 1 < grid.size() && grid[i + 1][j] == '1')
      dfs(grid, i + 1, j);
    if (j - 1 >= 0 && grid[i][j - 1] == '1')
      dfs(grid, i, j - 1);
    if (i - 1 >= 0 && grid[i - 1][j] == '1')
      dfs(grid, i - 1, j);
  }

};


int main(int argc, char *argv[]) {




}
