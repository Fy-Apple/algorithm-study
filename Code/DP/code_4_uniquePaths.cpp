//
// Created by Orange on 2024/11/20.
//
#include "code_0_headers.h"
// 62. 不同路径
class Solution {
public:
  //dp
  int uniquePaths(int m, int n) {
    vector<int> dp(n, 1);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i != 0 && j != 0)
          dp[j] = dp[j] + dp[j - 1];
      }
    }
    return dp[n - 1];
  }

  // dfs
  int uniquePath(int m, int n) {
    int result = 0;
    dfs(m, n, result, 0, 0);
    return result;
  }

  void dfs(int& m, int& n, int& result, const int row, const int col) {
    if (row == m - 1 && col == n - 1) {
      ++result;
      return;
    }
    if (col < n) dfs(m, n, result, row, col + 1);
    if (row < m) dfs(m, n, result, row + 1, col);
  }
};