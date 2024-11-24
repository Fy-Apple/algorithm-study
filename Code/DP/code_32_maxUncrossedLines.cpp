//
// Created by Orange on 2024/11/24.
//
#include "code_0_headers.h"

// 1035. 不相交的线
// 和1143. 最长公共子序列 一模一样(code_31_longestCommonSubsequence.cpp)
class Solution {
public:
  // dp 和
  int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));

    for (int i = 1; i <= nums1.size(); ++i) {
      for (int j = 1; j <= nums2.size(); ++j) {
        dp[i][j] = nums1[i - 1] == nums2[j - 1] ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
    return dp.back().back();
  }

  int maxUncrossedLines2(vector<int>& nums1, vector<int>& nums2) {
    vector<int>& small = nums1;
    vector<int>& large = nums2;
    if (nums1.size() > nums2.size()) {
      small = nums2;
      large = nums1;
    }
    vector<int> dp(small.size() + 1, 0);
    for (int i = 1; i <= large.size(); ++i) {
      int prev = 0;
      for (int j = 1; j <= small.size(); ++j) {
        const int temp = dp[j];
        dp[j] = large[i - 1] == small[j - 1] ? prev + 1 : max(dp[j], dp[j - 1]);
        prev = temp;
      }
    }
    return dp.back();
  }
};