//
// Created by orange on 11/4/24.
//
#include <iostream>
#include <stack>
#include <vector>
using namespace std;


class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
    return dp[m - 1][n - 1];
  }
  int uniquePaths2(int m, int n) {
    int result = 0;
    dfs(0, 0, m - 1, n - 1, result);
    return result;
  }
  void dfs(const int i, const int j, const int m, const int n, int& result) {
    if (i == m && j == n) {
      ++result;
      return;
    }
    if (j < n) {
      dfs(i, j + 1, m, n, result);
    }
    if (i < m) {
      dfs(i + 1, j, m, n, result);
    }
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  cout << s.uniquePaths(23, 12);
}
