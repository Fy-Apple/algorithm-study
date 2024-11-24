//
// Created by Orange on 2024/11/24.
//
#include "code_0_headers.h"

// 72. 编辑距离
class Solution {
public:
  int minDistance(string word1, string word2) {
    // dp[i][j] 表示 0 ~ i-1 的word1和0 ~ j-1 的word2最少操作数
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
    for (int i = 0; i <= word1.size(); ++i) dp[i][0] = i;
    for (int j = 0; j <= word2.size(); ++j) dp[0][j] = j;

    for (int i = 1; i <= word1.size(); ++i) {
      for (int j = 1; j <= word2.size(); ++j) {
        dp[i][j] = word1[i - 1] == word2[j - 1] ? dp[i - 1][j - 1] : min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
      }
    }
    return dp.back().back();
  }

  // 压缩
  int minDistance2(string word1, string word2) {
    // dp[i][j] 表示 0 ~ i-1 的word1和0 ~ j-1 的word2最少操作数
    vector<int> dp(word2.size() + 1, 0);
    for (int j = 0; j <= word2.size(); ++j) dp[j] = j;

    for (int i = 1; i <= word1.size(); ++i) {
      dp[0] = i;
      int prev = i - 1;
      for (int j = 1; j <= word2.size(); ++j) {
        const int temp = dp[j];
        dp[j] = word1[i - 1] == word2[j - 1] ? prev : min(prev, min(dp[j], dp[j - 1])) + 1;
        prev = temp;
      }
    }
    return dp.back();
  }
};

