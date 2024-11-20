//
// Created by Orange on 2024/11/20.
//
#include "code_0_headers.h"

#include <algorithm>
// 56. 合并区间
class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.size() <= 1) return intervals;
    sort(intervals.begin(), intervals.end(),[](const vector<int>& a, const vector<int>& b) -> bool {
      return a[0] < b[0];
    });
    vector<vector<int>> result;
    int l = intervals[0][0], r = intervals[0][1];
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i][0] > r) {
        result.push_back({l, r});
        l = intervals[i][0];
        r = intervals[i][1];
      }else {
        r = max(intervals[i][1], r);
      }
    }
    result.push_back({l, r});
    return result;
  }
};