//
// Created by orange on 11/4/24.
//
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < grid.size(); ++i) dp[i][0] = dp[i - 1][0] + grid[i][0];
    for (int j = 1; j < grid[0].size(); ++j) dp[0][j] = dp[0][j - 1] + grid[0][j];
    for (int i = 1; i < grid.size(); ++i) {
      for (int j = 1; j < grid[0].size(); ++j) {
        dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
      }
    }
    return dp[grid.size() - 1][grid[0].size() - 1];
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<vector<int>> test = {{1,3,1},{1,5,1},{4,2,1}};
  cout << s.minPathSum(test) << endl;
  return 0;
}
