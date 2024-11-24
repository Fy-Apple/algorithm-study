//
// Created by Orange on 2024/11/23.
//
#include "code_0_headers.h"


// 213. 打家劫舍 II
class Solution {
public:
  int rob(vector<int>& nums) {
    if (nums.size() <= 1) return nums[0];
    int byd = 0, yd = nums[0];
    for (int i = 2; i < nums.size(); ++i) {
      const int td = max(yd, byd + nums[i - 1]);
      byd = yd;
      yd = td;
    }
    const int f1 = yd;
    byd = 0, yd = nums[1];
    for (int i = 3; i <= nums.size(); ++i) {
      const int td = max(yd, byd + nums[i - 1]);
      byd = yd;
      yd = td;
    }
    return max(f1, yd);
  }
};