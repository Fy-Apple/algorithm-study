//
// Created by Orange on 2024/11/19.
//
#include "code_0_headers.h"

#include <algorithm>
// 452. 用最少数量的箭引爆气球
class Solution {
public:
  int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
      return a[1] < b[1];
    });
    long lastEnd = LONG_MIN;
    int result = 0, right = 0;
    for (const auto& point : points) {
      if (point[0] > lastEnd) {
        ++result;
        lastEnd = point[1];
        right = point[1];
      }else {
        if(point[0] > right) {
          ++result;
          right = point[1];
        }else {
          right = min(right, point[1]);
        }
      }
    }
    return result;
  }
  // 优化
  int findMinArrowShots2(vector<vector<int>>& points) {
    sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) -> bool {
                 return a[1] < b[1];
             });
    long lastEnd = LONG_MIN;
    int result = 0;
    for (const auto& pt : points) {
      if (pt[0] > lastEnd) {
        ++result;
        lastEnd = pt[1];
      }
    }
    return result;
  }
};

/**
 * 【1       6】
 *    【2              8】
 *                【7           12】
 *                        【10           16】
 */