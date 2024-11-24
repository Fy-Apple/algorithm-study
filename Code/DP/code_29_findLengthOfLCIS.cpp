//
// Created by Orange on 2024/11/24.
//
#include "code_0_headers.h"

// 674. 最长连续递增序列
class Solution {
public:
  int findLengthOfLCIS(vector<int>& nums) {
    int result = 1, len = 1;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) ++len;
      else len = 1;
      result = max(result, len);
    }
    return result;
  }
};