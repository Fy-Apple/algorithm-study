//
// Created by Orange on 2024/11/20.
//
#include "code_0_headers.h"
//70. 爬楼梯
class Solution {
public:
  int climbStairs(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
  }
};