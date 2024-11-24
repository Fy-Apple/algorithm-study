//
// Created by Orange on 2024/11/22.
//
#include "code_0_headers.h"

#include <numeric>

// 416. 分割等和子集
class Solution {
public:
  bool canPartition(vector<int>& nums) {
    if (nums.size() <= 1) return false;
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum & 1) return false;
    sum /= 2;
    vector<int> dp(sum + 1, false);
    dp[0] = true;
    for (const auto& num : nums) {
      for (int j = sum; j >= num; --j) {
        dp[j] = dp[j] || dp[j - num];
      }
    }
    return dp[sum];
  }
};