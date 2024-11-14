//
// Created by Orange on 2024/11/14.
//
#include "code_0_header.h"

class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> cur;
    dfs(result, cur, n, k);
    return result;
  }

  void dfs(vector<vector<int>>& result, vector<int>& cur, int n, int k) {
    if (cur.size() == k) {
      result.emplace_back(cur);
      return;
    }
    for (int i = cur.empty() ? 1 : cur.back() + 1; i <= n; ++i) {
      cur.emplace_back(i);
      dfs(result, cur, n, k);
      cur.pop_back();
    }
  }
};