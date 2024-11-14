//
// Created by Orange on 2024/11/14.
//
#include "code_0_header.h"

class Solution {
public:
  // 78. 子集
  vector<vector<int>> subsets1(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> cur;
    for (size_t size = 0; size <= nums.size(); ++size) {
      dfs(result, cur, nums, 0, size);
    }
    return result;
  }
  void dfs(vector<vector<int>>& result, vector<int>& cur, vector<int>& nums, const int index, const size_t size) {
    if (cur.size() == size) {
      result.emplace_back(cur);
      return;
    }
    for (int i = index; i < nums.size(); ++i) {
      cur.push_back(nums[i]);
      dfs(result, cur, nums, index + 1, size);
      cur.pop_back();
    }
  }

  vector<vector<int>> subsets2(vector<int>& nums) {
    vector<vector<int>> result = {{}};
    for (const int& num : nums) {
      auto copy = result;
      for (auto& v : copy) {
        v.emplace_back(num);
        result.emplace_back(v);
      }
    }
    return result;
  }

  vector<vector<int>> subsets2(vector<int>& nums) {


    return result;
  }


};