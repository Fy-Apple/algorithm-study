//
// Created by Orange on 2024/11/24.
//
#include "code_0_headers.h"

// 496. 下一个更大元素 I
class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result(nums1.size());
    unordered_map<int, int> mp;
    stack<int> stk;
    for (int i = 0; i < nums2.size(); ++i) {
      mp[nums2[i]] = -1;
      while (!stk.empty() && nums2[i] > nums2[stk.top()]) {
        mp[nums2[stk.top()]] = nums2[i];
        stk.pop();
      }
      stk.push(i);
    }
    for (int i = 0; i < nums1.size(); ++i) {
      result[i] = mp[nums1[i]];
    }
    return result;
  }
};