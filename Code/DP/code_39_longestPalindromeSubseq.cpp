//
// Created by Orange on 2024/11/24.
//
#include "code_0_headers.h"

// 516. 最长回文子序列
class Solution {
public:
  // dp
  int longestPalindromeSubseq(string s) {
    const int size = static_cast<int>(s.size());
    vector<vector<int>> dp(size, vector<int>(s.size(), 0));
    for (int i = 0; i < size; ++i) dp[i][i] = 1;
    for (int i = size - 1; i >= 0; --i) {
      for (int j = i + 1; j < size; ++j) {
        if (s[i] == s[j]) {
          dp[i][j] = dp[i + 1][j - 1] + 2;
        } else {
          dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
      }
    }
    return dp.front().back();
  }

  // 状态压缩
  int longestPalindromeSubseq2(string s) {
    const int size = static_cast<int>(s.size());
    vector<int> dp(s.size(), 0);
    for (int i = size - 1; i >= 0; --i) {
      dp[i] = 1;
      int prev = 0;
      for (int j = i + 1; j < size; ++j) {
        const int temp = dp[j];
        if (s[i] == s[j]) {
          dp[j] = prev + 2;
        } else {
          dp[j] = max(dp[j], dp[j - 1]);
        }
        prev = temp;
      }
    }
    return dp.back();
  }
};