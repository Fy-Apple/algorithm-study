//
// Created by Orange on 2024/11/14.
//
#include "code_0_header.h"

class Solution {
public:
  //216. 组合总和 III
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> result;
    vector<int> cur;
    dfs(result, cur, k, n, 0);
    return result;
  }

  void dfs(vector<vector<int>>& result, vector<int>& cur, int& k, int& n, const int sum) {
    if (cur.size() == k && sum == n) {
      result.emplace_back(cur);
      return;
    }
    for (int i = cur.empty() ? 1 : cur.back() + 1; i <= min(9, n - sum); ++i) {
      cur.push_back(i);
      dfs(result, cur, k, n, sum + i);
      cur.pop_back();
    }
  }
};