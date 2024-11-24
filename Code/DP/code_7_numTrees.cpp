//
// Created by Orange on 2024/11/22.
//
#include "code_0_headers.h"

class Solution {
public:
  int numTrees(int n) {
    vector<int> dp(n + 1, 0);
    if (n <= 2) return n;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i) {
      for (int j = 0; j < i; ++j) {
        dp[i] += dp[j] * dp[i - j - 1];
      }
    }
    return dp[n];
  }
};