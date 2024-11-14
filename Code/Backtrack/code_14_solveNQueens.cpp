//
// Created by orange on 11/14/24.
//
#include "code_0_header.h"
class Solution {
private:
  vector<bool> col;
  vector<bool> left;
  vector<bool> right;
public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    col.resize(n, false);
    left.resize(2 * n - 1, false);
    right.resize(2 * n - 1, false);
    vector<string> cur(n, string(n, '.'));
    dfs(result, cur, 0);
    return result;
  }

  void dfs(vector<vector<string>>& result, vector<string>& cur, const int row) {
    if (row == cur.size()) {
      result.emplace_back(cur);
      return;
    }
    for (int j = 0; j < cur.size(); ++j) {
      if (!col[j] && !left[row - j + cur.size() - 1] && !right[row + j]) {
        col[j] = left[row - j + cur.size() - 1] = right[row + j] = true;
        cur[row][j] = 'Q';
        dfs(result, cur, row + 1);
        cur[row][j] = '.';
        col[j] = left[row - j + cur.size() - 1] = right[row + j] = false;
      }
    }
  }
};