//
// Created by Orange on 2024/11/22.
//
#include "code_0_headers.h"

#include <iostream>
#include <numeric>

// 494. 目标和
class Solution {
public:
  int findTargetSumWays(vector<int>& nums, int target) {
    vector<vector<int>> dp(nums.size(), vector<int>(2001, 0));
    ++dp[0][-nums[0] + 1000];
    ++dp[0][nums[0] + 1000];
    for (int i = 1; i < nums.size(); ++i) {
      for (int j = 0; j <= 2000; ++j) {
        if (j - nums[i] >= 0) {
          dp[i][j] += dp[i - 1][j - nums[i]];
        }
        if (j + nums[i] <= 2000) {
          dp[i][j] += dp[i - 1][j + nums[i]];
        }
      }
    }
    return dp[nums.size() - 1][target + 1000];
  }

  // dp2
  int findTargetSumWays2(vector<int>& nums, int target) {
    // sum = (sum - neg) + neg;
    // target = (sum - neg) - neg = sum - 2 * neg
    // neg = (sum - target) / 2;
    int neg = accumulate(nums.begin(), nums.end(), 0) - target;
    if (neg & 1 || neg < 0) return 0;
    neg /= 2;
    vector<int> dp(neg + 1, 0);
    dp[0] = 1;
    for (const int& num : nums) {
      for (int j = neg; j >= num; --j) {
        // dp[i][j] = dp[i - 1][j] + dp[i - 1][j - num]
        dp[j] += dp[j - num];
      }
    }
    return dp[neg];
  }

  // dfs
  int findTargetSumWays3(vector<int>& nums, int target) {
    int result = 0;
    dfs(nums, target, result, 0);
    return result;
  }

  void dfs(vector<int>& nums, int target, int& result, const int cur) {
    if (cur == nums.size()) {
      if (target == 0) ++result;
      return;
    }
    dfs(nums, target - nums[cur], result, cur + 1);
    dfs(nums, target + nums[cur], result, cur + 1);
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> test = {1, 1, 1, 1, 1};
  cout << s.findTargetSumWays3(test, 3);
  return 0;
}
