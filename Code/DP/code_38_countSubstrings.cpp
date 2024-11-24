//
// Created by Orange on 2024/11/24.
//
#include "code_0_headers.h"

// 647. 回文子串
class Solution {
public:
  // dp
  int countSubstrings(string s) {
    const int size = static_cast<int>(s.size());
    vector<vector<bool>> dp(size, vector<bool>(size, false));
    int result = 0;
    for (int i = size - 1; i >= 0; --i) {
      for (int j = i; j < size; ++j) {
        if (s[i] == s[j]) {
          if (j == i || j == i + 1) {
            dp[i][j] = true;
          }else {
            dp[i][j] = dp[i + 1][j - 1];
          }
        }
        result += dp[i][j] ? 1 : 0;
      }
    }
    return result;
  }

  // 压缩空间
  int countSubstrings2(string s) {
    const int size = static_cast<int>(s.size());
    vector<bool> dp(size, false);
    int result = 0;
    for (int i = size - 1; i >= 0; --i) {
      for (int j = size - 1; j >= i; --j) {
        if (s[i] == s[j]) {
          if (j - i <= 2) {
            dp[j] = true;
          }else {
            dp[j] = dp[j - 1];
          }
        }else {
          dp[j] = false;
        }
        result += dp[j];
      }
    }
    return result;
  }

  // 中心扩展
  int countSubstrings3(string s) {
    int result = 0;
    for (int i = 0; i < s.size(); ++i) {
      int l = i,r = i;
      while (l >= 0 && r < s.size() && s[l--] == s[r++]) ++result;
      l = i,r = i + 1;
      while (l >= 0 && r < s.size() && s[l--] == s[r++]) ++result;
    }
    return result;
  }
};