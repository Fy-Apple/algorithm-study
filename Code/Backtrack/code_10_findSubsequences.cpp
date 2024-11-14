//
// Created by Orange on 2024/11/14.
//
#include <set>
#include <unordered_map>

#include "code_0_header.h"

// 491. 非递减子序列
class Solution {
public:
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
        vector<vector<int>> temp;

        // 遍历 nums
        for (int i = 0; i < nums.size(); ++i) {
            vector<vector<int>> newTemp;

            // 扩展已有的子序列
            for (auto& seq : temp) {
                if (nums[i] >= seq.back()) {
                    vector<int> newSeq = seq;
                    newSeq.push_back(nums[i]); // 将 nums[i] 加入当前子序列
                    newTemp.push_back(newSeq);
                }
            }

            // nums[i] 单独作为一个新的子序列起始
            newTemp.push_back({nums[i]});

            // 合并已有的 temp 和新生成的序列
            temp.insert(temp.end(), newTemp.begin(), newTemp.end());
        }

        // 去重：使用 set 保证子序列唯一
        set<vector<int>> uniqueSequences(temp.begin(), temp.end());

        // 过滤掉长度小于 2 的子序列
        for (auto& seq : uniqueSequences) {
            if (seq.size() >= 2) {
                result.push_back(seq);
            }
        }

        return result;
    }
};