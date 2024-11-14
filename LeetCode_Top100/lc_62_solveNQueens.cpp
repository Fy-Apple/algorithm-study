//
// Created by apple on 2024/10/27.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
  vector<bool> colStatus;
  vector<bool> leftStatus;
  vector<bool> rightStatus;
public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    vector<string> cur(n, string(n, '.'));
    colStatus.resize(n, false);
    leftStatus.resize(2 * n - 1, false);
    rightStatus.resize(2 * n - 1, false);
    dfs(0, n, result, cur);
    return result;
  }
  void dfs(const int row, const int n, vector<vector<string>>& result, vector<string>& cur) {
    if (row == n) {
      result.emplace_back(cur);
      return;
    }

    for (int j = 0; j < n; ++j) {
      const int left = j - row + n - 1;
      const int right = j + row;

      if (!colStatus[j] && !leftStatus[left] && !rightStatus[right]) {
        cur[row][j] = 'Q';
        colStatus[j] = true;
        leftStatus[left] = true;
        rightStatus[right] = true;

        dfs(row + 1, n, result, cur);

        cur[row][j] = '.';
        colStatus[j] = false;
        leftStatus[left] = false;
        rightStatus[right] = false;
      }
    }
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  for (const auto& v : s.solveNQueens(4)) {
    for (const auto& s : v) {
      cout << "[" << s << "], " << endl;
    }
  }
  return 0;
}
