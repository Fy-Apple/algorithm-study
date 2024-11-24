//
// Created by Orange on 2024/11/23.
//
#include "code_0_headers.h"

#include <unordered_set>

// 139. 单词拆分
class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 1; i <= s.size(); ++i) {
      for (int j = 1; j <= wordDict.size(); ++j) {
        if (i >= wordDict[j - 1].size() && s.substr(i - wordDict[j - 1].size(), wordDict[j - 1].size()) == wordDict[j -1])
          dp[i] = dp[i] || dp[i -wordDict[j - 1].size()];
      }
    }
    return dp[s.size()];
  }
};