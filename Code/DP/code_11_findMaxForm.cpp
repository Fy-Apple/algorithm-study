//
// Created by Orange on 2024/11/22.
//
#include "code_0_headers.h"

#include <iostream>
// 474. 一和零
class Solution {
public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    vector<pair<int, int>> nums;
    for (const auto& s : strs) {
      int c0 = 0, c1 = 0;
      for (const auto c : s) {
        if (c == '0') ++c0;
        else ++c1;
      }
      nums.emplace_back(c0, c1);
    }
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= strs.size(); ++i) {
      for (int j = m; j >= nums[i - 1].first; --j) {
        for (int k = n; k >= nums[i - 1].second; --k) {
          dp[j][k] = max(dp[j][k], dp[j - nums[i - 1].first][k - nums[i - 1].second] + 1);
        }
      }
    }
    return dp[m][n];
  }


  // dfs
  int findMaxForm2(vector<string>& strs, int m, int n) {
    vector<pair<int, int>> nums;
    for (const auto& s : strs) {
      int c0 = 0, c1 = 0;
      for (const auto c : s) {
        if (c == '0') ++c0;
        else ++c1;
      }
      nums.emplace_back(c0, c1);
    }
    int result;
    dfs(nums, m, n, result, 0, 0);
    return result;
  }

  void dfs(vector<pair<int, int>>& nums, const int m, const int n, int& result, const int curMax, const int cur) {
    if (m < 0 || n < 0) return;
    result = max(result, curMax);
    if (cur == nums.size()) {
      return;
    }
    dfs(nums, m - nums[cur].first, n - nums[cur].second, result, curMax + 1,cur + 1);
    dfs(nums, m, n, result, curMax,cur + 1);
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<string> test = {"10","0001","111001","1","0"};
  cout << s.findMaxForm(test, 5, 3);
  return 0;
}
