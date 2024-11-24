//
// Created by Orange on 2024/11/23.
//
#include "code_0_headers.h"
// 198. 打家劫舍
class Solution {
public:
  int rob(vector<int>& nums) {
    int byd = 0, yd = nums[0];
    for (int i = 2; i <= nums.size(); ++i) {
      const int td = max(yd, byd + nums[i - 1]);
      byd = yd;
      yd = td;
    }
    return yd;
  }
};