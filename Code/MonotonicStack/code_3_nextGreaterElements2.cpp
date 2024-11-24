//
// Created by Orange on 2024/11/24.
//
#include "code_0_headers.h"

// 503. 下一个更大元素 II
class Solution {
public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    vector<int> result(nums.size(), -1);
    stack<int> stk;
    for (int i = 0; i < 2 * nums.size() - 1; ++i) {
      while (!stk.empty() && nums[i % nums.size()] > nums[stk.top()]) {
        result[stk.top()] = nums[i % nums.size()];
        stk.pop();
      }
      if (i < nums.size())
        stk.push(i);
    }
    return result;
  }
};


