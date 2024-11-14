//
// Created by Orange on 2024/11/14.
//
#include "code_0_header.h"
// 131.分割回文串
class Solution {
public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> cur;
    // dp计算s[i...j]是否为回文串
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    for (int i = static_cast<int>(s.size() - 1); i >=0; --i) {
      for (int j = static_cast<int>(s.size() - 1); j >= i; --j) {
        if (i == j || (i == j - 1 && s[i] == s[j])) dp[i][j] = true;
        else dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
      }
    }
    dfs(result, cur, s, 0, dp);
    return result;
  }

  void dfs(vector<vector<string>>& result, vector<string>& cur, string& s, const int index, vector<vector<bool>>& dp) {
    if (index == s.size()) {
      result.emplace_back(cur);
      return;
    }

    for (int len = 1; len <= s.size() - index; ++len) {
      if (dp[index][index + len - 1]) {
        cur.emplace_back(s.substr(index, len));
        dfs(result, cur, s, index + len, dp);
        cur.pop_back();
      }
    }
  }
};