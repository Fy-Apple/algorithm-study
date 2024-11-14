//
// Created by Orange on 2024/11/14.
//
#include <algorithm>
#include <set>

#include "code_0_header.h"

class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    set<vector<int>> result;
    vector<int> cur;
    sort(nums.begin(), nums.end());
    dfs(result, cur, nums, 0);
    return {result.begin(), result.end()};
  }

  void dfs(set<vector<int>>& result, vector<int>& cur, vector<int>& nums, const int index) {
    if (index == nums.size()) {
      result.emplace(cur);
      return;
    }

    dfs(result, cur, nums, index + 1);
    cur.emplace_back(nums[index]);
    dfs(result, cur, nums, index + 1);
    cur.pop_back();
  }

  vector<vector<int>> subsetsWithDup2(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> cur;
    sort(nums.begin(), nums.end());
    dfs2(result, cur, nums, 0);
    return result;

  }

  void dfs2(vector<vector<int>>& result, vector<int>& cur, vector<int>& nums, const int index) {
    result.emplace_back(cur);
    for (int i = index; i < nums.size(); ++i) {
      if (i > index && nums[i] == nums[i - 1]) continue;
      cur.emplace_back(nums[i]);
      dfs2(result, cur, nums, index + 1);
      cur.pop_back();
    }
  }
};