//
// Created by Orange on 2024/11/24.
//
#include "code_0_headers.h"
// 718. 最长重复子数组
class Solution {
public:
  // 暴力
  int findLength(vector<int>& nums1, vector<int>& nums2) {
    int mxlen = 0;
    for (int i = 0; i < nums1.size(); ++i) {
      int indexI = i;
      int len = 0;
      for (int j = 0; j < nums2.size(); ++j) {
        if (nums2[j] != nums1[i]) continue;
        int indexJ = j;
        while (indexI < nums1.size() && indexJ < nums2.size() && nums1[indexI] == nums2[indexJ]) {
          ++indexI;
          ++indexJ;
          ++len;
        }
        mxlen = max(mxlen, len);
        len = 0;
        indexI = i;
      }
    }
    return mxlen;
  }
  // dp
  int findLength2(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
    int mxlen = 0;
    for(int i = static_cast<int>(nums1.size()) - 1; i >= 0;--i) {
      for (int j = static_cast<int>(nums2.size()) - 1; j >= 0; --j) {
        dp[i][j] = nums1[i] == nums2[j] ? dp[i + 1][j + 1] + 1 : 0;
        mxlen = max(mxlen, dp[i][j]);
      }
    }
    return mxlen;
  }
  // 压缩空间
  int findLength3(vector<int>& nums1, vector<int>& nums2) {
    vector<int> dp(nums2.size() + 1, 0);
    int mxlen = 0;
    for(int i = static_cast<int>(nums1.size()) - 1; i >= 0;--i) {
      for (int j = 0;j < nums2.size(); ++j) {
        dp[j] = nums1[i] == nums2[j] ? dp[j + 1] + 1 : 0;
        mxlen = max(mxlen, dp[j]);
      }
    }
    return mxlen;
  }
};