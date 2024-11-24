//
// Created by Orange on 2024/11/24.
//
#include "code_0_headers.h"

// 53. 最大子数组和
class Solution {
public:
  // 动态规划法
  int maxSubArray(vector<int>& nums) {
    int prev = -1;
    int result = nums[0];
    for (const int& num : nums) {
      prev = max(prev + num, num);
      result = max(result, prev);
    }
    return result;
  }

  // 分治法
  struct info{
    int left, right, sum, mid;
    info() : left(0), right(0), sum(0), mid(0) {}
    info(int left, int right, int sum, int mid) : left(left), right(right), sum(sum), mid(mid) {}
  };
  int maxSubArray2(vector<int>& nums) {
    return dfs(nums, 0, static_cast<int>(nums.size()) - 1).mid;
  }

  info dfs(vector<int>& nums, const int l, const int r) {
    if (l == r) return {nums[l], nums[l], nums[l], nums[l]};
    const info left = dfs(nums, l,  l + (r - l) / 2);
    const info right = dfs(nums, l + (r - l) / 2 + 1,  r);
    const int li = max(left.left, left.sum + right.left);
    const int ri = max(right.right, right.sum + left.right);
    const int si = left.sum + right.sum;
    return {li, ri, si, max(max(li, ri), max(max(left.mid, right.mid), left.right + right.left))};
  }
};