//
// Created by Orange on 2024/11/14.
//
#include <unordered_map>

#include "code_0_header.h"
class Solution {
public:
  vector<string> letterCombinations(string digits) {
    vector<string> result;
    unordered_map<char, vector<char>> mp = {
      {'2', {'a', 'b', 'c'}},{'3', {'d', 'e', 'f'}},
      {'4', {'g', 'h', 'i'}},{'5', {'j', 'k', 'l'}},
      {'6', {'m', 'n', 'o'}},{'7', {'p', 'q', 'r', 's'}},
      {'8', {'t', 'u', 'v'}},{'9', {'w', 'x', 'y', 'z'}},
    };
    string cur;
    dfs(result, cur, mp, digits, 0);
    return result;
  }

  void dfs(vector<string>& result, string& cur, unordered_map<char, vector<char>>& mp, string& digits, const int index) {
    if (index == digits.size()) {
      if (!cur.empty()) result.emplace_back(cur);
      return;
    }
    if (!mp.count(digits[index])) return;
    for (const auto& c : mp[digits[index]]) {
      cur.push_back(c);
      dfs(result, cur, mp, digits, index + 1);
      cur.pop_back();
    }
  }
};