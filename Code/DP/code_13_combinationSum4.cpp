//
// Created by Orange on 2024/11/22.
//
#include "code_0_headers.h"
// 377. 组合总和 Ⅳ
class Solution {
public:
  int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= target; ++i) {
      for (int j = 1; j <= nums.size(); ++j) {
        if (i >= nums[j - 1]) dp[i] += dp[i - nums[j - 1]];
      }
    }
    return dp[target];
  }
};