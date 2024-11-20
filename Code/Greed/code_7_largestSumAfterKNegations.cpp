//
// Created by Orange on 2024/11/19.
//
#include <algorithm>

#include "code_0_headers.h"

// 1005. K 次取反后最大化的数组和
class Solution {
public:
  int largestSumAfterKNegations(vector<int>& nums, int k) {
    if (nums.empty()) return 0;
    sort(nums.begin(), nums.end());
    int sum = 0;
    long minNum = LONG_MAX;
    for (auto& num : nums) {
      if (num < 0 && k > 0) {
        num = -num;
        --k;
      }
      if (minNum == LONG_MAX) minNum = num;
      else minNum = min(static_cast<int>(minNum), num);
      sum += num;
    }
    if (k % 2 == 0) return sum;
    return sum - 2 * minNum;
  }
};