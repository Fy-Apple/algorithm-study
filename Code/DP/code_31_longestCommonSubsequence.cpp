//
// Created by Orange on 2024/11/24.
//
#include "code_0_headers.h"
// 1143. 最长公共子序列
class Solution {
public:
  // dp
  int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
    for (int i = 1; i <= text1.size(); ++i) {
      for (int j = 1; j <= text2.size(); ++j) {
        dp[i][j] = text1[i - 1] == text2[j - 1] ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
    return dp.back().back();
  }

  // 空间压缩
  int longestCommonSubsequence2(string text1, string text2) {
    vector<int> dp(text2.size() + 1, 0);
    for (int i = 1; i <= text1.size(); ++i) {
      vector<int> lastdp = dp;
      for (int j = 1; j <= text2.size(); ++j) {
        dp[j] = text1[i - 1] == text2[j - 1] ? lastdp[j - 1] + 1 : max(dp[j], dp[j - 1]);
      }
    }
    return dp.back();
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  string text1 = "axxbxxcxxdxxc";
  string text2 = "abc";
  cout << s.longestCommonSubsequence(text1, text2);
  return 0;
}
