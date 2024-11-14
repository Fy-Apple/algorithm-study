//
// Created by Orange on 2024/11/14.
//
#include <unordered_map>

#include "code_0_header.h"

class Solution {
public:
  // 491. 非递减子序列
  vector<vector<int>> findSubsequences2(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> cur;
    dfs(result, cur, nums, 0);
    return result;
  }
  // 递归
  void dfs(vector<vector<int>>& result, vector<int>& cur, vector<int>& nums, const int index) {
    if (cur.size() > 1) {
      result.emplace_back(cur);
    }
    if (index == nums.size()) return;
    unordered_map<int, bool> mp;
    for (int i = index; i < nums.size(); ++i) {
      if (!cur.empty() && nums[i] < cur.back()) continue;
      if (mp.count(nums[i])) continue;
      mp[nums[i]] = true;
      cur.emplace_back(nums[i]);
      dfs(result, cur, nums, i + 1);
      cur.pop_back();
    }
  }
  // 枚举
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> cur;
    for (int i = 0; i < nums.size() - 1; ++i) {
      vector<vector<int>> temp;
      for (int j = i + 1; j < nums.size(); ++j) {
        const auto len = temp.size();
        for (auto k = 0; k < len; ++k) {
          if (nums[j] >= temp[k].back()) {
            vector<int> vec = temp[k];
            vec.emplace_back(nums[j]);
            temp.emplace_back(vec);
          }
          if (nums[j] >= nums[i]) temp.push_back({nums[i], nums[j]});
        }
      }
      result.insert(result.end(), temp.begin(), temp.end());
    }
    return result;
  }
};