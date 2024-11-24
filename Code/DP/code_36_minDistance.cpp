//
// Created by Orange on 2024/11/24.
//
#include "code_0_headers.h"

// 583. 两个字符串的删除操作
class Solution {
public:
  // dp 求子序列长度在做删操作
  int minDistance(string word1, string word2) {
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));

    for (int i = 1; i <= word1.size(); ++i) {
      for (int j = 1; j <= word2.size(); ++j) {
        dp[i][j] = word1[i - 1] == word2[j - 1] ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
    return static_cast<int>(word1.size() + word2.size()) - 2 * dp.back().back();
  }

  // 空间压缩
  int minDistance2(string word1, string word2) {
    vector<int> dp(word2.size() + 1, 0);
    for (int i = 1; i <= word1.size(); ++i) {
      int prev = 0;
      for (int j = 1; j <= word2.size(); ++j) {
        const int temp = dp[j];
        dp[j] = word1[i - 1] == word2[j - 1] ? prev + 1 : max(dp[j], dp[j - 1]);
        prev = temp;
      }
    }
    return static_cast<int>(word1.size() + word2.size()) - 2 * dp.back();
  }

  // 求最少操作数的dp
  int minDistance3(string word1, string word2) {
    vector<int> dp(word2.size() + 1, 0);
    for (int j = 0; j <= word2.size(); ++j) dp[j] = j;
    for (int i = 1; i <= word1.size(); ++i) {
      dp[0] = i;// dp[i][0]
      int prev = i - 1;// dp[i - 1][0]
      for (int j = 1; j <= word2.size(); ++j) {
        const int temp = dp[j];
        dp[j] = word1[i - 1] == word2[j - 1] ? prev : min(dp[j], dp[j - 1]) + 1;
        prev = temp;
      }
    }
    return dp.back();
  }
};
