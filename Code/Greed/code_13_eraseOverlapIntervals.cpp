//
// Created by Orange on 2024/11/19.
//
#include "code_0_headers.h"

#include <algorithm>
// 435. 无重叠区间
class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
      return a[1] < b[1];
    });
    int result = 0;
    long lastEnd = LONG_MIN;
    for (const auto& inter : intervals) {
      if (inter[0] <lastEnd) {
        ++result;
      }else {
        lastEnd = inter[1];
      }
    }
    return result;
  }
};