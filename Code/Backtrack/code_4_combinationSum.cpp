//
// Created by Orange on 2024/11/14.
//
#include <algorithm>
#include <unordered_map>

#include "code_0_header.h"

// 39. 组合总和
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
      cur.emplace_back(candidates[i]);
      dfs(result, cur, candidates, target - candidates[i], i);
      cur.pop_back();
    }
  }

  // dp版本
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    // 每一个元素存储能组合成目标值target的二维vector
    vector<vector<vector<int>>> dp(target + 1);
    dp[0] = {{}};// 因为需要拿出空数组来pushback，所以需要初始化一个空的vector

    // 遍历每一个候选数字
    for (const int& num : candidates) {
      // 对于每一个数字，需要填充遍历从当前数字一直到target的dp值，dp[j]与dp[j - num] 相关
      for (int j = num; j <= target; ++j) {
        // 将所有可能的组合加入dp[j]中
        for (const auto& vec: dp[j - num]) {
          vector<int> result = vec;
          result.emplace_back(num);
          dp[j].emplace_back(result);
        }
      }
    }
    return dp[target];
  }
};