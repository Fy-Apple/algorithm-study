//
// Created by Orange on 2024/11/24.
//
#include "code_0_headers.h"

// 115. 不同的子序列
class Solution {
public:
  int numDistinct(string s, string t) {
    // dp[i][j]: 以0 ~ i-1 的s串和 以0 ~ j-1的t串，t串在s串中出现的个数
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
    for (int i = 0; i <= s.size(); ++i) dp[i][0] = 1;
    for (int i = 1; i <= s.size(); ++i) {
      for (int j = 1; j <= t.size();++j) {
        dp[i][j] = s[i - 1] == t[j - 1] ? dp[i - 1][j - 1] + dp[i - 1][j] : dp[i - 1][j];
      }
    }
    return dp.back().back();
  }

  // 空间压缩
  int numDistinct2(string s, string t) {
    vector<int> dp(t.size() + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= s.size(); ++i) {
      int prev = 1;
      for (int j = 1; j <= t.size();++j) {
        const int temp = dp[j];
        dp[j] = s[i - 1] == t[j - 1] ? prev + dp[j] : dp[j];
        prev = temp;
      }
    }
    return dp.back();
  }
};

/**
 *  a b c d
 *  a b d