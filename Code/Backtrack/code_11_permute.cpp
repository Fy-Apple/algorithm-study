//
// Created by Orange on 2024/11/14.
//
#include "code_0_header.h"

class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> cur;
    vector<bool> visited(nums.size(), false);
    dfs(result, cur, nums, visited);
    return result;
  }

  void dfs(vector<vector<int>>& result, vector<int>& cur, vector<int>& nums, vector<bool>& visited) {
    if (cur.size() == nums.size()) {
      result.emplace_back(cur);
      return;
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (visited[i]) continue;
      cur.emplace_back(nums[i]);
      visited[i] = true;
      dfs(result, cur, nums, visited);
      visited[i] = false;
      cur.pop_back();
    }
  }
};