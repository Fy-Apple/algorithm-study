//
// Created by Orange on 2024/11/14.
//
#include "code_0_header.h"
// 93.复原IP地址
class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> result;
    if (s.size() < 4 || s.size() > 13) return result;
    vector<int> cur;
    dfs(result, cur, s, 0);
    return result;
  }


  void dfs(vector<string>& result, vector<int>& cur, string& s, const int index) {
    if (cur.size() == 4 && index == s.size()) {
      result.emplace_back(to_string(cur[0]) + '.'
        + to_string(cur[1]) + '.'
        + to_string(cur[2]) + '.'
        + to_string(cur[3]));
    }

    for (int len = 1; len <= 3 && index + len <= s.size(); ++len) {
      if (len > 1 && s[index] == '0') break;
      const int addr = stoi(s.substr(index, len));
      if (s.substr(index, len) <= "255") {
        cur.emplace_back(addr);
        dfs(result, cur, s, index + len);
        cur.pop_back();
      }
    }
  }
};