//
// Created by Orange on 2024/11/14.
//
#include <algorithm>

#include "code_0_header.h"

// 40.组合总和II
class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> cur;
    sort(candidates.begin(), candidates.end());
    dfs(result, cur, candidates, target, 0);
    return result;
  }

  void dfs(vector<vector<int>>& result, vector<int>& cur, vector<int>& candidates, const int target, const int start) {
    if (target == 0) {
      result.emplace_back(cur);
      return;
    }

    for (int i = start; i < candidates.size() && candidates[i] <= target; ++i) {
      if (i > start && candidates[i] == candidates[i - 1]) continue;
      cur.emplace_back(candidates[i]);
      dfs(result, cur, candidates, target - candidates[i], i + 1);
      cur.pop_back();
    }
  }
};