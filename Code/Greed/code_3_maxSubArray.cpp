//
// Created by Orange on 2024/11/19.
//
#include "code_0_headers.h"
//53. 最大子数组和
class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int presum = -1, result = INT_MIN;
    for (const auto& num : nums) {
      if (presum >= 0) {
        presum += num;
      }else {
        presum = num;
      }
      result = max(result, presum);
    }
    return result;
  }

  struct info {
    int left;
    int right;
    int mid;
    int sum;
    info(int l, int r, int m, int s) : left(l), right(r), mid(m), sum(s) {}
  };
  // 分治
  int maxSubArray2(vector<int>& nums) {
    const info result = dfs(nums, 0, static_cast<int>(nums.size()) - 1);
    return max(max(result.left, result.right), max(result.mid, result.sum));
  }

  info dfs(vector<int>& nums, int l, int r) {
    if (l == r) {
      return {nums[l], nums[l], nums[l],nums[l]};
    }
    const info infol = dfs(nums, l, l + (r - l) / 2);
    const info infor = dfs(nums,l + (r - l) / 2 + 1, r);
    return {max(infol.sum + infor.left, infol.left),
      max(infor.sum + infol.right, infor.right),
      max(max(infol.mid, infor.mid), infol.right + infor.left),
      infol.sum + infor.sum};
  }
};