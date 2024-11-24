//
// Created by Orange on 2024/11/20.
//
#include "code_0_headers.h"
//343. 整数拆分
class Solution {
public:
  int integerBreak(int n) {
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
      int maxNum = i - 1;
      for (int j = 2; j < i; ++j) {
        maxNum = max(maxNum, max(j * (i - j), j * dp[i - j]));
      }
      dp[i] = maxNum;
    }
    return dp[n];
  }
};