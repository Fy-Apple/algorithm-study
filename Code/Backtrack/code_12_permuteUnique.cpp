//
// Created by Orange on 2024/11/14.
//
#include <set>

#include "code_0_header.h"
// 47. 全排列 II
class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    set<vector<int>> result;
    vector<int> cur;
    vector<bool> visited(nums.size(), false);
    dfs(result, cur, nums, visited);
    return {result.begin(), result.end()};
  }

  void dfs(set<vector<int>>& result, vector<int>& cur, vector<int>& nums,
           vector<bool>& visited) {
    if (cur.size() == nums.size()) {
      result.emplace(cur);
      return;
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (visited[i])
        continue;
      cur.emplace_back(nums[i]);
      visited[i] = true;
      dfs(result, cur, nums, visited);
      visited[i] = false;
      cur.pop_back();
    }
  }
};